#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
    char c;
    int freq;
    TreeNode *left,*right;
    TreeNode(char c1,int freq1):
        c(c1),freq(freq1),left(NULL),right(NULL) {}
};
TreeNode* createNode(pair<int,int> node){
    TreeNode *ptr = new TreeNode();
    ptr->c = node.second;
    ptr->freq = node.first;
    ptr->left = NULL;
    ptr->right = NULL;
    return ptr;
}
vector<string> getHuffManCodes(vector<int> nums,string S){
    priority_queue<{pair<int,int>},vector<pair<int,int>>,Greater<pair<int,int>>> pq;

    for(int i=0;i<nums.size();i++){
        pq.push(make_pair(nums[i],S[i]));
    }
    while(pq.size()!=1 && pq.size()>=2){
        pair<int,int> node1 = pq.top();
        pq.pop();
        pair<int,int> node2 = pq.top();
        pq.pop();
        int new_val = node1.first + node2.first;
        TreeNode *r = createNode(make_pair(new_val,'1'));
        // if(node1.first < node2.first){
        r->left = n1;
        r->right = n2;
        
       
    }
}