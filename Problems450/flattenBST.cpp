#include<iostream> 
#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
};

void flatten(TreeNode *root,TreeNode* prev){
    if(!root) return;
    flatten(root->left,prev);
    if(prev == NULL){
        prev = root;
    }
    else{
        prev->right = root;
        prev->left = NULL;
        prev = root;
    }
    flatten(root->right,prev);
}
