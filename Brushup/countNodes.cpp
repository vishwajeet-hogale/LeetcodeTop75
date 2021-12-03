#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left,*right;
};
int c = 0;
void countNode(TreeNode *root){
    if(!root)
        return;
    countNode(root->left);
    c++;
    countNode(root->right);


}
