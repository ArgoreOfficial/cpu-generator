#pragma once

#include "../Instructions/cInstruction.h"
#include "../Instructions/cAddressingMode.h"
#include <vector>

class cInstructionSet
{
public:
	cInstructionSet();
	~cInstructionSet();

private:
	std::vector<cInstruction> m_instructions;
	std::vector<cAddressingMode> m_modes;

};
