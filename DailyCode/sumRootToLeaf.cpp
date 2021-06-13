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
    int sum = 0;
    void helper(string s, TreeNode *root){
        if(!root){
            
            
            
            return;
        }
        if(!root->left && !root->right){
            s += to_string(root->val);
            sum += stoi(s);
            s.pop_back();
            return;
        }
        s += to_string(root->val);
        
        helper(s,root->left);
        helper(s,root->right);
    }
    int sumNumbers(TreeNode* root) {
        helper("",root);
        return sum;
    }
};