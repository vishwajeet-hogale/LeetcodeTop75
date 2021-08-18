#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left, * right;
};
bool hasPathSum(Node *root, int S) {
    if(root==NULL)
            return S == 0;
        
    if(root->left==NULL && root->right==NULL && S-root->data==0) return true;
        
    return hasPathSum(root->left,S-root->data) || hasPathSum(root->right,S-root->data);
}