#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left, *right;
};
TreeNode* f = NULL;
void inorderFind(TreeNode* root,int val){
    if(root == NULL){
        return ;
    }
    inorderFind(root->left,val);
    if(root->val == val){
        f = root;
        return;
    }
    inorderFind(root->right,val);

}
