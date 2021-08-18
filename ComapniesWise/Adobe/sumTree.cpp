#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node* left, * right;
};
int sum(Node *root)
{
    if (root == NULL)
        return 0;
     
    return sum(root->left) + root->data +
           sum(root->right);
}
bool isSumTree(Node* root){
    int ls,rs;
    if(!root) return true;
    if(!root->left && !root->right)
        return true;
    ls = sum(root->left);
    rs = sum(root->right);
    if((root->data == ls + rs) && isSumTree(root->left) && isSumTree(root->right))
        return 1;
    return 0;    
}