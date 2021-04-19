#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int item;
    struct Node *next;
} Node;

Node* searchNodeItem(Node*, int);
void viewList(Node*);
void addItemAtLast(Node**, int);
void addItemAtStart(Node**, int);
void addItemAfterNode(Node*, int);
void deleteFirstNode(Node**);
void deleteLastNode(Node*);
void deleteNode(Node*, int);

Node* searchNodeItem(Node *s, int item)
{
    while(s)
    {
        if(s->item == item)
            return s;
        s = s->next;
    }
    return NULL;
}

void deleteNode(Node *s, int item)
{
    Node *t, *r;
    r = s;
    t = r = *s;

    if(r->item == item)
        *s = r->next;
    
    while(r->item != item)
    {
        t = r;
        r = r->next;
    }
    t->next = r->next;
}

void deleteLastNode(Node *s)
{
    Node *temp, *t;
    temp = t = s;

    while(temp->next != NULL)
    {
        t=temp;
        temp = temp->next;
    }
    if(temp == s)
        s=NULL;
    else
        t->next = NULL;

    free(temp);
}

void deleteFirstNode(Node **s)
{
    Node *temp;
    if(*s == NULL)
        printf("List is empty");
    else
    {
        temp = *s;
        *s = temp->next;
        free(temp);
    }
}

void addItemAfterNode(Node *t, int item)
{
    Node *n;
    int i;
    n = (Node*)malloc(sizeof(Node));
    n->item = item;
    n->next = t->next;
    t->next = n;
}

void addItemAtStart(Node **s, int item)
{
    Node *n;
    n = (Node*)malloc(sizeof(Node));
    n->item = item;
    n->next = *s;
    *s = n;
}

void addItemAtLast(Node **s, int item)
{
    Node *temp, *t;
    temp = (Node*)malloc(sizeof(Node));
    temp->item = item;
    temp->next = NULL;

    if(*s == NULL)
        *s = temp;
    else
    {
        t = *s;
        while(t->next != NULL)
            t = t->next;
        t->next = temp;
    }
}

void viewList(Node *s)
{
    while(s)
    {
        printf("%d ",s->item);
        s = s->next;
    }
}
