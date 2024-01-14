#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <algorithm>
#include <Windows.h>

typedef unsigned char byte;

struct instr
{
	std::string name = "";
	std::vector<byte> modes;
};

struct opcode
{
	std::string name = "";
	std::string mode = "";
	std::string fullname = "";
	byte code;
};

#define MODES_COUNT 8

std::string modes[ MODES_COUNT ] = {
	" impl", // 0b00000000 0x00
	" imm" , // 0b00000001 0x01
	" ac"  , // 0b00000010 0x02
	" rel" , // 0b00000011 0x03
	" abs" , // 0b00000100 0x04
	" abx" , // 0b00000101 0x05
	" aby" , // 0b00000110 0x06
	" ind" , // 0b00000111 0x07
};

std::string modes_full[ MODES_COUNT ] = {
	"Implied",
	"Immediate",
	"AC",
	"Relative",
	"Absolute",
	"Absolute,X",
	"Absolute,Y",
	"Indirect",
};

int modes_sizes[ MODES_COUNT ] = {
	1, // Implied
	2, // Immediate
	1, // AC
	2, // Relative
	3, // Absolute
	3, // Absolute,X
	3, // Absolute,Y
	3, // Indirect
};


#define impl 0b00000000
#define imm  0b00000001
#define ac   0b00000010
#define rel  0b00000011
#define abs  0b00000100
#define abx  0b00000101
#define aby  0b00000110
#define ind  0b00000111

std::vector<instr> instructions = {
	{ "JMP", { abs, ind } },
	{ "JSR", { abs } },
	{ "RTS", { impl } },
	{ "LDA", { imm,abs,abx,aby } },
	{ "LDX", { imm,abs,aby,ac } },
	{ "LDY", { imm,abs,abx,ac } },
	{ "ADD", { imm,abs,abx,aby } },
	{ "SUB", { imm,abs,abx,aby } },
	{ "DIV", { imm,abs,abx,aby } },
	{ "MUL", { imm,abs,abx,aby } },
	{ "PSH", { imm,abs,abx,aby,ac } },
	{ "POP", { impl } },
	{ "SHL", { abs, abx, aby, ac } },
	{ "SHR", { abs, abx, aby, ac } },
	{ "AND", { abs, abx, aby, ac } },
	{ "OR",  { abs, abx, aby, ac } },
	{ "NOR", { abs, abx, aby, ac } },
	{ "XOR", { abs, abx, aby, ac } },
	{ "STA", { abs, abx, aby } },
	{ "STX", { abs, abx, aby } },
	{ "STY", { abs, abx, aby } },
	{ "CLM", { impl } },
	{ "NOP", { impl } },
};

opcode set[ 16 ][ 16 ];

byte getOpcode( byte _instr, byte _mode )
{
	byte instr = _instr << 3;
	byte code = ( instr + _mode );
	return code;
}

int main()
{
	for ( int i = 0; i < instructions.size(); i++ )
	{
		for ( int m = 0; m < instructions[i].modes.size(); m++ )
		{
			byte mode = instructions[ i ].modes[ m ];
			
			byte code = getOpcode( i, mode );

			byte low = code & 0x0F;
			byte high = code >> 4;

			if ( set[ high ][ low ].name != "" )
			{
				std::string oldname = set[ high ][ low ].name;
				std::string newname = ( instructions[ i ].name + modes[ mode ] );
				printf( "overriden 0x%hx from %-7s to %-7s\n", code, oldname.c_str(), newname.c_str() );
			}

			set[ high ][ low ].code = code;
			set[ high ][ low ].fullname = instructions[ i ].name + modes[ mode ];
			set[ high ][ low ].name = instructions[ i ].name;
			set[ high ][ low ].mode = modes[ mode ];
		}
	}

	CreateDirectory( L"out", NULL );

	FILE* fptr;
	fptr = fopen( "out/instruction-set-docs.md", "w" );
	fprintf( fptr, "|        | x0       | x1       | x2       | x3       | x4       | x5       | x6       | x7       | x8       | x9       | xA       | xB       | xC       | xD       | xE       | xF       |\n" );
	fprintf( fptr, "| :----: | :------: | :------: | :------: | :------: | :------: | :------: | :------: | :------: | :------: | :------: | :------: | :------: | :------: | :------: | :------: | :------: |\n" );

	for ( int y = 0; y < 16; y++ )
	{
		fprintf( fptr, "| **%hXx** |", y );
		for ( int x = 0; x < 16; x++ )
		{
			std::string& fullname = set[ y ][ x ].fullname;
			std::string& name = set[ y ][ x ].name;
			std::string name_lowercase = name; 
			std::transform( name_lowercase.begin(), name_lowercase.end(), name_lowercase.begin(), std::tolower );

			fprintf( fptr, " [%-9s](#%s)|", fullname.c_str(), name_lowercase.c_str() );
		}
		fprintf( fptr, "\n" );
	}

	fprintf( fptr, "\n\n\n" );

	for ( int i = 0; i < instructions.size(); i++ )
	{
		fprintf( fptr, "> ### %-3s\n", instructions[ i ].name.c_str() );
		fprintf( fptr, "> \n" );

		fprintf( fptr, "> | Mode | Opcode | Bytes \n" );
		fprintf( fptr, "> | :--- | :----: | :---: \n" );

		for ( int m = 0; m < instructions[i].modes.size(); m++ )
		{
			int mode = instructions[ i ].modes[ m ];

			fprintf( fptr, "> | **%s** | 0x%02hX | %i \n", modes_full[ mode ].c_str(), getOpcode( i, mode ), modes_sizes[ mode ] );
		}

		fprintf( fptr, "\n\n" );
	}

	fclose( fptr );

	return 0;
}