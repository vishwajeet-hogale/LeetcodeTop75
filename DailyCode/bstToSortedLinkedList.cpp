#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left,*right;
};
TreeNode *head = NULL; 
TreeNode *p = NULL;
void flattenTree(TreeNode *root){
    if(!root) return;
    flattenTree(root->left);
    if(p == NULL)
        head = root;
    else{
        root->left = p;
        p->right = root;
        p = root;
    }
    flattenTree(root->right);
}