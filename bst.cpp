#include<iostream>
using namespace std;

struct node{
    int data;
    node *left, *right;
} *root;

class bst{
public:
    bst(){
        root = NULL;  // Initialize root to NULL
    }
    
    void create(int value);
    void insert(node *p, int value);
    void search(node *p, int key);
    void traverse(node *p);
    void min_element(node *p);
    void max_element(node *p);
};

void bst::create(int value){
    if(root == NULL){
        root = new node();
        root->data = value;
        root->left = root->right = NULL;
        cout << "Root created successfully" << endl;
    }
}

void bst::insert(node *p, int value){
    if(root == NULL){
        return create(value);
    }
    else{
        node *temp = new node();  // Initialize temp correctly
        temp->data = value;
        temp->left = temp->right = NULL;

        if(temp->data <= p->data){
            if(p->left == NULL){
                p->left = temp;
            }
            else{
                node *temp1 = p->left;
                while(temp1->left != NULL ){
                    temp1 = temp1->left;
                }
                temp1->left = temp;
            }
            cout << "Left node " << value << " created successfully" << endl;
        }
        else{
            if(p->right == NULL){
                p->right = temp;
            }
            else{
                node *temp1 = p->right;
                while(temp1->right != NULL ){
                    temp1 = temp1->right;
                }
                temp1->right = temp;
            }
            cout << "Right node " << value << " created successfully" << endl;
        }
    }
}

void bst::search(node *p, int key){
    if(p == NULL){
        cout << "Tree is empty" << endl;
        return;
    }

    if(p->data == key){
        cout << "Key is found" << endl;
        return;
    }
    else if(key < p->data){
        search(p->left, key);  // Search recursively in the left subtree
    }
    else{
        search(p->right, key);  // Search recursively in the right subtree
    }
}

void bst::traverse(node *p){
    if(p == NULL){
        return;
    }
    traverse(p->left);
    cout << p->data << " ";  // Print node data during traversal
    traverse(p->right);
}

int main(){
    cout << "Enter the elements of a tree:" << endl;
    bst b;
    b.create(20);  // Create the root node with value 20
    b.insert(root, 10);  // Insert 10
    b.insert(root, 30);  // Insert 30
    b.insert(root, 56);  // Insert 56
    b.search(root, 56);  // Search for key 56
    cout << "In-order Traversal of the tree: ";
    b.traverse(root);  // Perform in-order traversal
    cout << endl;
    return 0;
}
