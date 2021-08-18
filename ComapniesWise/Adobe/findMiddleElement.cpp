#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Listnode{
    int data;
    Listnode *next;
};

Listnode* findMiddle(Listnode *head){
    Listnode *fast = head,*slow = head;
    while(fast && fast->next){
        fast = fast->next->next;
        slow = slow->next;
        
    }
    return slow;
}
