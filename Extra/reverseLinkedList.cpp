#include<iostream>
#include<bits/stdc++.h>

using namespace std;
struct node{
    int data;
    node* next;
};
node* insert(node* root,int val){
    node* ptr = new node;
    ptr->data = val;
    ptr->next = NULL;
    if(root == NULL){
        return ptr;
    }
    node* p = root;
    while(p->next != NULL){
        p = p->next;
    }
    p->next = ptr;
    return root;

}
node* reverse(node* root){
    node* prev=NULL,*next = NULL,*curr = root;
    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    root = prev;
    return root;
}
int main(){
   
    node* root = insert(NULL,0);
    for(int i=1;i<10;i++){
        root = insert(root,i);
    }
    node *root1 = reverse(root);
    while(root1!=NULL){
        cout<<root1->data<<"->";
        root1 = root1->next;
    }
    cout<<"NULL"<<endl;
    return 0;
}