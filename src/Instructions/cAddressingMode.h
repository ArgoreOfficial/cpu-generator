#pragma once
#include "Bytecode.h"

class cAddressingMode
{
public:
	cAddressingMode();
	~cAddressingMode();

private:
	unsigned char m_byte;
	std::string m_name;
	cBytecodeSequence m_sequence;

};
