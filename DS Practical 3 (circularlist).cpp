#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
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

class cll
{
    Node *head;

public:
    cll()
    {
        head = NULL;
    }
    void insertatfront(int);
    void insertafterele(int, int);
    void insertattail(int);
    void deleteathead();
    void deleteatpos(int);
    void deleteattail();
    void display();
};

void cll ::insertatfront(int x)
{
    Node *newnode = new Node(x);
    if (head == NULL)
    {
        head = newnode;
        newnode->next = newnode;
        return;
    }
    Node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->next = head;
    head = newnode;
}

void cll ::insertattail(int x)
{
    Node *newnode = new Node(x);
    if (head == NULL)
    {
        head = newnode;
        newnode->next = newnode;
        return;
    }
    Node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->next = head;
}

void cll ::insertafterele(int x, int ele)
{
    Node *temp = head;
    Node *newnode = new Node(x);
    while (temp->next != head)
    {
        if (temp->data == ele)
        {
            break;
        }
        temp = temp->next;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}

void cll ::display()
{
    if (head == NULL)
    {
        cout << "The LL is empty " << endl;
        return;
    }
    Node *temp = head;
    while (temp->next != head)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << temp->data;
}

void cll ::deleteathead()
{
    if (head->next == head)
    {
        delete head;
        return;
    }
    Node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    Node *ele = head;
    head = head->next;
    temp->next = head;
    delete ele;
}

void cll::deleteatpos(int k)
{
    if (head == NULL)
    {
        return;
    }
    if (k == 1)
    {
        Node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        Node *ele = head;
        head = head->next;
        temp->next = head;
        delete ele;
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
    temp->next = temp->next->next;
    delete ele;
}

void cll::deleteattail()
{
    if (head == NULL)
    {
        return;
    }
    Node *temp = head;
    while (temp->next->next != head)
    {
        temp = temp->next;
    }
    Node *ele = temp->next;
    temp->next = head;
    delete ele;
}

int main()
{
    cll c1;
    c1.insertatfront(5);
    c1.insertatfront(3);
    c1.insertatfront(2);
    c1.insertatfront(1);
    c1.insertafterele(4, 3);
    c1.insertattail(6);
    c1.deleteattail();
    c1.display();
    return 0;
}
