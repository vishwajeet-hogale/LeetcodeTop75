#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Listnode{
    int data;
    Listnode *next;
};

Listnode* reverseLinkedList(Listnode *head){
    Listnode *curr = head,*prev = NULL,*next = NULL;
    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}