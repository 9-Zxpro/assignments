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

void addNode(struct node *head, int val)
{
    struct node *ptr, *new_node = createNode(val);
    if (head == NULL)
    {
        head = new_node;
    }
    else
    {
        ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = new_node;
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

int getListLength(struct node *head)
{
    int length = 0;
    while (head != NULL)
    {
        length++;
        head = head->next;
    }
    return length;
}

struct node* intersectionNode(struct node *head1, struct node *head2)
{
    int length1 = getListLength(head1);
    int length2 = getListLength(head2);

    if (length1 > length2)
    {
        for (int i = 0; i < length1 - length2; i++)
        {
            head1 = head1->next;
        }
    }
    else if (length2 > length1)
    {
        for (int i = 0; i < length2 - length1; i++)
        {
            head2 = head2->next;
        }
    }

    // traverse both lists until the intersection node is found
    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data == head2->data)
        {
            return head1;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    return NULL;
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

    displayList(head1->next);
    printf("\n");
    displayList(head2->next);

    struct node *is = intersectionNode(head1->next, head2->next);
    if (is)
    {
        printf("\n intersection node is %d", is->data);
    }
    else
    {
        printf("\n no intersection node");
    }
    return 0;
}
