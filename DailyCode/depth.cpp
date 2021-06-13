#include<iostream>
#include<bits/stdc++.h>
#include<math.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left,*right;
};
int depth(TreeNode* root){
    if(!root) return 0;
    return max(depth(root->left),depth(root->right)) + 1;
}