#include "String.h"

namespace zstring {

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
		len = strlen(s);
		if ( len == 0 )
			buf = NULL;
		else 
		{
			assert(len+1 > 0);
			buf = new char[len+1];
			strcpy(buf,s.buf);
		}
	}

	String String::operator = ( const String & s )
	{
		if ( len > 0 )
			delete[] buf;
		len = strlen(s);
		buf = new char[len+1];
		strcpy(buf,s.buf);
		return *this;
	}

	char & String::operator [] ( int index )
	{
		assert ( inBounds ( index ) );
		return buf[index];
	}

	int String::size() const
	{	
		return strlen(buf);
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
				return i;
		return -1;
	}

	int String::indexOf( String pattern )
	{
		// First check the length
		if ( len == 0 || pattern.len == 0)
			return -1;

		for ( int i = 0; i < len; i++) 
		{
			// If the first character matches
			if(pattern[0] == buf[i])
			{
				// Compare each character
				for ( int x = 0; x < pattern.len; x++ )
				{
					// If it's not a match, break the loop and try the next charset
					if ( pattern[x] != buf[i+x] )
						break;

					// If we've reached the end of the needle, we've found a match
					if ( x+1 == pattern.len )
						return i;
				}
			}
		}
		return -1;
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
		return ! operator >= (s);
	}

	bool String::operator <= ( String s )
	{
		return ! operator > (s);
	}

	bool String::operator >= ( String s )
	{
		return *this == s || ! operator > (s);
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
		else if ( s.len == 0 )
		{
			return *this;
		}
		else
		{
			int newsize = size() + s.size() + 1;
			
			char *o = new char[newsize];
			strcpy(o, buf);
			
			// Replace it with the new one			
			strcat(o, s.buf);
			
			
			return String(o);
		}
	}

	/// concatenates s onto end of this
	String String::operator += ( String s )
	{
		if ( len == 0 && s.len == 0)
		{
			return String();		
		}
		else if ( len == 0 )
			return s;
		else if ( s.len == 0 )
		{
			return *this;
		}
		else
		{
			int newsize = size() + s.size() + 1;
			
			char *o = new char[newsize];
			strcpy(o, buf);
			
			// Now, delete the old string
			if ( size() > 0 )
				delete[] buf;

			// Replace it with the new one			
			strcat(o, s.buf);
			buf = o;
			len = strlen(buf);
			return buf;
		}
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
		if ( size() > 0 )
			delete[] buf;
	}


	/* Non member functions */	
	char* strcpy(char* dest, const char* source)
	{
		// dest should be correctly sized before passing in
		char *o = dest;
		while(*dest++ = *source++);
		dest = o;
		return dest;
	}

	int strlen( const char * s ) 
	{			
		int len = 0;
		if(s==NULL) return 0;
		while(*s++ != '\0')
			len++;
		return len;
	}

	int strlen( const String & s )
	{
		// Not counting the null terminator
		return(s.size());
	}

	bool strcmp(const char* s,const char *t)
	{
		for (  int i = 0; i < strlen(s); i++ )
			if ( s[i] != t[i] )
				return false;
		return true;
	}

	/* Resulting string should already be large enough to 
	   contain the new concatenated string. */
	char* strcat(char *dest, const char *source) 
	{
		// Save the original pointer
		char *o = dest;

		// Start at the end of dest, and the beginning of source
		int i = strlen(dest);
		int x = 0;
		while(dest[i++] = source[x++]);
		
		return dest;
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

}
