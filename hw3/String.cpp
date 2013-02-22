#include "String.h"


String::String( const char * s = "")
{	
	len = strlen(s);
	// Create new memspace for the string
	assert(len+1 > 0);
	buf = NULL;
	strcpy(buf, s);
	
	// Copy contents of s over
	//memcpy(buf, s, len*sizeof(char));
	// while(*buf++ = *s++); // why break?

	cout << "len: " << len << " buf: " << buf << " s: " << s << " strlen: " << strlen(buf) <<  endl;
}

String::String( const String & s )
{
	
}

char* String::strcpy(char* dest, const char* source)
{
	if(dest != NULL) delete dest;
	dest = new char[strlen(dest)];
	for(int i=0; i<len; i++)
		dest[i] = source[i];
	dest[len] = '\0';
	buf = dest;
	return dest;
}

int String::strlen( const char * s) 
{	// Get strlen of s
	int len = 0;
	if(s==NULL) return 0;
	while(*s++ != '\0')
		len++;
	return len;

}

int String::strlen( const String & s)
{
	return(strlen(s.buf));
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
	if(len != s.len)
		return false;
	for ( int i = 0; i < s.len; i++ )
		if ( buf[i] != s.buf[i] )
			return false;
	return true;
}

bool String::operator != ( String s )
{
	return ! operator == (s);
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
	//delete[] buf; 
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