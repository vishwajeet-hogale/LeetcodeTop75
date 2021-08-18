#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node* left, *right;
};
int areMirror(Node* a, Node* b) {
    // Your code here
    if(!a && !b) return 1;
    if(!a || !b)
        return false;
    return a->data == b->data && areMirror(a->left,b->right) && areMirror(a->right,b->left);
}