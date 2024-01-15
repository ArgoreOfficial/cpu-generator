#pragma once

#include <string>
#include <vector>
#include <map>

enum eBytecodeKey
{
	kNone = 0,
	kRegister = 1,				// [..]      Register ..
	kRegisterRef = 2,			// [$..]     Value at Address Register ..
	kRegisterRefOffset = 3,		// [$..+x]   Value at Address Register .. offset by x
	kMemory = 4,				// M         Memory fetched by AddressingMode
	kCopyA = 5,					// <-        Copy value B into address A
	kCopyB = 6,					// ->        Copy value A into address B
	kXor = '~',					// ~         XOR A and B
	kOr = '|',					// |         OR A and B
	kAnd = '&',					// &         AND A and B
	kNor = '!',					// !         NOR A and B
	kAdd = '+',					// +         A + B
	kSubtract = '-',			// -         A - B
	kMult = '*',				// *         A * B
	kDivide = '/',				// /         A / B
	kShiftLeft = '<',			// <         A shifted left B amount
	kShiftRight = '>',			// >         A shifted right B amount
	kPush,					    // push      A pushed onto stack, stack pointer incremented
	kPop					    // pop       value at stack pointer moved into A, stack pointer decremented
};

struct sBytecode;

struct sBytecodeValue
{
	sBytecode* code = nullptr;
	std::string value;
};

struct sBytecode
{
	eBytecodeKey key;

	sBytecodeValue a;
	sBytecodeValue b;

	~sBytecode()
	{
		if ( a.code )
		{
			delete a.code;
			a.code = nullptr;
		}
		if ( b.code )
		{
			delete b.code;
			b.code = nullptr;
		}
	}
};


class cBytecodeSequence
{
public:
	cBytecodeSequence();
	~cBytecodeSequence();

	void push( std::string _str ) { m_sequence.push_back( constructBytecode( _str ) ); }
	void construct( const std::string& _name );

private:
	sBytecode* constructBytecode( std::string _str );

	sBytecode* constructOperation( std::string _str );
	sBytecode* constructAddress( std::string _str );

	sBytecode* constructBytecodeValues( eBytecodeKey _key, const std::string& _str );

	std::string formatBytecode( sBytecode& _code );
	std::vector<std::string> splitKeys( const std::string& _str, eBytecodeKey _key, char _divider );

	std::vector<sBytecode*> m_sequence;

};
