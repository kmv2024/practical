#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node() : data(0), next(NULL) {}
    Node(int data) : data(data), next(NULL) {}
};

class Llstack {
    Node* head;    
    int el;

public:
    Llstack() : head(NULL), el(0) {}

    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
        return;
    }

    void push(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
        el++;
    }

    void pop() {
        if (head == NULL) return; 
        Node* temp = head;
        head = head->next;
        delete temp;
        el--;
    }

    bool isempty() {
        return el == 0;
    }

    int top() {
        if (head != NULL) {
            return head->data;
        }
        return -1; 
    }

    int postfix(string d) {
    for (int i = 0; i < d.length(); i++) {
        char c = d[i];
        if (isdigit(c)) { 
            push(c - '0'); 
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            if (isempty()) return -1; 
            int n2 = top();
            pop();
            if (isempty()) return -1; 
            int n1 = top();
            pop();

            int result;
            if (c == '+') {
                result = n1 + n2;
            } else if (c == '-') {
                result = n1 - n2;
            } else if (c == '*') {
                result = n1 * n2;
            } else if (c == '/') {
                if (n2 == 0) {
                    cout << "Division by zero" << endl;
                    return 0; 
                }
                result = n1 / n2;
            }
            push(result);
        }
    }
    display();
    return top(); 
}
};

int main() {
    Llstack s;
    s.postfix("43+");
   
}

