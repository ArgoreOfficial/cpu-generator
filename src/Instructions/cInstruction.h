#pragma once 

#include "Bytecode.h"

class cInstruction
{
public:
	cInstruction();
	~cInstruction();

	void load( const std::string& _name );
	void construct();

private:
	unsigned char m_byte;
	std::string m_name;
	cBytecodeSequence m_sequence;
	std::vector<unsigned char> m_modes;
};
