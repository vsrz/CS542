#define STACK_CAPACITY 1000

class Stack
{
private:
	char stack[STACK_CAPACITY];
	int getSize();
public:

	Stack(); // constructor for a stack
	void push( char c ); // adds c to the top of the stack
	void pop(); // removes top element
	char top(); // returns the top element
	bool isEmpty(); // returns true iff the stack is empty
	~Stack(); // destructor for a stack
};

int Stack::getSize() {
	return(sizeof(this->stack)/sizeof(char));
}
/* Stack constructor */
Stack::Stack() {
	
}

/* Push an item onto the stack */
void Stack::push(char c) {
	for (int i=0; i<s
}