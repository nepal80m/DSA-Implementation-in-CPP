#include <iostream>
#include <cstring>

using namespace std;
const int stack_size = 50;
struct Stack
{
	int items[stack_size];
	int top;
};

char infexp[50];
char postexp[50] = "";

void push(Stack &stack, char symbol)
{
	if (stack.top >= stack_size - 1)
	{
		cout << "Stack Overflow!";
		exit(0);
	}
	else
	{

		stack.top++;
		stack.items[stack.top] = symbol;
	}
}
char pop(Stack &stack)
{
	if (stack.top <= -1)
	{
		cout << "Stack Underflow!";
		exit(0);
	}
	else
	{
		char symbol;
		symbol = stack.items[stack.top];
		stack.top--;
		return symbol;
	}
}
char get_top_symbol(Stack stack)
{
	char t_symbol;
	t_symbol = stack.items[stack.top];
	return t_symbol;
}

int get_precedence(char symbol)
{
	switch (symbol)
	{
	case '+':
		return 1;
		break;
	case '-':
		return 1;
		break;
	case '*':
		return 2;
		break;
	case '/':
		return 2;
		break;
	case '$':
		return 3;
		break;
	default:
		return 0;
		break;
	}
}
void prec_wise_push(Stack &stack, char r_symbol)
{
	while (get_precedence(r_symbol) <= get_precedence(get_top_symbol(stack)))
	{
		char t_symbol = pop(stack);
		strncat(postexp, &t_symbol, 1);
	}
	push(stack, r_symbol);
}

void enclose_infix_with_par()
{
	char temp[50] = "(";
	strcat(temp, infexp);
	strcat(temp, ")");
	strcpy(infexp, temp);
}
int main()
{
	Stack stack;
	stack.top = -1;
	cout << "Enter the infix expression to be converted:";
	cin >> infexp;
	enclose_infix_with_par();

	for (int i = 0; i < strlen(infexp); i++)
	{
		char r_symbol = infexp[i];

		if (r_symbol == '+' || r_symbol == '-' || r_symbol == '*' || r_symbol == '/' || r_symbol == '$')
		{
			prec_wise_push(stack, r_symbol);
		}
		else if (r_symbol == '(')
		{
			push(stack, r_symbol);
		}
		else if (r_symbol == ')')
		{
			while (get_top_symbol(stack) != '(')
			{

				char t_symbol = pop(stack);
				strncat(postexp, &t_symbol, 1);
			}
			pop(stack);
		}
		else
		{
			strncat(postexp, &r_symbol, 1);
		}
	}

	cout << "\nThe required postfix expression is: " << postexp << endl;

	return 0;
}
