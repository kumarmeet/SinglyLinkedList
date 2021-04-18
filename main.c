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
int menu(void);
void metaData(Node*s);
void input(int*);

int main()
{
    Node *start = NULL, *p;
    int item;

    while(1)
    {
        system("cls");
        metaData(start);

        switch(menu())
        {
        case 1:
            input(&item);
            addItemAtLast(&start,item);
            break;
        case 2:
            input(&item);
            addItemAtStart(&start,item);
            break;
        case 3:
            printf("Check your item in list or not -> ");
            scanf("%d",&item);
            if(p = searchNodeItem(start,item))
            {
                input(&item);
                addItemAfterNode(p,item);
            }
            else
                printf("Item not found");
            break;
        case 4:
            deleteFirstNode(&start);
            printf("First node deleted successfully");
            break;
        case 5:
            deleteLastNode(start);
            printf("last node deleted successfully");
            break;
        case 6:
            input(&item);
            if(searchNodeItem(start,item))
                deleteNode(start,item);
            else
                printf("Item not exist");
            break;
        case 7:
            exit(0);
            break;
        default:
            printf("Enter right choice");
        }
        getch();
    }
    return 0;
}

void metaData(Node *s)
{
    int count = 0;
    Node *r;
    r=s;
    while(s)
    {
        count++;
        s = s->next;
    }
    printf("You have %d items in your list\n", count);
    printf("You have list Items? %s\n",s == NULL ? "No" : "Yes");
    viewList(r);
}

void input(int *x)
{
    printf("Enter your item -> ");
    scanf("%d",x);
}

int menu()
{
    int n;
    printf("\n1. Add node");
    printf("\n2. Add node at start");
    printf("\n3. Add node after node");
    printf("\n4. Delete first node");
    printf("\n5. Delete last node");
    printf("\n6. Delete particular node");
    printf("\n7. Exit");
    printf("\nEnter your choice -> ");
    scanf("%d",&n);
    return n;
}
