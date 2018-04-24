#include<iostream>
using namespace std;
struct Stack
{
    int top;
    unsigned capacity;
    int *arr;
};

struct Stack *createStack(unsigned capacity)
{
        struct Stack * s = new Stack();
        s->capacity = capacity;
        s->top = -1;
        s->arr = new int[sizeof(s->capacity)];
        return s;
}

int isempty(struct Stack *s)
{
    return (s->top == -1);
}

int isfull(struct Stack *s)
{
    return (s->top == s->capacity - 1);
}

void push(struct Stack *s,int item)
{
    if(isfull(s))
        return;
    s->arr[++s->top] = item;
}

int pop(struct Stack *s)
{
    if(isempty(s))
        return -32767;
    int item = s->arr[s->top--];
    return item;
}

int main()
{
    struct Stack * s = createStack(1000);
    push(s,10);
//    push(s,50);
//    push(s,20);
 //   push(s,30);
    cout<<"pop item"<<endl;
    cout<<pop(s);
    cout<<pop(s);
//    cout<<"push item"<<endl;
 //   push(s,60);
//    cout<<pop(s);
}
