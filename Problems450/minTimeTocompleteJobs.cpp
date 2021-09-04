#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<vector<int>> &list,int i,int j,vector<int> &inDeg){
    list[i].push_back(j);
    inDeg[j]++;
}

int main(){
    int n = 10;
    
    // cin>>n;
    vector<int> inDeg(n,0);
    vector<vector<int>> list(n);
    addEdge(list,1, 3,inDeg);
    addEdge(list,1, 4,inDeg);
    addEdge(list,1, 5,inDeg);
    addEdge(list,2, 3,inDeg);
    addEdge(list,2, 8,inDeg);
    addEdge(list,2, 9,inDeg);
    addEdge(list,3, 6,inDeg);
    addEdge(list,4, 6,inDeg);
    addEdge(list,4, 8,inDeg);
    addEdge(list,5, 8,inDeg);
    addEdge(list,6, 7,inDeg);
    addEdge(list,7, 8,inDeg);
    addEdge(list,8, 10,inDeg);
    // while(n>0){
    //     int i,j;
    //     cin>>i>>j;
    //     addEdge(list,i,j);
    //     inDeg[j]++;
    // }
    queue<int> q;
    vector<int> res(n,0);
    for(int i=0;i<n;i++){
        if(inDeg[i] == 0){
            q.push(i);
            res[i] = 1;
        }
    }
    
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(int i:list[curr]){
            inDeg[i]--;
            if(inDeg[i] == 0){
                res[i] = res[curr] + 1;
                q.push(i);
            }
        }
    }
    for (int i = 0; i < n; i++)
        cout << res[i] << " ";
    cout << "\n";
}
