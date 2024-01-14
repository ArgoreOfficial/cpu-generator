# P65255 CPU Architecture

[Full instruction set here](instruction-set.md)

## REGISTERS

| Name  | Size* | Description
| :---  | :---: | :----------
| AC    | 8     | Accumulator
| PC    | 16    | Program Counter
| CIR   | 8     | Current Instruction Register
| MAR   | 8     | Memory Address Register (hidden)
| MDR   | 8     | Memory Data Register (hidden)
| X     | 8     | X Register
| Y     | 8     | Y Register
| SP    | 8     | Stack Pointer

<sup>*Size in bits</sup>

<!-- TODO: Add stack -->

**aaaaabbb**
where a is base instruction and b is mode

## Addressing Modes
| Mode | Size* | xxxxxBBB | Description
| :--- | :---: | :------: | :---------- 
| impl | 0     | xxxxx000 | operand is implied, 
| imm  | 1     | xxxxx001 | operand is next byte
| ac   | 0     | xxxxx010 | operand is AC register
| rel  | 1     | xxxxx011 | operand is PC, incremented by signed byte (-128 ~ 127)
| abs  | 2     | xxxxx100 | operand is address
| abx  | 3     | xxxxx101 | operand is address, incremented by X
| aby  | 3     | xxxxx110 | operand is address, incremented by Y
| ind  | 2     | xxxxx111 | operand is address specified in the next 2 bytes*

<sup>*as in: 'JMP 1000', where the address 1000 has the values 80 00 .., the PC will jump to address 8000</sup>

| Instruction | BBBBBxxx | Modes           | Description |
| :---------: | :------: | -----           | -----------
| JMP         | 00000xxx | abs,ind         | Jump
| JSR         | 00001xxx | abs             | Jump to subroutine
| RTS         | 00010xxx | impl            | Return from subroutine
| LDA         | 00011xxx | imm,abs,abx,aby | Load into AC register 
| LDX         | 00100xxx | imm,abs,aby,ac  | Load into X register
| LDY         | 00101xxx | imm,abs,abx,ac  | Load into Y register
| ADD         | 00110xxx | imm,abs,abx,aby | Arithmetic addition -> A
| SUB         | 00111xxx | imm,abs,abx,aby | Arithmetic subtraction -> A
| PSH         | 01000xxx | imm,abs,abx,aby | Push data to stack
| POP         | 01001xxx |                 | Pop data from stack
| SHL         | 01011xxx |                 | Shift left
| SHR         | 01100xxx |                 | Shift right
| AND         | 01101xxx |                 | Bitwise ANA
| OR          | 01110xxx |                 | Bitwise OR
| NOT         | 01111xxx |                 | Bitwise NOT
| XOR         | 10000xxx |                 | Bitwise XOR
| STA         | 10001xxx |                 | Store value of AC register
| STX         | 10010xxx |                 | Store value of X register
| STY         | 10011xxx |                 | Store value of Y register
| NOP         | 10100xxx | impl            | No operation
