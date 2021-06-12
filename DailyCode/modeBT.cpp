#include<iostream>
#include<bits/stdc++.h>
#include<math.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left,*right;
};
map<int,int> m;
int j = INT_MIN;int val = 0;
void mode(TreeNode *root){
    if(!root) return;
    mode(root->left);
    if(m.find(root->val) == m.end())
        m[root->val] = 1;
    else{
        m[root->val]++;
        if(j<m[root->val]){
            j = m[root->val];
            val = root->val;
        }
    }
    mode(root->right);
}