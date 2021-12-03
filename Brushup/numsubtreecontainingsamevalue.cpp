#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
    int data;
    TreeNode *left,*right;
}
int getNodes(TreeNode *root,int count){
    if(!root)
        return 1;
    int l = getNodes(root->left,count);
    int r = getNodes(root->right,count);
    if(!l || !r)
        return 0;
    if(root->left && root->data != root->left->data)
        return 0;
    if(root->right && root->data != root->right->data)
        return 0;
    count++;
    return 1;
}