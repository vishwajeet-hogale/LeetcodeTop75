#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left,*right;
};
int sum(TreeNode *root){
    if(!root) return 0;
    return root->val + sum(root->left) + sum(root->right);
}
TreeNode totalsum = 0;
void levelup(TreeNode *root,TreeNode *par){
    if(!root) return;
    
    levelup(root->left);
   
    levelup(root->right);
    if(!par){
        
        root->val = root->val + totalsum - sum(root,par) + sum(root->right,par);
        
    }
    else if(par && par->left){

        root->val = root->val + totalsum - sum(root) + sum(root->right)-sum(par->left);
    }
    
    
} 
int main(){
    TreeNode *root = NULL;
    totalsum = sum(root->right);
    root->val = sum(root);
    levelup(root);
}