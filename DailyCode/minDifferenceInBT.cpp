#include<iostream>
#include<bits/stdc++.h>
#include<math.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left,*right;
};
TreeNode *p = NULL;int m = INT_MAX;
void inorder(TreeNode *root){
    if(!root) return;
    inorder(root->left);
    if(p == NULL)
        p = root;
    else{
        int diff = abs(root->val - p->val);
        if(m < diff)
            diff = m;
    }
    inorder(root->right);
    
}