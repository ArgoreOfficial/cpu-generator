#include "cInstruction.h"

#include <sstream>
#include <fstream>
#include <iostream>

cInstruction::cInstruction()
{

}

cInstruction::~cInstruction()
{

}

void cInstruction::load( const std::string& _name )
{
	m_name = _name;
	const std::string full_path = "architecture/instructions/" + _name + ".instrc";

	std::ifstream file_stream( full_path );
	std::stringstream file_buffer;
	file_buffer << file_stream.rdbuf();

	std::istringstream file_string_stream( file_buffer.str() );
	std::string line;
	while ( std::getline( file_string_stream, line ) )
	{
		m_sequence.push( line );
	}
}

void cInstruction::construct()
{
	m_sequence.construct( m_name );
}
