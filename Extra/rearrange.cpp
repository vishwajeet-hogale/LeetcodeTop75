#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void rearrange(vector<int> &nums){
    int smallest = 0;
    int largest = n-1;
    int i =0;
    int f = 1;
    long long nums1[10000]={0};
    
    while(i<n){
        if(f){
            nums1[i] = arr[largest];
            largest--;
        }
        else{
            nums1[i] = arr[smallest];
            smallest++;
        }
        f = !f;
        i++;
    }
    for(int i=0;i<n;i++){
        arr[i] = nums1[i];
    }
}
int main(){
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(5);
    nums.push_back(6);
    vector<int> res = rearrange(nums);
    for(int &i:res){
        cout<<i<<endl;
    }
    return 0;

}