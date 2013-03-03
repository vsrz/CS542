
#include "String.h"

namespace lstring {


String::String( const char * s = "")
{
	head = create(s);
#ifdef DEBUG
	cout << "Copy Created" << endl;	
#endif // DEBUG

	
}

String::String( const String & s )
{
	head = copy( s.head );
#ifdef DEBUG
	cout << "Copy Created" << endl;	
#endif // DEBUG
}

String::~String() 
{ 
	flush(head); 

}

String String::operator = ( const String & s )
{
#ifdef DEBUG
	cout << "Function called" << endl;	
#endif // DEBUG

	ListNode *n = copy( s.head );
	flush(head);
	head = n;
	return *this;
}

char & String::operator [] ( const int index )
{
#ifdef DEBUG
	cout << "Function called" << endl;	
#endif // DEBUG

	ListNode *n = head;
	for( int i = index ; i > 0 ; i-- )
		n = n->next;
	return n->info;
}

int String::length() const
{
#ifdef DEBUG
	cout << "Function called" << endl;	
#endif // DEBUG
	ListNode *n = head;		
	if(head == NULL) return 0;
	int i = 1;
	while(n = n->next)
		i++;
	return i;		
}
	
int String::indexOf( char c ) const
{
#ifdef DEBUG
	cout << "Function called" << endl;	
#endif // DEBUG
	if(head == NULL) return -1;
	int i = 0;
	for( ListNode *n = head; n; n = n->next, ++i )
		if( n->info == c )
			return i;
	return -1;
		
}

bool String::operator == ( const String & s ) const
{		
#ifdef DEBUG
	cout << "Function called" << endl;	
#endif // DEBUG
	ListNode *l = head, *r = s.head;
		
	do
	{
		// if node is not null
		if ( l && r )
			// and info doesn't matche
			if ( l->info != r->info )
				return false;
		if ( !l || !r )
			return false;
			
	} while( ( l = l->next ) && ( r = r->next ) );
	return true;
}

String String::operator + ( const String & s ) const
{
#ifdef DEBUG
	cout << "Function called" << endl;	
#endif // DEBUG
	String str = *this;
	for( ListNode *n = s.head; n; n = n->next )
		append(str.head, n->info);
	return str;

}

String String::operator += ( const String & s )
{
#ifdef DEBUG
	cout << "Function called" << endl;	
#endif // DEBUG
	// append each character to end node (slow!)
	for( ListNode *n = s.head; n; n = n->next )
		append(head, n->info);
	return *this;
}
	
void String::print( ostream & out )
{		
	for( ListNode *n = head ; n ; n = n->next )
		out << n->info;
}

void String::read( istream & in ) 
{
#ifdef DEBUG
	cout << "Function called" << endl;	
#endif // DEBUG
	char uin[256];
	in >> uin;
	flush(head);
	head = create(uin);	
}


void String::append ( ListNode *p, char s ) const
{	   
#ifdef DEBUG
	cout << "Function called" << endl;	
#endif // DEBUG
	while(p->next) p = p->next;
	ListNode *n = new ListNode(s,NULL);
	p->next = n;		
}

String::ListNode* String::create ( const char *s )
{		
#ifdef DEBUG
	cout << "Function called" << endl;	
#endif // DEBUG
	// recursively create nodes passing the next char as the new head
	return s[0] != NULL ? 
		new ListNode ( s[0], create ( s+1 ) ) :
		NULL;
}

String::ListNode* String::copy ( const ListNode *s )
{
#ifdef DEBUG
	cout << "Function called" << endl;	
#endif // DEBUG
	return s != NULL ?
		new ListNode( s->info, copy( s->next ) ) :
		NULL;
}

void String::flush( ListNode *p )
{		
#ifdef DEBUG
	cout << "Function called" << endl;	
#endif // DEBUG
	if(p != NULL)
		flush(p->next);
	delete[] p;
}

ostream & operator << ( ostream & out, String str )
{
#ifdef DEBUG
	cout << "Function called" << endl;	
#endif // DEBUG
	str.print(out);
	return out;
}

istream & operator >> ( istream & in, String & str )
{
#ifdef DEBUG
	cout << "Function called" << endl;	
#endif // DEBUG
	str.read(in);
	return in;

}

} // end namespace
