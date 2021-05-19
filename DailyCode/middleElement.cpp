#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
};
int middleElement(ListNode *head){
    ListNode *slow = head;
    ListNode *fast = head;
    while(fast->next && fast){
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return slow->val;
}