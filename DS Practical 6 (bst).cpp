#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* right = NULL;
    Node* left = NULL;

    Node() {
        data = 0;
    }
    Node(int data) {
        this->data = data;
    }
};

class Bst {
    Node* root = NULL;

public:
    Bst() {
        root = NULL;
    }

    Node* insert(Node* node, int data) {
        if (node == NULL) {
            return new Node(data);
        }
        if (data < node->data) {
            node->left = insert(node->left, data);
        } else {
            node->right = insert(node->right, data);
        }
        return node;
    }

    Node* search(Node* root, int s) {
        if (root == NULL || root->data == s) {
            return root;
        }
        if (s < root->data) {
            return search(root->left, s);
        }
        return search(root->right, s);
    }

    Node* deleteNode(Node* root, int key) {
        if (root == NULL) {
            return root;
        }
        if (key < root->data) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->data) {
            root->right = deleteNode(root->right, key);
        } else {
            if (root->left == NULL) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == NULL) {
                Node* temp = root->left;
                delete root;
                return temp;
            }
            Node* temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
        return root;
    }

    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current && current->left != NULL) {
            current = current->left;
        }
        return current;
    }

    void insert(int data) {
        root = insert(root, data);
    }

    void search(int data) {
        Node* result = search(root, data);
        if (result) {
            cout << "Found: " << result->data << endl;
        } else {
            cout << "Not Found" << endl;
        }
    }

    void deleteNode(int key) {
        root = deleteNode(root, key);
    }

    void inorder(Node* root) {
        if (root == NULL) {
            return;
        }
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

    void preorder(Node* root) {
        if (root == NULL) {
            return;
        }
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }

    void postorder(Node* root) {
        if (root == NULL) {
            return;
        }
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }

    void inorder() {
        cout << "Inorder: ";
        inorder(root);
        cout << endl;
    }

    void preorder() {
        cout << "Preorder: ";
        preorder(root);
        cout << endl;
    }

    void postorder() {
        cout << "Postorder: ";
        postorder(root);
        cout << endl;
    }
};

int main() {
    Bst tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(20);
    tree.insert(40);
    tree.insert(70);
    tree.insert(60);
    tree.insert(80);

    tree.inorder();
    tree.preorder();
    tree.postorder();

    tree.search(50);

    tree.deleteNode(50);
    cout << "After deleting 50:" << endl;
    tree.inorder();

    return 0;
}
