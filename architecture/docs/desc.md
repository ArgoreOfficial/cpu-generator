
# P65255 Processor

```
Pendulum Electronics
65k ram
255 bytes rom
```

| Data    | |
| ----    | -
| RAM     | 65535 bytes
| ROM     | 255 bytes (?)
| I/O     | QWERTY Keyboard Input / Video Output
| I/O Mem | Last Keyboard InputCode+Handled Flag / 


## [Instruction Set Manual](instr.md)

## Instruction Cycle
[copied from wikipedia]([https://en.wikipedia.org/wiki/Instruction_cycle#/media/File:Fetch-Decode-Execute_Cycle.png]) 

1. Address in PC copied to MAR
2. PC incremented to next instruction
3. Opcode at address in MAR copied into MDR
4. Opcode in MDR copied to CIR
5. Decode Opcode in CIR^[instr.md#opcode-decoding]
6. Execute Opcode
