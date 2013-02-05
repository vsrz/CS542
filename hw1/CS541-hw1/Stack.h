#define STACK_CAPACITY 1000

class Stack
{
private:
	char stack[STACK_CAPACITY];
	int size;
public:

	Stack(); // constructor for a stack
	void push( char c ); // adds c to the top of the stack
	void pop(); // removes top element
	char top(); // returns the top element
	bool isEmpty(); // returns true iff the stack is empty
	~Stack(); // destructor for a stack
};

Stack::Stack(){
	this->size = 0;
}
Stack::~Stack(){}


/* Push an item onto the stack */
void Stack::push(char c) {	

	/* First make sure we're not exceeding the stack size */
	if(this->size+1 > STACK_CAPACITY) {
		std::cout<<"Stack is already full\n";
		return;
	}
	
	/* Stick the item at the end of the array */
	stack[size+1] = c;
	this->size++;
}

void Stack::pop() {
	/* "Pop" the last element of the array */
	this->size--;
}

char Stack::top() {
	return stack[size];
}

bool Stack::isEmpty() {
	return(this->size==0);
}