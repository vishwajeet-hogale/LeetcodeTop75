#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left,*right;
};
vector<int> averageOrder(TreeNode* root){
    queue<TreeNode*> q;
    q.push(root);
    vector<int> res;
    while(!q.empty()){
        int size = q.size();
        int sum = 0;

        for(int i=0;i<size;i++){
            TreeNode *curr = q.front();
            q.pop();
            if(!curr)
                continue;
            sum += curr->val;
            if(curr->left)
                q.push(curr->left);
            if(curr->right)
                q.push(curr->right);
            
        }
        res.push_back(sum/size);
    }
    return res;
}