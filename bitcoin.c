#include<stdio.h>
#include<stdlib.h>

typedef struct StackNode
{
    int data;
    struct Stacknode *next;
} stackNode;

typedef struct Stack
{
    stackNode *top;
} stack;

stack *stackInit()
{
    stack *s = (stack*) malloc(sizeof(stack));
    if(s == NULL)
        return NULL;
    s->top = NULL;
    return s;
}

void stackPush(stack *s, int data)
{
    stackNode *newnode = (stackNode*) malloc(sizeof(stackNode));
    if(newnode == NULL)
        return NULL;
    newnode->data = data;
    newnode->next = s->top;
    s->top = newnode;
}

int stackEmty(stack *s)
{
    return (s->top == NULL);
}

int stackPop(stack *s)
{
    if(stackEmty(s))
        return NULL;
    int data = s->top->data;
    stackNode *node = s->top;
    s->top = s->top->next;
    free(node);
    return data;
}

void stackPrint(const stack *s)
{
    if(stackEmty(s))
    {
        printf("DS rong");
        return 0;
    }
    else
    {
        stackNode *node = s->top;
        do
        {
            printf("%3d",node->data);
            node = node->next;
        } while(!(node == NULL));
    }
}

void bitcoin(stack *s,int *a,int n)
{
    int d[7] = {};
    int i;
    for(i=0;i<n;i++)
    {
        while(!stackEmty(s) && a[i]>a[s->top->data])
            {
                d[s->top->data] = i - s->top->data;
                stackPop(s);
            }
        stackPush(s,i);
    }
    printkq(d,n);
}

void printkq(int *d,int n)
{
    printf("\n");
    int i;
    for(i=0;i<n;i++)
        if(d[i] == 0)
            printf("FAIL ");
        else
            printf("%d ",d[i]);
}

int main()
{
    stack *s = stackInit();
    int a[7] = {73,74,75,71,70,76,72};
    int n = sizeof(a)/sizeof(int);
    bitcoin(s,a,n);

    printf("\n-----------------------------\n");
    return 0;
}
