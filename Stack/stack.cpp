#include <iostream>
using namespace std;

const int stack_size = 5;
struct Stack
{
	int items[stack_size];
	int top;
};

void push(Stack &stack)
{
	if (stack.top >= stack_size - 1)
	{
		cout << "Stack Overflow!";
	}
	else
	{
		cout << "Enter a number:";
		int num;
		cin >> num;
		stack.top++;
		stack.items[stack.top] = num;
		cout << num << " was added to the stack";
	}
}

void pop(Stack &stack)
{
	if (stack.top <= -1)
	{
		cout << "Stack Underflow!";
	}
	else
	{
		int num;
		num = stack.items[stack.top];
		stack.top--;
		cout << num << " was popped out of stack";
	}
}
void display(Stack stack)
{
	if (stack.top == -1)
	{
		cout << "The stack is empty.";
	}
	else
	{
		cout << "The stack is:\n";
		for (int i = stack.top; i >= 0; i--)
		{
			cout << stack.items[i] << endl;
		}
	}
}

int main()
{
	Stack stack;
	stack.top = -1;
	int menu;
	cout << "Select an option:";
	cout << "\n1. Push";
	cout << "\n2. Pop";
	cout << "\n3. Display";
	cout << "\n4. Exit";
	while (1)
	{
		cout << "\n Choice:";
		cin >> menu;
		switch (menu)
		{
		case 1:
			push(stack);
			break;
		case 2:
			pop(stack);
			break;
		case 3:
			display(stack);
			break;
		case 4:
			return 0;
			break;

		default:
			cout << "Wrong choice.";
			break;
		}
	}
	return 0;
}
