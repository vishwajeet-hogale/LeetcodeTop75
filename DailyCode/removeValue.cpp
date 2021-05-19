#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
};
ListNode* removeValue(ListNode *head,int value){
    ListNode *ptr =head;
    ListNode *prev =NULL;
    if(!head){
        return NULL;
    }
    while(ptr->next){
        if(ptr->val == value){
            break;
        }
        prev = ptr;
        ptr = ptr->next;
    }
    prev->next = ptr->next;
    ptr->next = NULL;
    return head;
    
}