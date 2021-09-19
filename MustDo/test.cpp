#include <iostream>
using namespace std;
 
struct Node {
    int key;
    Node *left, *right;
};
 
/* utility that allocates a new Node
with the given key */
Node* newNode(int key)
{
    Node* node = new Node;
    node->key = key;
    node->left = node->right = NULL;
    return (node);
}
 
// Function to convert binary tree into
// linked list
Node *head = NULL;
void helper(Node* root){
    if(!root) return;
    helper(root->left);
    // if(root->left || root->right){
        Node* temp = root->right; //4
        root->right = root->left; // 3
        root->left = NULL; 
        while(root->right!=NULL){
            root = root->right;
        }
        root->right = temp;
    // }
    helper(root->right);
}
void flatten(struct Node* root)
{
    Node* head = root;
    helper(root);
 
}
 
// To find the inorder traversal
void inorder(struct Node* root)
{
    // base condition
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->key << " ";
    inorder(root->right);
}
 
/* Driver program to test above functions*/
int main()
{
    /* 1
        / \
    2     5
    / \     \
    3 4     6 */
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(5);
    root->left->left = newNode(3);
    root->left->right = newNode(4);
    root->right->right = newNode(6);
 
    helper(root);
 
    cout << "The Inorder traversal after "
            "flattening binary tree ";
    inorder(head);
    return 0;
}
