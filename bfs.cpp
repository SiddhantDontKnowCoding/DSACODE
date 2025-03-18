#include<iostream>
#include<queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

void bfsTraversal(Node* root) {
    if (root == NULL) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        cout << current->data << " "; 
        if (current->left != NULL) {
            q.push(current->left);
        }
        if (current->right != NULL) {
            q.push(current->right);
        }
    }
}

int main() {
    queue<Node*> q;
    int r;
    cout << "Enter the root element: ";
    cin >> r;
    
    Node* root = new Node(r);
    q.push(root);
    
    while (!q.empty()) {
        Node* current = q.front();
        q.pop();
        
        int leftChild, rightChild;
        
        cout << "Enter the left child of " << current->data<<endl ;
        cin >> leftChild;
        current->left = new Node(leftChild);
        q.push(current->left);
        
        cout << "Enter the right child of " << current->data <<endl;
        cin >> rightChild;
        current->right = new Node(rightChild);
        q.push(current->right);
        
    }

    //BSF traversal of tree using queue
    bfsTraversal(root);
    
    
    return 0;
}
