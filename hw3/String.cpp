#include "String.h"


String::String( const char * s = "")
{	
	const char* o = s;
	// Get strlen of s
	len = 0;
	while(*s++ != '\0')
		len++;

	// Create new memspace for the string
	buf = new char[len+1]();

	// Restore original pointer value
	s = o;

	// Copy contents of s over
	memcpy(buf, s, len*sizeof(char));
	
	//cout << "len: " << len << " buf: " << buf << " s: " << s << " strlen: " << strlen(buf);
}

String::String( const String & s )
{

}

String String::operator = ( const String & s )
{
	return " ";
}

char & String::operator [] ( int index )
{
	return *buf;
}

int String::size()
{

	return 0;
}

// does not modify this String
String String::reverse()
{
	return " ";
} 

int String::indexOf( char c )
{
	return 0;
}

int String::indexOf( String pattern )
{
	return 0;
}

bool String::operator == ( String s )
{
	if(s.len == len)
		return true;
	return false;
}

bool String::operator != ( String s )
{
	return false;
}

bool String::operator > ( String s )
{
	return false;
}

bool String::operator < ( String s )
{
	return false;
}

bool String::operator <= ( String s )
{
	return false;
}

bool String::operator >= ( String s )
{
	return false;
}

/// concatenates this and s to return result
String String::operator + ( String s )
{
	return s;

}

/// concatenates s onto end of this
String String::operator += ( String s )
{
	return s;
}
void String::print( ostream & out )
{
	out << buf;
}
void String::read( istream & in )
{

}

String::~String() 
{
	delete[] buf; 
}

ostream & operator << ( ostream & out, String str )
{
	str.print(out);
	return out;
}

istream & operator >> ( istream & in, String & str )
{	
	return in;
}