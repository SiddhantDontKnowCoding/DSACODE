#include<iostream>
#include<stack>
using namespace std;

class Node {
public:
    char data;
    Node* left, * right;

    Node(char value) {
        data = value;
        left = right = nullptr;
    }
};

class Tree {
public:
    void createTree(string exp, Node*& root);
    void traverse(Node* root);
    void deleteTree(Node* root);
};

class stack1 {
public:
    Node* data[30];
    int top;

    stack1() { top = -1; }

    bool empty() {
        return (top == -1);
    }

    void push(Node* p) {
        data[++top] = p;
    }

    Node* pop() {
        return (empty() ? nullptr : data[top--]);
    }
};

void Tree::createTree(string s, Node*& root) {
    int l = s.length();
    Node* temp;
    stack1 stack;
    
    for (int i = l - 1; i >= 0; i--) {
        if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '^') {
            
            temp = new Node(s[i]);
            Node* x = stack.pop();  // Pop two operands
            Node* y = stack.pop();
            temp->left = y;  // Left child
            temp->right = x;  // Right child
            stack.push(temp);  // Push the operator node back to stack
        }
        else {
            // It's an operand
            temp = new Node(s[i]);  // Create operand node
            stack.push(temp);  // Push operand node to stack
        }
    }

    // After processing the entire string, the root of the tree is the only remaining element in the stack
    root = stack.pop();
}

void Tree::traverse(Node* root) {
    if (!root) {
        return;
    }

    stack1 s1, s2;
    Node* temp = root;

    cout << "\nPost-order Traversal: ";

    s1.push(temp);
    while (!s1.empty()) {
        temp = s1.pop();
        s2.push(temp);

        // Push left and right children to the first stack
        if (temp->left) {
            s1.push(temp->left);
        }
        if (temp->right) {
            s1.push(temp->right);
        }
    }

    // Pop all nodes from stack2 for post-order result
    while (!s2.empty()) {
        temp = s2.pop();
        cout << temp->data << " ";
    }
    cout << endl;
}

void Tree::deleteTree(Node* root) {
    if (!root) {
        return;
    }

    // Recursively delete left and right subtrees
    deleteTree(root->left);
    deleteTree(root->right);

    cout << "Deleting node: " << root->data << endl;
    delete root;  // Deallocate memory of the current node
    root = nullptr;
}

int main() {
    string str;
    cout << "Enter the Prefix Expression: ";
    cin >> str;

    Tree tree;
    Node* root = nullptr;

    tree.createTree(str, root);  // Construct the expression tree
    tree.traverse(root);  // Perform post-order traversal
    tree.deleteTree(root);  // Delete the entire tree

    return 0;
}
