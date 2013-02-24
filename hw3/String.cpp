#include "String.h"


String::String( const char * s = "")
{	
	len = strlen(s);
	
	if ( len == 0 )
		buf = NULL;
	else
	{
		// Create new memspace for the string
		assert(len+1 > 0);
		buf = new char[len+1];
		strcpy(buf, s);
	}
	//cout << "len: " << len << " buf: " << buf << " s: " << s << " strlen: " << strlen(buf) <<  endl;
}

String::String( const String & s )
{
	len = s.len;
	if ( len == 0 )
		buf = NULL;
	else 
	{
		assert(len+1 > 0);
		buf = new char[len+1];
		strcpy(buf,s.buf);
	}
}

char* String::strcpy(char* dest, const char* source)
{
	// dest should be correctly sized before passing in
	char* o = dest;
	int i = 0;
	while(*dest++ = *source++);
	dest = o;

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

bool String::strcmp(const char* s,const char *t)
{
	for (  int i = 0; i < len; i++ )
		if ( s[i] != t[i] )
			return false;
	return true;
}

String String::operator = ( const String & s )
{
	if ( buf != NULL)
		delete[] buf;
	len = strlen(s);
	buf = new char[len+1];
	strcpy(buf,s.buf);
	return *this;
}

char & String::operator [] ( int index )
{
	assert(index >= 0);
	while(index--)
		buf++;
	return *buf;
}

int String::size()
{	
	return len+1;
}

// does not modify this String
String String::reverse()
{
	// Don't bother if the string is empty
	if(len == 0)
		return String();
	char *r, *orig;
	r = new char[len];
	orig = r;

	// Loop through the buf in reverse order (skip the null)
	for ( int i = strlen(buf)-1; i >= 0; --i)
		*r++ = buf[i];

	// Append the null terminator to the string
	*r++ = '\0';
	r = orig;
	return String(r);
	
} 

int String::indexOf( char c )
{
	for ( int i = 0; i < len; i++ )
		if(buf[i] == c)
			return i+1;
	return 0;
}

int String::indexOf( String pattern )
{
	if ( len != pattern.len )
		return 0;

	for ( int i = 0; i < len; i++) 
	{

		return 0;


	}
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
	if ( *this == s )
		return false;
	else 
	{
		for ( int i = 0; i < len; i++ )
			if ( buf[i] > s[i] )
				return true;
	}
	return false;
}

bool String::operator < ( String s )
{
	return ! operator > (s);
}

bool String::operator <= ( String s )
{
	if ( *this == s )
		return false;
	else 
	{
		for ( int i = 0; i < len; i++ )
			if ( buf[i] <= s[i] )
				return true;
	}
	return false;
}

bool String::operator >= ( String s )
{
	return ! operator <= (s);
}

/// concatenates this and s to return result
String String::operator + ( String s )
{	
	if ( len == 0 && s.len == 0)
	{
		return String();		
	}
	else if ( len == 0 )
		return s;
	else
	{
		String r;
		r.len = len + s.len;		
		return r;	
	}


}

/// concatenates s onto end of this
String String::operator += ( String s )
{
	if ( len == 0 ) 
	{
		len = s.len;
		buf = new char[len+1];
		strcpy(buf,s.buf);
	}
	else
	{
		//String n(buf + s.buf);

	}
	return *this;
}
void String::print( ostream & out )
{
	out << buf;
}
void String::read( istream & in )
{
	in >> buf;
}

String::~String() 
{
	if ( len > 0 )
		delete[] buf;
}

ostream & operator << ( ostream & out, String str )
{
	str.print(out);
	return out;
}

istream & operator >> ( istream & in, String & str )
{	
	str.read(in);
	return in;
}