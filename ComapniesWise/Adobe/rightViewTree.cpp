#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node* left, * right;
};

vector<int> rightView(Node *root){
    queue<Node*> q;
    q.push(root);
    vector<int> res;
    while(!q.empty()){
        int size = q.size();
        for(int i=0;i<size;i++){
            Node *cur = q.front();
            q.pop();
            if(cur == NULL)
                continue;
            if(i==size-1){
                res.push_back(cur->data);
            }
            if(cur->left)
                q.push(cur->left);
            if(cur->right)
                q.push(cur->right);
        }
    }
    return res;
}