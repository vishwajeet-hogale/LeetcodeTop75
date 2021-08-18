#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

Node *removeDuplicates(Node* head){
    Node *curr = head;
    while(curr->next != NULL){
        if(curr->next->data == curr->data){
            curr->next = curr->next->next;
        }
        else
            curr = curr->next;
    }
    return head;
}