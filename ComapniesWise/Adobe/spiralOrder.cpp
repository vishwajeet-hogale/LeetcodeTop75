#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node* left, * right;
};

vector<int> findSpiral(Node *root){
    queue<Node*> q;
    q.push(root);
    vector<int> res;
    int f = 1;
    while(!q.empty()){
        int size = q.size();
        if(f == 0){
            for(int i=0;i<size;i++){
            Node *cur = q.front();
            q.pop();
            if(cur == NULL)
                continue;
            
            res.push_back(cur->data);
            
            if(cur->left)
                q.push(cur->left);
            if(cur->right)
                q.push(cur->right);
            }
            f = 1;
        }
        else{
            vector<int> temp;
            for(int i=0;i<size;i++){
            Node *cur = q.front();
            q.pop();
            if(cur == NULL)
                continue;
            
            temp.push_back(cur->data);
            
            if(cur->left)
                q.push(cur->left);
            if(cur->right)
                q.push(cur->right);
            }
            f = 0;
            reverse(temp.begin(),temp.end());
            res.insert(res.end(),temp.begin(),temp.end());
        }
    } 
    return res;
}