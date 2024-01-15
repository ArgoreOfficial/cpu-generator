
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
	cBytecodeSequence seq_jsr;
	seq_jsr.push( "[$SP] <- PCL" );
	seq_jsr.push( "[SP] <- [SP] + 1" );
	seq_jsr.push( "[$SP] <- PCH" );
	seq_jsr.push( "[SP] <- [SP] + 1" );
	seq_jsr.push( "PCH <- [$PC+1]" );
	seq_jsr.push( "PCL <- [$PC+2]" );
	seq_jsr.construct( "JSR" );

	cBytecodeSequence seq_jmp;
	seq_jmp.push( "[PCH] <- [PC+1]" );
	seq_jmp.push( "[PCL] <- [PC+2]" );
	seq_jmp.construct( "JMP" );

	return 0;
}