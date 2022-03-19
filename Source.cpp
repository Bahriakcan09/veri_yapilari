#include <iostream>
#include <stdlib.h>

using namespace std;

struct stack
{
	int* data;
	int head;
	int capacity;
};

typedef struct stack Stack;

void create(Stack& stack, int size)
{
	stack.head = 0;
	stack.capacity = size;
	stack.data = (int*)calloc(size, sizeof(int));
}

void print(Stack &stack)
{
	
	for (int i = 0; i < stack.capacity; i++)
	{

		if (i == stack.head)
		{
			cout << "| " << stack.data[i] << " | <--- head" << endl;;
		}
		else
		{
			cout << "| " << stack.data[i] << " |" << endl;
		}
	}
}

void push(Stack &stack,int a)
{
	stack.data[stack.head] = a;
	stack.head++;

	if(stack.capacity==stack.head)
	{
		cout << "\n doldu \n" << endl;

		int s = stack.capacity * (1 / 2);
		stack.capacity = s;
		stack.data = (int*)realloc(stack.data,stack.capacity);
	}
}

void pop(Stack& stack)
{
	stack.data[stack.head - 1] = 0;
	stack.head--;
}

void reverse(Stack &stack1,Stack &stack2)
{
	for (int i = stack1.capacity-1;i>=0; i--)
	{
		push(stack2, stack1.data[i]);
	}
}


void main()
{
	Stack stack1,stack2;

	create(stack1, 6);

	create(stack2, 6);

	cout << "stack olusturuldu \n " << endl;

	push(stack1, 10);
	
	push(stack1, 20);

	push(stack1, 30);

	push(stack1, 40);
	
	push(stack1, 50);

	print(stack1);

	cout << "\n push kullaniildi \n " << endl;

	pop(stack1);
	
	print(stack1);
	
	cout << "\n pop kullaniildi \n " << endl;

	reverse(stack1,stack2);

	print(stack2);

	cout << "\n reverse kullaniildi \n " << endl;
}