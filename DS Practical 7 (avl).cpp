#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    int height;

    Node(int value) : data(value), left(NULL), right(NULL), height(1) {}
};

class AVLTree {
private:
    Node* root;

    int height(Node* node) {
        return node ? node->height : 0;
    }

    int getBalance(Node* node) {
        return node ? height(node->left) - height(node->right) : 0;
    }

    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;
        x->right = y;
        y->left = T2;
        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;
        return x;
    }

    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;
        y->left = x;
        x->right = T2;
        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;
        return y;
    }

    Node* balance(Node* node, int key) {
        int balanceFactor = getBalance(node);
        if (balanceFactor > 1 && key < node->left->data) {
            return rightRotate(node);
        }
        if (balanceFactor < -1 && key > node->right->data) {
            return leftRotate(node);
        }
        if (balanceFactor > 1 && key > node->left->data) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        if (balanceFactor < -1 && key < node->right->data) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
        return node;
    }

    Node* insert(Node* node, int key) {
        if (node == NULL) {
            return new Node(key);
        }
        if (key < node->data) {
            node->left = insert(node->left, key);
        } else if (key > node->data) {
            node->right = insert(node->right, key);
        } else {
            return node;
        }
        node->height = 1 + max(height(node->left), height(node->right));
        return balance(node, key);
    }

    Node* search(Node* node, int key) {
        if (node == NULL || node->data == key) {
            return node;
        }
        if (key < node->data) {
            return search(node->left, key);
        }
        return search(node->right, key);
    }

    void inorder(Node* root) {
        if (root == NULL) {
            return;
        }
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

public:
    AVLTree() : root(NULL) {}

    void insert(int key) {
        root = insert(root, key);
        cout << "Inserted " << key << " into the AVL tree.\n";
    }

    bool searchElement(int key) {
        Node* result = search(root, key);
        if (result != NULL) {
            cout << key << " found in the AVL tree.\n";
            return true;
        } else {
            cout << key << " not found in the AVL tree.\n";
            return false;
        }
    }

    void inorder() {
        cout << "Inorder: ";
        inorder(root);
        cout << endl;
    }
};

int main() {
    AVLTree tree;
    tree.insert(30);
    tree.insert(20);
    tree.insert(10);
    tree.insert(25);
    tree.insert(40);
    tree.insert(50);
    tree.inorder();
    tree.searchElement(25);
    tree.searchElement(100);
    return 0;
}
