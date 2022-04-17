#include <stdlib.h>
#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
} * head;

void initialize()
{
    head = NULL;
}

void insert(int num)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = num;
    newNode->next = head;
    head = newNode;
}

int getLength(struct node *head)
{
    if (head == NULL)
    {
        cout << "\nError : Invalid node pointer !!!\n";
        return 0;
    }
    int length = 0;
    while (head != NULL)
    {
        head = head->next;
        length++;
    }
    return length;
}

struct node *getNthLastNode(struct node *head, int n)
{
    struct node *front, *back;
    int i;
    front = back = head;
    if (n > getLength(head))
    {
        cout << "\nError : n is greater than length of Linked List\n";
        return NULL;
    }
    for (i = 0; i < n - 1; i++)
    {
        front = front->next;
    }

    while (front->next != NULL)
    {
        front = front->next;
        back = back->next;
    }

    return back;
}

void printLinkedList(struct node *nodePtr)
{
    while (nodePtr != NULL)
    {
        cout << nodePtr->data << " ";
        nodePtr = nodePtr->next;
        if (nodePtr != NULL)
            cout << "-> ";
    }
}

int main()
{
    int N, k;
    struct node *NthNode;
    initialize();

    /* Creating a linked List*/
    int new_node;
    int i;
    cout << "\nEnter the total number of nodes : ";
    /* Number of nodes */
    cin >> k;
    cout << "\nEnter the data for the nodes : ";
    for (i = 0; i < k; i++)
    {
        cin >> new_node;
        insert(new_node); /* Inserting the nodes */
    }

    cout << "\nLinked List : ";
    printLinkedList(head);
    cout << "\n\nEnter value of N : ";
    cin >> N;
    NthNode = getNthLastNode(head, N);
    cout << "\nNth Last node is " << NthNode->data << endl;
    return 0;
}