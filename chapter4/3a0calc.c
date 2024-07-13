#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXLEN	1000	// max length of input line
#define MAXOP 	100	// max size of operand or operator
#define NUMBER	'0'	//signal that a number was found

int getop(char [], char []);
	// get next operator or numeric operand
void push(double);
	// push f onto value stack
double pop(void);
	//pop and return top value from stack
void command(int, char []);
	//execute function; with push and pop
	//or make a variable
void getline(char []);
	//read line into main input string

/*
pg79; reverse polish calculator; takes one line of input at a time
 */

int main()
{
  int type;
  int i;
  double op2;
  char in[MAXLEN];	//main input
  char s[MAXOP];

  getline(in);
  for(i = 0; (type = getop(s,in)) != EOF; i++) {
    switch(type) {
    case NUMBER:
      push(atof(s));
      break;
    case '+':
      push(pop() + pop());
      break;
    case '*':
      push(pop() * pop());
      break;
    case '-':
      op2 = pop();
      push(pop() - op2);
      break;
    case '/':
      op2 = pop();
      if(op2 != 0.0)
	push(pop() / op2);
      else
	printf("error/devision: zero devisor");
      break;
    case '%':
      op2 = pop();
      if(op2 != 0.0)
	push((int) pop() % (int) op2);
      else
	printf("error/modulus: zero devisor");
      break;
    case '\n':
      ;
      break;
    default:
      if((type >= 'a' && type <= 'z') || type == '$') {
	command(type,in);
	break;
      }
      else {
	printf("error/main: unknown command %s\n", s);
	break;
      }
    }
  }
  return 0;
}
  
#define MAXVAL	100	// max depth of val stack

int sp = 0;		//next free stack position
double val[MAXVAL];	// value stack

void push(double f)
{
  if(sp < MAXVAL)
    val[sp++] = f;
  else {
    printf("error/push: stack full, can't push %g\n", f);
  }
}

double pop(void)
{
  if(sp > 0)
    return val[--sp];
  else {
    printf("error/pop: stack empty\n");
    return 0.0;
  }
}

#include <ctype.h>

int checkstr(char[], char[]);
//check if strings are the same
void print(void);
//print top of stack
void pop1(void);
//pop and print
void duplicate(void);
//duplicate top element of stack
void swap(void);
//swap top two elements of stack
void clear(void);
//clear stack

#define VARNUM 26
  char var[VARNUM];
  char set[VARNUM];

void command(char c, char in[])
{
  char d;
  char s[MAXOP];
  int x; 	//varnum position
  int i;
  
  //get command
  s[0] = c;	
  for(i = 1; (d = getch()) != '\n' && d != ' ' && d != '\t'; i++)
    s[i] = d;
  s[i] = '\0';
  ungetch(d);

  if(s[0] == '$') { 	// assign variable
    x = s[1] - 'a';	//find x
    if(s[1] >= 'a' && s[1] <= 'z') {	//valid variable
      push(var[x] = pop());
      set[x] = 1;
    }
    else
      printf("error/command: invalid variable\n");
  }
    
  //if is variable (1 character), 
  else if(i == 1) {
    x = s[0] - 'a';
    if(set[x] == 1)
      push(var[x]);
    else
      printf("error/command: unassigned variable\n");
  }
  
  //find and execute command
    //math.h
  else if(checkstr(s,"sin"))
    push(sin(pop()));
  else if(checkstr(s,"cos"))
    push(cos(pop()));
    //system
  else if(checkstr(s, "ungets"))
    ungets();
  else if(checkstr(s, "print"))
    print();
  else if(checkstr(s, "pop"))
    pop1();
  else if(checkstr(s, "duplicate"))
    duplicate();
  else if(checkstr(s, "swap"))
    swap();
  else if(checkstr(s, "clear"))
    clear();
  else
    printf("error/command: unknown command\n");
}

int checkstr(char s[], char t[])
{
  int i;
  
  for(i = 0; s[i] == t[i]; i++)
    if(s[i] == '\0') {
      return 1;
    }
  return 0;
}  

int getop(char s[], char in[])
{
  int i, c, d, x;
  
  x = 1;
  while ((s[0] = c = getch()) == ' ' || c == '\t')
    ;
  s[1] = '\0';
  
  if(c == '-') {
    if(isdigit(d = getch()))
      x = 0; 	//negative
    else
      x = 1; 	//subtraction
    ungetch(d);
  }
  if(!isdigit(c) && c != '.' && x) {
    return c;		//not a number
  }
  i = 0;
  if(isdigit(c) || c == '-')	//collext inger part
    while(isdigit(s[++i] = c = getch()))
      ;
  if(c == '.')		//collect fraction part
    while(isdigit(s[++i] = c = getch()))
      ;
  s[i] = '\0';
  if(c != EOF)
    ungetch(c);
  return NUMBER;
}

int getline(char in[])
{
  int i,c;
  for(i = 0; (c = getchar()) != '\n' && c != EOF; i++)
    in[i] = c;
  in[i] = '\0';
}
   
void print(void)
{
  if(sp > 0)
    printf("\t%.8g\n", val[sp-1]);
  else
    printf("error/print: stack empty\n");
}

void pop1(void)
{
  printf("\t%.8g\n", pop());
}

void duplicate(void)
{
  if(sp > 0) {
    val[sp] = val[sp - 1];
    sp++;
    printf("duplicate complete\n");
  } else
    printf("error/duplicate: stack empty");
}

void swap(void)
{
  double x;

  if(sp > 1) {
    x = val[sp-1];
    val[sp-1] = val[sp-2];
    val[sp-2] = x;
    printf("swap complete\n");
  } else
    printf("error/swap: less than two elements in stack");
}

void clear(void)
{
  sp = 0;
  printf("clear complete\n");
}
