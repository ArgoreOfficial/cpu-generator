
#include "Instructions/Bytecode.h"
#include <stdio.h>
#include <format>
#include <string>
#include <vector>
#include <sstream>

/* Example code, Jump to Subroutine */
/*

push PCL         // Program Counter High (0xH.) pushed onto Stack
push PCH 		 // Program Counter Low  (0x.L) pushed onto Stack

PCH = [$PC+1]      // Value at Program Counter + 1 copied into Program Counter High
PCL = [$PC+2]      // Value at Program Counter + 1 copied into Program Counter Low
[0] = 5


*/

/* Translated to Luau */
/*

function JSR()
	stack[SP+1] = PCL
	SP += 1
	stack[SP+1] = PCH
	SP += 1

	PCH = RAM[PC+1]
	PCL = RAM[PC+2]

	PC = bit32.lshift( PCH, 4 ) + PCL -- not included in function, done afterwars
end

*/

int main()
{
	cBytecodeSequence seq;
	/*
	seq.push( "PCH <- [$PC+1]" );
	seq.push( "PCL <- [ $PC + 2 ]" );
	seq.push( "5 <- [$0]" );
	seq.push( "4 -> [$1]" );
	*/

	seq.push( "PCL <- M" );
	seq.push( "PC <- [SP]" );
	seq.push( "PC -> [$SP+1]" );


	seq.construct();

	return 0;
}