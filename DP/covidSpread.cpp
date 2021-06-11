#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> graph({
    {2, 1, 0, 2, 1},
    {1, 0 ,1 ,2 ,1},
    {1, 0 ,0, 2, 1 },
});

/* 
They asked minimum amount of time 
so we use BFS 
Iterate through the matrix and keep setting all the 1's to 2's which means an 
uninfected person was infected by the virus.
*/
bool check(int i, int j, int N, int M, vector<vector<int>> &hospital)
    {
        if(i >= 0 and i < N and j >= 0 and j < M and hospital[i][j] == 1)
        {
            return true;
        }
        
        return false;
    }
    

    int helpaterp(vector<vector<int>> hospital)
    {
        int N = hospital.size();
        int M = hospital[0].size();
        
        queue<pair<int, int>> q;
        
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < M; j++)
            {
                if(hospital[i][j] == 2)
                {
                    q.push({i, j});
                }
            }
        }
        
        int timer = -1;
        
        while(!q.empty())
        {
            int size = q.size();
            
            while(size--)
            {
                int currX = q.front().first;
                int currY = q.front().second;
                
                if(check(currX - 1, currY, N, M, hospital))
                {
                    q.push({currX - 1, currY});
                    
                    hospital[currX - 1][currY] = 2;
                }
                
                if(check(currX, currY + 1, N, M, hospital))
                {
                    q.push({currX, currY + 1});
                    
                    hospital[currX][currY + 1] = 2;
                }
                
                if(check(currX + 1, currY, N, M, hospital))
                {
                    q.push({currX + 1, currY});
                    
                    hospital[currX + 1][currY] = 2;
                }
                
                if(check(currX, currY - 1, N, M, hospital))
                {
                    q.push({currX, currY - 1});
                    
                    hospital[currX][currY - 1] = 2;
                }
                
                q.pop();
            }
            
            timer++;
        }
        
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < M; j++)
            {
                if(hospital[i][j] == 1)
                {
                    return -1;
                }
            }
        }
        
        return timer;
    }
int main(){
    cout<<helpaterp(graph)<<endl;
    return 0;
}