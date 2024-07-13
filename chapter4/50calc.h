#define NUMBER	'0'	//signal that a number was found
#define MAXOP 	100	// max size of operand or operator
#define MAXVAL  100


int getop(char []);
	// get next operator or numeric operand
void push(double);
	// push f onto value stack
double pop(void);
	//pop and return top value from stack
void command(char);
	//execute function; with p
int getch(void);
	//get a character
void ungetch(int);
	//push character back on input
