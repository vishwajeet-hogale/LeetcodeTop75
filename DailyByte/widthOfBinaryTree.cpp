#include<bits/stdc++.h>
#include<iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left,*right;
};
int diam = 0;
int width(TreeNode *root){
    if(!root) return 0;
    int l = width(root->left);
    int r = width(root->right);
    int dia = max(dia,l+r);
    int ans = max(dia,1+l+r);
    diam = max(diam,ans);
    return dia;
}