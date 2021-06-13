#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<string> res;
    void helper(string s, TreeNode *root){
        if(!root){
            
            
            
            return;
        }
        if(!root->left && !root->right){
            s += to_string(root->val);
            res.push_back(s);
            s.pop_back();
            return;
        }
        s += to_string(root->val);
        
        helper(s,root->left);
        helper(s,root->right);
    }
    vector<string> rootToLeafPath(TreeNode* root) {
        helper("",root);
        return res;
    }
};