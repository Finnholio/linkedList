#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

//make the node for linked list
typedef struct node
{
    int value;
    struct node * next;
} node;

//functions
node * createLinkedList(int n);
void print(node * head);
void deleteNode(node * deleteMe, node * head);

int main()
{
    //setup varriables
    int n = 0;
    node * HEAD = NULL;
    n = get_int("HOW MANY NODES????????? : ");

    //make the linked list by asking the user for inputs
    HEAD = createLinkedList(n);

    //print the linked list starting at the HEAD
    print(HEAD);

    //delete the node after the HEAD
    node * toBeDeleted = HEAD->next;
    deleteNode(toBeDeleted, HEAD);

    //print the linked list again
    print(HEAD);
}

node * createLinkedList(int n)
{
    //define varriables
    node * head = NULL;
    node * temp = NULL;
    node * p = NULL;

    for (int i = 0; i < n; i++)
    {
        //define variables
        temp = (node*)malloc(sizeof(node));
        temp->value = get_int("WHAT IS THIS NODE?!!!!? : ");
        temp->next = NULL;

        //if the head doesn't exist, make the next value the head
        if (head == NULL)
        {
            head = temp;
        }
        else
        {
            //if the head does exist, define the next variable
            p = head;
            while (p->next != NULL)
            {
                p = p->next;
            }
            p->next = temp;
        }
    }

    //return the head
    return head;
}

void print(node * head)
{
    //define variables
    node * p = NULL;
    p = head;

    while (p != NULL)
    {
        //for each variable in the list, print it and then use next to find the next variable
        printf("%i", p->value);
        if (p->next != NULL)
        {
            printf(", ");
        }
        p = p->next;
    }
    printf("\n");
}

void deleteNode(node * deleteMe, node * head)
{
    //define the variables
    node * p = NULL;
    p = head;

    //delete the head if ya need to
    if (head == deleteMe)
    {
        free(head);
        return;
    }

    //for each link in the list...
    while (p->next != NULL)
    {
        //if the links next link is the one to be deleted
        if (p->next == deleteMe)
        {
            //delete it and connect the gaps
            node * temp = p->next;
            p->next = temp->next;
            free(temp);
            return;
        }
        p = p->next;
    }

    //if the last link needs to be deleted, delete it
    if (p == deleteMe)
    {
        free(p);
        return;
    }
}
