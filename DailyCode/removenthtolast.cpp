#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
};
ListNode* removeNthToLast(ListNode *head,int num){
    ListNode *temp = head;
    int n=0;
    while(temp!=NULL){
        n++;
        temp = temp->next;
    }
    int i=0;
    ListNode* ptr = head;
    ListNode* prev = NULL;
    while(ptr && i< n-num){
        prev = ptr;
        ptr = ptr->next;
        i++;
    }
    prev->next = ptr->next;
    ptr->next = NULL;
    return head;

}