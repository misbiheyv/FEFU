#include <fstream>
#include <iostream>
#include <string>

using namespace std;

ofstream fout("output.txt");

struct Stack
{
    string value;
    Stack *next;
    Stack *head;
};

bool empty(Stack *s)
{
    if (s->head == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void add(string val, Stack *&s)
{
    Stack *tempStack = new Stack;
    tempStack->value = val;
    tempStack->next = s->head;
    s->head = tempStack;
}

void pop(Stack *s)
{
    if (s->head == NULL)
    {
        fout << "ERROR";
        exit(0);
    };
    Stack *tempStack = s->head->next;
    delete s->head;
    s->head = tempStack;
}

void print(Stack *s)
{

    Stack *tempStack = s->head;

    if (empty(s))
    {
        return;
    };

    string x = s->head->value;

    pop(s);

    print(s);

    fout << x << " ";

    add(x, s);
};

int main()
{
    Stack *stack = new Stack;

    stack->head = NULL;

    fstream file("input.txt");
    string x;

    while (file >> x)
    {
        x[0] == '+' ? add(x.substr(1), stack) : pop(stack);
    }

    if (empty(stack))
    {
        fout << "EMPTY";
    }
    else
    {
        print(stack);
    }

    return 0;
}
