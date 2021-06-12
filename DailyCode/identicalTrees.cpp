#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left,*right;
};
bool identicalTree(TreeNode *root1,TreeNode *root2){
    if(!root1 && !root2) return true;
    identicalTree(root1->left,root2->left);
    identicalTree(root1->right,root2->right);
    if(root1->val == root2->val){
        return true;
    }
    return false;
}
bool isSameTree(TreeNode* root1, TreeNode* root2) {
    if(!root1 && !root2) return true;
    if(root1 && root2){

        return (root1->val == root2->val) && isSameTree(root1->left,root2->left) && isSameTree(root1->right,root2->right);

    }
    return false;
}