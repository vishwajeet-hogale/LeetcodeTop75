#include<iostream>
#include<bits/stdc++.h>
#include<math.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left,*right;
};
vector<vector<int>> levelOrderTraversal(TreeNode *root){
    vector<vector<int>> res;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        vector<int> temp;
        for(int i=0;i<size;i++){
            
            TreeNode *curr = q.front();
            q.pop();
            if(curr==NULL)
                continue;
            temp.push_back(curr->val);
            if(curr->left)
                q.push(curr->left);
            if(curr->right)
                q.push(curr->right);
            
        }
        res.push_back(temp);
    }
    return res;
}