#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _node
{
    int data;
    struct _node *next;
} node;

typedef struct _queue
{
    node *front;
    node *back;
} queue;

queue *queueInit()
{
    queue *q = (queue*) malloc(sizeof(queue));
    if(q == NULL)
        return NULL;
    q->front = NULL;
    q->back = NULL;
    return q;
}

int queueEmpty(queue *q)
{
    return q->front == NULL;
}

void enqueue(queue *q, int x)
{
    node *newnode = (node*)malloc(sizeof(node));
    newnode->data = x;
    newnode->next = NULL;
    if(q->front == NULL && q->back == NULL)
    {
        q->front = newnode;
        q->back = newnode;
    }
    else
    {
        q->back->next = newnode;
        q->back = newnode;
    }
}

int dequeue(queue *q)
{
    if(queueEmpty(q))
        return 0;
    node *tempnode;
    int x;
    if(q->front == q->back)
    {
        tempnode = q->front;
        q->front = NULL;
        q->back = NULL;
        x = tempnode->data;
        free(tempnode);
        return x;
    }
    else
    {
        tempnode = q->front;
        q->front = q->front->next;
        x = tempnode->data;
        free(tempnode);
        return x;
    }
}

int main()
{
    queue *q = queueInit();
    enqueue(q,10);
    enqueue(q,30);
    enqueue(q,40);
    while(!queueEmpty(q))
        printf("%d\n",dequeue(q));

    printf("\n-----------------------------\n");
    return 0;
}
