#include <stdio.h>
#include <stdlib.h>

// define a node structure for the linked list
struct Node {
    int data;
    struct Node* next;
};

// declare head1 and head2 as global variables
struct Node* head1 = NULL;
struct Node* head2 = NULL;

// function to create a new node with the given data value
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// function to add a node to the beginning of a linked list
void addToLinkedList(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = head->next;
    head->next = newNode;
}

// function to print a linked list
void printLinkedList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    int n1, n2, data;

    // get input from user to create first linked list
    printf("Enter the number of elements for the first linked list: ");
    scanf("%d", &n1);
    head1 = createNode(0);
    printf("Enter %d elements for the first linked list:\n", n1);
    for (int i = 0; i < n1; i++) {
        scanf("%d", &data);
        addToLinkedList(head1, data);
    }
    printf("The first linked list is: ");
    printLinkedList(head1->next);

    // get input from user to create second linked list
    printf("Enter the number of elements for the second linked list: ");
    scanf("%d", &n2);
    head2 = createNode(0);
    printf("Enter %d elements for the second linked list:\n", n2);
    for (int i = 0; i < n2; i++) {
        scanf("%d", &data);
        addToLinkedList(head2, data);
    }
    printf("The second linked list is: ");
    printLinkedList(head2->next);

    return 0;
}




// second 
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head1 = NULL;
struct node *head2 = NULL;

struct node *createNode(int value)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void addNode(struct node* head,int val)
{
    struct node *prePtr, *ptr, *new_node = createNode(val);
    if (head == NULL)
    {
        head = new_node;
    }
    else
    {
        ptr = prePtr = head;
        while (ptr != NULL)
        {
            prePtr = ptr;
            ptr = ptr->next;
        }
        prePtr->next = new_node;

    }
}

void displayList(struct node *head)
{
    struct node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d  ", ptr->data);
        ptr = ptr->next;
    }
}

int main()
{
    int n, l1, l2, tmp;
    printf("Enter number of item in list L1 and L2 : ");
    scanf("%d %d", &l1, &l2);
    printf("Enter l1 elements : ");
    head1 = createNode(0);
    for (int i = 0; i < l1; i++)
    {
        scanf("%d", &n);
        addNode(head1, n);
    }
    printf("\nEnter l2 elements : ");
    head2 = createNode(0);
    for (int i = 0; i < l2; i++)
    {
        scanf("%d", &n);
        addNode(head2, n);
    }

    displayList(head1);
    displayList(head2);

    return 0;
}
