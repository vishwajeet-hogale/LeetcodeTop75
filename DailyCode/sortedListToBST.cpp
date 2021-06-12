#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left,*right;

};
TreeNode *create(int val){
    TreeNode *ptr = new TreeNode;
    ptr->left = NULL;
    ptr->right = NULL;
    ptr->val = val;
    return ptr;
}
TreeNode *makeBST(TreeNode *root,int start,int end,vector<int> &nums){
    if(start>end)
        return NULL;
    int mid = (start+end) / 2;
    TreeNode *root = create(nums[mid]);
    if(start == end)
        return root;
    root->left = makeBST(root,start,mid-1,nums);
    root->right = makeBST(root,mid+1,end,nums);
    return root;
}