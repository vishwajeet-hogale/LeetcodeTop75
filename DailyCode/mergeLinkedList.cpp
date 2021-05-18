#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
};
ListNode* mergeList(ListNode *head1,ListNode *head2){
    ListNode *temp = head1;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = head2;
    return head1;
}
