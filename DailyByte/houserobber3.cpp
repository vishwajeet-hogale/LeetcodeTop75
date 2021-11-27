#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left,*right;
};
int rob(TreeNode *root){
    if(!root) return;
    int val = 0;
    if(root->left){
        val += rob(root->left->left) + rob(root->left->right);
    }
    if(root->right){
        val += rob(root->right->left) + rob(root->right->right);
    }
    return max(root->val + val,rob(root->left) + rob(root->right));
}