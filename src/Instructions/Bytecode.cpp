#include "Bytecode.h"
#include <format>
#include <sstream>

cBytecodeSequence::cBytecodeSequence()
{
}

cBytecodeSequence::~cBytecodeSequence()
{
	for ( int i = 0; i < m_sequence.size(); i++ )
	{
		if ( m_sequence[ i ] )
		{
			delete m_sequence[ i ];
			m_sequence[ i ] = nullptr;
		}
	}
}

void cBytecodeSequence::construct()
{
	for ( int i = 0; i < m_sequence.size(); i++ )
	{
		printf( "%s\n", formatBytecode( *m_sequence[ i ] ).c_str() );
	}
}

sBytecode* cBytecodeSequence::constructBytecode( std::string _str )
{
	_str.erase( std::remove( _str.begin(), _str.end(), ' ' ), _str.end() );

	std::vector<eBytecodeKey> keys;
	
	for ( int i = 0; i < _str.size(); i++ )
	{
		switch ( _str[ i ] )
		{
		case '[':
			keys.push_back( kRegister );
			break;
		case '$':
			if ( !keys.empty() && keys.back() == kRegister )
				keys.back() = kRegisterRef;
			break;
		case '+':
			if ( !keys.empty() && keys.back() == kRegisterRef )
				keys.back() = kRegisterRefOffset;
			else
				keys.push_back( kAdd );
			break;
		case 'M':
			keys.push_back( kMemory );
			break;
		case '~':
			keys.push_back( kXor );
			break;
		case '|':
			keys.push_back( kOr );
			break;
		case '&':
			keys.push_back( kAnd );
			break;
		case '!':
			keys.push_back( kNor );
			break;
		case '-':
			if ( !keys.empty() && keys.back() == kShiftLeft )
				keys.back() = kCopyA;
			else 
				keys.push_back( kSubtract );
			break;
		case '*':
			keys.push_back( kMult );
			break;
		case '/':
			keys.push_back( kDivide );
			break;
		case '<':
			keys.push_back( kShiftLeft );
			break;
		case '>':
			if ( !keys.empty() && keys.back() == kSubtract )
				keys.back() = kCopyB;
			else
				keys.push_back( kShiftRight );
			break;
		}
	}

	if ( keys.empty() )
		return nullptr;

	eBytecodeKey key = keys.front();

	sBytecode* code = new sBytecode;
	code->key = key;
	std::vector<std::string> values = splitKeys( _str, key, key );

	sBytecode* code_a = constructBytecode( values[ 0 ] );
	if ( code_a ) code->a.code = code_a;
	else code->a.value = values[ 0 ];

	sBytecode* code_b = constructBytecode( values[ 1 ] );
	if ( code_b ) code->b.code = code_b;
	else code->b.value = values[ 1 ];

	return code;
}

std::string cBytecodeSequence::formatBytecode( sBytecode& _code )
{
	if ( _code.a.code )
	{
		_code.a.value = formatBytecode( *_code.a.code );
		delete _code.a.code;
		_code.a.code = nullptr;
	}
	if ( _code.b.code )
	{
		_code.b.value = formatBytecode( *_code.b.code );
		delete _code.b.code;
		_code.b.code = nullptr;
	}

	const char* a = _code.a.value.c_str();
	const char* b = _code.b.value.c_str();

	switch ( _code.key )
	{
	case kRegister:
		return std::format( "{}", a );
		break;
	case kRegisterRef:
		return std::format( "RAM[{}]", a );
		break;
	case kRegisterRefOffset:
		return std::format( "RAM[({} + {}) % 256]", a, b );
		break;
	case kMemory:
		return "mode_getmem()";
		break;
	case kCopyA:
		return std::format( "{} = {}", a, b );
		break;
	case kCopyB:
		return std::format( "{} = {}", a, b );
		break;
	case kXor:
		return std::format( "{} ~ {}", a, b );
		break;
	case kOr:
		return std::format( "{} | {}", a, b );
		break;
	case kAnd:
		return std::format( "{} & {}", a, b );
		break;
	case kNor:
		return std::format( "~{}", a );
		break;
	case kAdd:
		return std::format( "({} + {}) % 256", a, b );
		break;
	case kSubtract:
		return std::format( "({} - {}) % 256", a, b );
		break;
	case kMult:
		return std::format( "({} * {}) % 256", a, b );
		break;
	case kDivide:
		return std::format( "({} - {}) % 256", a, b );
		break;
	case kShiftLeft:
		return std::format( "bit32.lshift({}, {}) % 256", a, b );
		break;
	case kShiftRight:
		return std::format( "bit32.rshift({}, {}) % 256", a, b );
		break;
	case kPush:
		return std::format( "stack[SP+1] = {} \nSP += 1", a );
		break;
	case kPop:
		return std::format( "SP -= 1 \n{} = stack[SP]", a );
		break;
	default:
		return "";
		break;
	}

	return "";
}

std::vector<std::string> cBytecodeSequence::splitKeys( const std::string& _str, eBytecodeKey _key, char _divider )
{
	std::string tmp;
	std::string val_a;
	std::string val_b;
	std::stringstream stream( _str );

	switch ( _key )
	{
	case kMemory:
		val_a = "";
		val_b = "";
		break;
	case kRegister: // [x] -> Register, A=x, B=null
		std::getline( stream, tmp, '[' );
		std::getline( stream, val_a, ']' );
		break;
	case kRegisterRef: // [$x] -> Register Ref, A=x, B=null
		std::getline( stream, tmp, '$' );
		std::getline( stream, val_a, ']' );
		break;
	case kRegisterRefOffset: // [$x+n] -> Register Ref Offset, A=x, B=n
		std::getline( stream, tmp, '$' );
		std::getline( stream, val_a, '+' );
		std::getline( stream, val_b, ']' );
		break;
	case kNor: // ![x] -> Nor/Invert, A=x
		std::getline( stream, tmp, '[' );
		std::getline( stream, val_a, ']' );
		break;
	case kCopyA: // x<-y -> Copy y into Addr. of x, A=x, B=y
		std::getline( stream, val_a, '<' );
		std::getline( stream, tmp, '-' );
		std::getline( stream, val_b, '-' );
		break;
	case kCopyB: // x->y -> Copy x into Addr. of y, A=y, B=x
		std::getline( stream, val_b, '-' );
		std::getline( stream, tmp, '>' );
		std::getline( stream, val_a, '-' );
		break;
	default:
		std::getline( stream, val_a, _divider );
		std::getline( stream, val_b, _divider );
		break;
	}

	std::vector<std::string> out;
	out.push_back( val_a );
	out.push_back( val_b );

	return out;
}
