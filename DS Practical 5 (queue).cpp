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

class queuee
{
    Node *front;
    Node *rear;
    int size = 0;

public:
    queuee()
    {
        front = rear = NULL;
    }
    void enqueue(int x)
    {
        Node *newNode = new Node(x);
        if (front == NULL)
        {
            front = rear = newNode;
            size++;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
            size++;
        }
    }
    void dequeue()
    {
        if (size == 0)
        {
            cout << "Can not dequeue queue is empty" << "\n";
            return;
        }
        Node *ele = front;
        if (front->next)
        {
            front = front->next;
        }
        delete ele;
        size--;
    }
    void display()
    {
        Node *temp = front;
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};

int main()
{
    queuee q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.dequeue();
    q.display();
}
