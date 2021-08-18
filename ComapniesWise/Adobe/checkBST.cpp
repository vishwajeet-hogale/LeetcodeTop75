#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct Treenode{
    int data;
    Treenode *left,*right;
    Treenode(int x) : data(x), left(nullptr), right(nullptr) {}
};

Treenode* helper(vector<int> &nums,int start,int end){
         if(start>end)
            return NULL;
        if(start == end){
            Treenode *ptr = new Treenode(nums[start]);
            return ptr;
        }
        int mid = (start+end)/2;
        Treenode *root = new Treenode(nums[mid]);
        root->left = helper(nums,start,mid-1);
        root->right = helper(nums,mid+1,end);
        return root;
}
int checkBST(Treenode *root){
    if(root==NULL)
        return true;
    
    if(!root->left && root->left->data > root->data){
        return false;
    }
    if(root->right->data < root->data && !root->right)
        return false;
    if(!checkBST(root->left) || !checkBST(root->right))
        return false;
    return true;

}
int main(){
    vector<int> arr({-10,-3,0,5,9});
    Treenode *root = helper(arr,0,arr.size()-1);
    cout<<checkBST(root)<<endl;
    return 0;
}