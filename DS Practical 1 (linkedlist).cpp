#include <iostream>
using namespace std;

class Node
{
public:
    Node *next;
    int data;
    Node()
    {
        data = 0;
        next = NULL;
    }
    Node(int data1)
    {
        data = data1;
        next = NULL;
    }
};

class linkedlist
{
    Node *head;

public:
    linkedlist()
    {
        head = NULL;
    }
    void insertathead(int);
    void insertattail(int);
    void insertbeforepos(int, int);
    void insertafterpos(int, int);
    void deleteathead();
    void deleteatpos(int);
    void print();
};

void linkedlist ::insertathead(int x)
{
    Node *newnode = new Node(x);
    if (head == NULL)
    {
        head = newnode;
        return;
    }
    newnode->next = head;
    head = newnode;
}

void linkedlist ::insertattail(int x)
{
    Node *newnode = new Node(x);
    if (head == NULL)
    {
        head = newnode;
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
}

void linkedlist ::insertbeforepos(int x, int k)
{
    Node *newnode = new Node(x);
    if (head == NULL)
    {
        if (k == 0)
        {
            head = newnode;
            return;
        }
        else
        {
            cout << "Cannot add to the given position " << endl;
            return;
        }
    }
    Node *temp = head;
    int s = 0;
    while (temp)
    {
        s++;
        if (s == k - 1)
        {
            break;
        }
        temp = temp->next;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}

void linkedlist ::insertafterpos(int x, int k)
{
    Node *newnode = new Node(x);
    if (head == NULL)
    {
        if (k == 0)
        {
            head = newnode;
            return;
        }
        else
        {
            cout << "Cannot add to the given position " << endl;
            return;
        }
    }
    Node *temp = head;
    int s = 0;
    while (temp)
    {
        s++;
        if (s == k)
        {
            break;
        }
        temp = temp->next;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}

void linkedlist ::deleteathead()
{
    if (head == NULL)
    {
        return;
    }
    if (head->next == NULL)
    {
        delete head;
        return;
    }
    Node *temp = head;
    head = head->next;
    delete temp;
}

void linkedlist ::deleteatpos(int k)
{
    if (head == NULL)
    {
        return;
    }
    if (k == 0)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Node *temp = head;
    int x = 0;
    while (temp)
    {
        x++;
        if (x == k - 1)
        {
            break;
        }
        temp = temp->next;
    }
    Node *ele = temp->next;
    temp->next = temp->next->next;
    delete ele;
}

void linkedlist ::print()
{
    Node *temp = head;
    if (head == NULL)
    {
        cout << "The Linked List is empty" << endl;
        return;
    }
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    linkedlist l1;
    l1.insertathead(10);
    l1.insertathead(20);
    l1.insertathead(30);
    l1.print();
    l1.insertattail(40);
    l1.insertattail(50);
    l1.print();
    l1.insertbeforepos(70, 2);
    l1.insertafterpos(100, 3);
    l1.print();
    l1.deleteatpos(2);
    l1.deleteathead();
    l1.print();
    return 0;
}
