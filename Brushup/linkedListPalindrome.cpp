#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct Node{
    int val;
    Node *next;
};

int palindromeCheck(Node *head){
    Node *slow = head;
    Node *fast = head;
    stack<int> q;
    while(fast && fast->next){
        q.push(slow->val);
        slow = slow->next;
        fast = fast->next->next;
    }
    while(slow){
        if(slow->val == q.top())
            q.pop();
        else 
            return 0;
        slow = slow->next;
    }
    return q.empty();
}
      