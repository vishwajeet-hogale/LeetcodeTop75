#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct ListNode{
    int data;
    struct ListNode *next;
};

bool hasCycle(ListNode *root){
    ListNode *fast = root,*slow = root;
    while(fast && fast->next){
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow){
            return true;
        }
    }
    return false;
}

