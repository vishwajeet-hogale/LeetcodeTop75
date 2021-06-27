#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool popsicle(vector<int> &customers){
    int change = 0;
    vector<int> coins({20,10,5});
    if(customers[0]>5)
        return false;
    map<int,int> cha;
    cha[5] = 0;
    cha[10] = 5;
    cha[20] = 15;
    for(int i=0;i<customers.size();i++){
        
        change += customers[i];
        if(customers[i]>5){

            if(change < cha[customers[i]])
                return false;
            else
                change -= cha[customers[i]];
        }
        
        
    }
    return true;
}
int main(){
    vector<int> nums({20});
    cout<<popsicle(nums)<<endl;
    return 0;
}