
#include "Instructions/cInstruction.h"

int main()
{
	cInstruction instr_jmp;
	instr_jmp.load( "JMP" );
	instr_jmp.construct();
	
	cInstruction instr_jsr;
	instr_jsr.load( "JSR" );
	instr_jsr.construct();

	return 0;
}