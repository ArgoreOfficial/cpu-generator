|        | x0       | x1       | x2       | x3       | x4       | x5       | x6       | x7       | x8       | x9       | xA       | xB       | xC       | xD       | xE       | xF       |
| :----: | :------: | :------: | :------: | :------: | :------: | :------: | :------: | :------: | :------: | :------: | :------: | :------: | :------: | :------: | :------: | :------: |
| **0x** | [         ](#)| [         ](#)| [         ](#)| [         ](#)| [JMP abs  ](#jmp)| [         ](#)| [         ](#)| [JMP ind  ](#jmp)| [         ](#)| [         ](#)| [         ](#)| [         ](#)| [JSR abs  ](#jsr)| [         ](#)| [         ](#)| [         ](#)|
| **1x** | [RTS impl ](#rts)| [         ](#)| [         ](#)| [         ](#)| [         ](#)| [         ](#)| [         ](#)| [         ](#)| [         ](#)| [LDA imm  ](#lda)| [         ](#)| [         ](#)| [LDA abs  ](#lda)| [LDA abx  ](#lda)| [LDA aby  ](#lda)| [         ](#)|
| **2x** | [         ](#)| [LDX imm  ](#ldx)| [LDX ac   ](#ldx)| [         ](#)| [LDX abs  ](#ldx)| [         ](#)| [LDX aby  ](#ldx)| [         ](#)| [         ](#)| [LDY imm  ](#ldy)| [LDY ac   ](#ldy)| [         ](#)| [LDY abs  ](#ldy)| [LDY abx  ](#ldy)| [         ](#)| [         ](#)|
| **3x** | [         ](#)| [ADD imm  ](#add)| [         ](#)| [         ](#)| [ADD abs  ](#add)| [ADD abx  ](#add)| [ADD aby  ](#add)| [         ](#)| [         ](#)| [SUB imm  ](#sub)| [         ](#)| [         ](#)| [SUB abs  ](#sub)| [SUB abx  ](#sub)| [SUB aby  ](#sub)| [         ](#)|
| **4x** | [         ](#)| [DIV imm  ](#div)| [         ](#)| [         ](#)| [DIV abs  ](#div)| [DIV abx  ](#div)| [DIV aby  ](#div)| [         ](#)| [         ](#)| [MUL imm  ](#mul)| [         ](#)| [         ](#)| [MUL abs  ](#mul)| [MUL abx  ](#mul)| [MUL aby  ](#mul)| [         ](#)|
| **5x** | [         ](#)| [PSH imm  ](#psh)| [PSH ac   ](#psh)| [         ](#)| [PSH abs  ](#psh)| [PSH abx  ](#psh)| [PSH aby  ](#psh)| [         ](#)| [POP impl ](#pop)| [         ](#)| [         ](#)| [         ](#)| [         ](#)| [         ](#)| [         ](#)| [         ](#)|
| **6x** | [         ](#)| [         ](#)| [SHL ac   ](#shl)| [         ](#)| [SHL abs  ](#shl)| [SHL abx  ](#shl)| [SHL aby  ](#shl)| [         ](#)| [         ](#)| [         ](#)| [SHR ac   ](#shr)| [         ](#)| [SHR abs  ](#shr)| [SHR abx  ](#shr)| [SHR aby  ](#shr)| [         ](#)|
| **7x** | [         ](#)| [         ](#)| [AND ac   ](#and)| [         ](#)| [AND abs  ](#and)| [AND abx  ](#and)| [AND aby  ](#and)| [         ](#)| [         ](#)| [         ](#)| [OR ac    ](#or)| [         ](#)| [OR abs   ](#or)| [OR abx   ](#or)| [OR aby   ](#or)| [         ](#)|
| **8x** | [         ](#)| [         ](#)| [NOT ac   ](#not)| [         ](#)| [NOT abs  ](#not)| [NOT abx  ](#not)| [NOT aby  ](#not)| [         ](#)| [         ](#)| [         ](#)| [XOR ac   ](#xor)| [         ](#)| [XOR abs  ](#xor)| [XOR abx  ](#xor)| [XOR aby  ](#xor)| [         ](#)|
| **9x** | [         ](#)| [         ](#)| [         ](#)| [         ](#)| [STA abs  ](#sta)| [STA abx  ](#sta)| [STA aby  ](#sta)| [         ](#)| [         ](#)| [         ](#)| [         ](#)| [         ](#)| [STX abs  ](#stx)| [STX abx  ](#stx)| [STX aby  ](#stx)| [         ](#)|
| **Ax** | [         ](#)| [         ](#)| [         ](#)| [         ](#)| [STY abs  ](#sty)| [STY abx  ](#sty)| [STY aby  ](#sty)| [         ](#)| [CLM impl ](#clm)| [         ](#)| [         ](#)| [         ](#)| [         ](#)| [         ](#)| [         ](#)| [         ](#)|
| **Bx** | [NOP impl ](#nop)| [         ](#)| [         ](#)| [         ](#)| [         ](#)| [         ](#)| [         ](#)| [         ](#)| [         ](#)| [         ](#)| [         ](#)| [         ](#)| [         ](#)| [         ](#)| [         ](#)| [         ](#)|
| **Cx** | [         ](#)| [         ](#)| [         ](#)| [         ](#)| [         ](#)| [         ](#)| [         ](#)| [         ](#)| [         ](#)| [         ](#)| [         ](#)| [         ](#)| [         ](#)| [         ](#)| [         ](#)| [         ](#)|
| **Dx** | [         ](#)| [         ](#)| [         ](#)| [         ](#)| [         ](#)| [         ](#)| [         ](#)| [         ](#)| [         ](#)| [         ](#)| [         ](#)| [         ](#)| [         ](#)| [         ](#)| [         ](#)| [         ](#)|
| **Ex** | [         ](#)| [         ](#)| [         ](#)| [         ](#)| [         ](#)| [         ](#)| [         ](#)| [         ](#)| [         ](#)| [         ](#)| [         ](#)| [         ](#)| [         ](#)| [         ](#)| [         ](#)| [         ](#)|
| **Fx** | [         ](#)| [         ](#)| [         ](#)| [         ](#)| [         ](#)| [         ](#)| [         ](#)| [         ](#)| [         ](#)| [         ](#)| [         ](#)| [         ](#)| [         ](#)| [         ](#)| [         ](#)| [         ](#)|



> ### JMP
> 
> | Mode | Opcode | Bytes 
> | :--- | :----: | :---: 
> | **Absolute** | 0x04 | 3 
> | **Indirect** | 0x07 | 3 


> ### JSR
> 
> | Mode | Opcode | Bytes 
> | :--- | :----: | :---: 
> | **Absolute** | 0x0C | 3 


> ### RTS
> 
> | Mode | Opcode | Bytes 
> | :--- | :----: | :---: 
> | **Implied** | 0x10 | 1 


> ### LDA
> 
> | Mode | Opcode | Bytes 
> | :--- | :----: | :---: 
> | **Immediate** | 0x19 | 2 
> | **Absolute** | 0x1C | 3 
> | **Absolute,X** | 0x1D | 3 
> | **Absolute,Y** | 0x1E | 3 


> ### LDX
> 
> | Mode | Opcode | Bytes 
> | :--- | :----: | :---: 
> | **Immediate** | 0x21 | 2 
> | **Absolute** | 0x24 | 3 
> | **Absolute,Y** | 0x26 | 3 
> | **AC** | 0x22 | 1 


> ### LDY
> 
> | Mode | Opcode | Bytes 
> | :--- | :----: | :---: 
> | **Immediate** | 0x29 | 2 
> | **Absolute** | 0x2C | 3 
> | **Absolute,X** | 0x2D | 3 
> | **AC** | 0x2A | 1 


> ### ADD
> 
> | Mode | Opcode | Bytes 
> | :--- | :----: | :---: 
> | **Immediate** | 0x31 | 2 
> | **Absolute** | 0x34 | 3 
> | **Absolute,X** | 0x35 | 3 
> | **Absolute,Y** | 0x36 | 3 


> ### SUB
> 
> | Mode | Opcode | Bytes 
> | :--- | :----: | :---: 
> | **Immediate** | 0x39 | 2 
> | **Absolute** | 0x3C | 3 
> | **Absolute,X** | 0x3D | 3 
> | **Absolute,Y** | 0x3E | 3 


> ### DIV
> 
> | Mode | Opcode | Bytes 
> | :--- | :----: | :---: 
> | **Immediate** | 0x41 | 2 
> | **Absolute** | 0x44 | 3 
> | **Absolute,X** | 0x45 | 3 
> | **Absolute,Y** | 0x46 | 3 


> ### MUL
> 
> | Mode | Opcode | Bytes 
> | :--- | :----: | :---: 
> | **Immediate** | 0x49 | 2 
> | **Absolute** | 0x4C | 3 
> | **Absolute,X** | 0x4D | 3 
> | **Absolute,Y** | 0x4E | 3 


> ### PSH
> 
> | Mode | Opcode | Bytes 
> | :--- | :----: | :---: 
> | **Immediate** | 0x51 | 2 
> | **Absolute** | 0x54 | 3 
> | **Absolute,X** | 0x55 | 3 
> | **Absolute,Y** | 0x56 | 3 
> | **AC** | 0x52 | 1 


> ### POP
> 
> | Mode | Opcode | Bytes 
> | :--- | :----: | :---: 
> | **Implied** | 0x58 | 1 


> ### SHL
> 
> | Mode | Opcode | Bytes 
> | :--- | :----: | :---: 
> | **Absolute** | 0x64 | 3 
> | **Absolute,X** | 0x65 | 3 
> | **Absolute,Y** | 0x66 | 3 
> | **AC** | 0x62 | 1 


> ### SHR
> 
> | Mode | Opcode | Bytes 
> | :--- | :----: | :---: 
> | **Absolute** | 0x6C | 3 
> | **Absolute,X** | 0x6D | 3 
> | **Absolute,Y** | 0x6E | 3 
> | **AC** | 0x6A | 1 


> ### AND
> 
> | Mode | Opcode | Bytes 
> | :--- | :----: | :---: 
> | **Absolute** | 0x74 | 3 
> | **Absolute,X** | 0x75 | 3 
> | **Absolute,Y** | 0x76 | 3 
> | **AC** | 0x72 | 1 


> ### OR 
> 
> | Mode | Opcode | Bytes 
> | :--- | :----: | :---: 
> | **Absolute** | 0x7C | 3 
> | **Absolute,X** | 0x7D | 3 
> | **Absolute,Y** | 0x7E | 3 
> | **AC** | 0x7A | 1 


> ### NOT
> 
> | Mode | Opcode | Bytes 
> | :--- | :----: | :---: 
> | **Absolute** | 0x84 | 3 
> | **Absolute,X** | 0x85 | 3 
> | **Absolute,Y** | 0x86 | 3 
> | **AC** | 0x82 | 1 


> ### XOR
> 
> | Mode | Opcode | Bytes 
> | :--- | :----: | :---: 
> | **Absolute** | 0x8C | 3 
> | **Absolute,X** | 0x8D | 3 
> | **Absolute,Y** | 0x8E | 3 
> | **AC** | 0x8A | 1 


> ### STA
> 
> | Mode | Opcode | Bytes 
> | :--- | :----: | :---: 
> | **Absolute** | 0x94 | 3 
> | **Absolute,X** | 0x95 | 3 
> | **Absolute,Y** | 0x96 | 3 


> ### STX
> 
> | Mode | Opcode | Bytes 
> | :--- | :----: | :---: 
> | **Absolute** | 0x9C | 3 
> | **Absolute,X** | 0x9D | 3 
> | **Absolute,Y** | 0x9E | 3 


> ### STY
> 
> | Mode | Opcode | Bytes 
> | :--- | :----: | :---: 
> | **Absolute** | 0xA4 | 3 
> | **Absolute,X** | 0xA5 | 3 
> | **Absolute,Y** | 0xA6 | 3 


> ### CLM
> 
> | Mode | Opcode | Bytes 
> | :--- | :----: | :---: 
> | **Implied** | 0xA8 | 1 


> ### NOP
> 
> | Mode | Opcode | Bytes 
> | :--- | :----: | :---: 
> | **Implied** | 0xB0 | 1 


