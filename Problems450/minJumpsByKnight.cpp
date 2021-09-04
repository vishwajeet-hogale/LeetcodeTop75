#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// int invalid(int x,int y,int N){
//     return x<0 || x>=N || y<0 || y>= N;
// }
// int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
// 	{
// 	    // Code here
// 	    queue<pair<int,int>> q;
// 	    vector<vector<int>> vis(N,vector<int>(N,0));
// 	    q.push(make_pair(KnightPos[0]-1,KnightPos[1]-1));
// 	    vector<int> xdir({ -2, -1, 1, 2, -2, -1, 1, 2 });
// 	    vector<int> ydir({ -1, -2, -2, -1, 1, 2, 2, 1 });
// 	    vis[KnightPos[0]-1][KnightPos[1]-1] = 1;
// 	    int c = 0;
// 	    while(!q.empty()){
// 	        int size = q.size();
//             cout<<"Size : "<<size<<endl;
// 	        for(int i=0;i<size;i++){
// 	            pair<int,int> m = q.front();
// 	            q.pop();
// 	            // if(m.first<0 || m.first>=N || m.second <0 || m.second >= N || vis[m.first][m.second]){
// 	            //     continue;
// 	            // }
// 	            if(m.first == TargetPos[0]-1 && m.second == TargetPos[1]-1)
// 	                return c;
	            
// 	            for(int i=0;i<xdir.size();i++){
//                     cout<<m.first+xdir[i]<<","<<m.second+ydir[i]<<endl;
//                     if(!invalid(m.first+xdir[i],m.second+ydir[i],N)){
//                         vis[m.first+xdir[i]][m.second+ydir[i]] = 1;
// 	                    q.push(make_pair(m.first+xdir[i],m.second+ydir[i]));
//                     }
// 	            }
// 	        }
// 	        c++;
// 	    }
// 	    return c;
// 	}
int minStepToReachTarget(vector<int>&kp, vector<int>&tp,int n){
    if(kp[0] == tp[0] && kp[1] == tp[1]) return 0;
    
    int board[n+1][n+1] = {0};
    int dir[][2] = {{-1, 2}, {-1, -2}, {1, -2}, {1, 2}, {-2, 1}, {-2, -1}, {2, 1}, {2, -1}};
    
    queue<pair<int, int>> q;
    q.push({kp[0]-1, kp[1]-1});
    board[tp[0]-1][tp[1]-1] = 2;
    
    int steps=0;
    
    while(!q.empty()){
        int siz = q.size();
        for(int i=0; i<siz; i++){
	        auto p = q.front();
	        int sr = p.first;
	        int sc = p.second;
	        q.pop();
	        
	        for(int d=0; d<8; d++){
	            int r = sr + dir[d][0];
	            int c = sc + dir[d][1];
	            if(r>=0 && c>=0 && r<n && c<n){
	                if(board[r][c]==2){
	                    return steps+1;
	                } else if(board[r][c]==0){
	                    board[r][c] = -1;
	                    q.push({r, c});
	                }
	            }
	        }
        }
        steps++;
    }
    return -1;
}
int main(){
    vector<int> start({4,5});
    vector<int> end({7,7});
    int N = 9;
    cout<<minStepToReachTarget(start,end,N)<<endl;
    return 0;
}