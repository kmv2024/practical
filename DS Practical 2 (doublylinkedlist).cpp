#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node()
    {
        data = 0;
        next = NULL;
    }
    Node(int data1)
    {
        data = data1;
        next = NULL;
        prev = NULL;
    }
};

class dll
{
    Node *head;

public:
    dll()
    {
        head = NULL;
    }
    void insertathead(int);
    void insertafterpos(int, int);
    void insertbeforepos(int, int);
    void insertattail(int);
    void deleteathead();
    void deleteatpos(int);
    Node *search(int);
    void display();
};

void dll ::insertathead(int x)
{
    Node *newnode = new Node(x);
    if (head == NULL)
    {
        head = newnode;
        return;
    }
    Node *temp = head;
    newnode->next = head;
    head->prev = newnode;
    head = newnode;
}

void dll ::insertattail(int x)
{
    Node *newnode = new Node(x);
    if (head == NULL)
    {
        head = newnode;
        return;
    }
    Node *temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->prev = temp;
}

void dll ::insertafterpos(int x, int k)
{
    Node *temp = head;
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
    int count = 0;
    while (temp)
    {
        count++;
        if (count == k)
        {
            break;
        }
        temp = temp->next;
    }
    temp->next->prev = newnode;
    newnode->next = temp->next;
    newnode->prev = temp;
    temp->next = newnode;
}

void dll ::insertbeforepos(int x, int k)
{
    Node *temp = head;
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
    int count = 0;
    while (temp)
    {
        count++;
        if (count == k - 1)
        {
            break;
        }
        temp = temp->next;
    }
    temp->next->prev = newnode;
    newnode->next = temp->next;
    newnode->prev = temp;
    temp->next = newnode;
}

void dll ::display()
{
    if (head == NULL)
    {
        cout << "The LL is empty " << endl;
        return;
    }
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

void dll ::deleteathead()
{
    if (head == NULL)
    {
        return;
    }
    Node *temp = head;
    head = head->next;
    head->prev = NULL;
    delete temp;
}

void dll::deleteatpos(int k)
{
    if (head == NULL)
    {
        return;
    }
    if (k == 1)
    {
        Node *temp = head;
        head = head->next;
        head->prev = NULL;
        delete temp;
    }
    int x = 0;
    Node *temp = head;
    while (temp->next != head)
    {
        x++;
        if (x == k - 1)
        {
            break;
        }
        temp = temp->next;
    }
    Node *ele = temp->next;
    temp->next = ele->next;
    ele->next->prev = temp;
    delete ele;
}

Node *dll ::search(int x)
{
    if (head == NULL)
    {
        return head;
    }
    Node *temp = head;
    while (temp)
    {
        if (temp->data == x)
        {
            cout << "Element Found" << endl;
            return temp;
        }
        temp = temp->next;
    }
    cout << "Element not found" << endl;
}

int main()
{
    dll d1;
    d1.insertattail(1);
    d1.insertattail(3);
    d1.insertattail(5);
    d1.insertattail(6);
    d1.insertattail(7);
    d1.insertbeforepos(2, 2);
    d1.insertafterpos(4, 3);
    d1.deleteathead();
    d1.deleteatpos(3);
    d1.display();
    return 0;
}
