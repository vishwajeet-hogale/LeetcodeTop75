#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
    int data;
    TreeNode *left,*right;
};

//Flattening Tree problem i.e converting a bst to a sorted doubly linked list
TreeNode *head=NULL,*p = NULL;
void convertBSTtoSorted(TreeNode *root){
    if(!root) return;
    convertBSTtoSorted(root->left);
    if(p == NULL)
        head = root;
    else{
        root->left = p;
        p->right = root;
        p = root;
    }
    convertBSTtoSorted(root->right);

}