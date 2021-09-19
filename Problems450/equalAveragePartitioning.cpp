#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr,vector<int> &temp,int index,int n1,int sum){
    if(index >= arr.size()){
        return false;
    }
    if(n1 == 0){
        return sum == 0;
    }
    if(arr[index]<=sum){
        temp.push_back(arr[index]);
        if(partition(arr,temp,index+1,n1-1,sum-arr[index]));
            return true;
        temp.pop_back();
    }
    if(partition(arr,temp,index+1,n1,sum))
        return true;
    return false;

}
void avgset(vector<int> &A) {
    int sum = 0;
    for(int i:A)
        sum += i;
    int n = A.size();
    for(int i = 1;i<n;i++){
        if((sum*i)%n == 0){
            vector<int> res;
            int s = (sum*i)/n;
            if(partition(A,res,0,i,s)){
                cout<<"[";
                for(int i:res)
                    cout<<i<<",";
                cout<<" ]";
                cout<<" [";
                for(int i:A){
                    if(find(res.begin(),res.end(),i)==res.end()){
                        cout<<i<<",";
                    }
                }
                cout<<" ]";
                cout<<endl;
            }

        }
    }
}
int main(){
    vector<int> arr({1,2,3,4,5,6});
    avgset(arr);
    return 0;
}