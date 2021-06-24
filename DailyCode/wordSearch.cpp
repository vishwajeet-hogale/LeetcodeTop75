#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int f = 0;
bool wordSearch(vector<vector<char>> &grid,int row,int col,string word,int index){
    if(index >= word.size())
        return true;
    if(row < 0 || row > grid.size() || col < 0 || col > grid[0].size() || grid[row][col] != word[index])
        return false;
    
    grid[row][col] = '#';
    if(wordSearch(grid,row+1,col,word,index+1))
        return true;
    if(wordSearch(grid,row-1,col,word,index+1))
        return true;
    if(wordSearch(grid,row,col+1,word,index+1))
        return true;
    if(wordSearch(grid,row,col-1,word,index+1))
        return true;

    grid[row][col] = word[index];
    return false;
}
int main(){
    vector<vector<char>> grid({
        {'C','A','T','F'},
        {'B','G','E','S'},
        {'I','T','A','E'}
    });
    string word = "CAZ";
    cout<<wordSearch(grid,0,0,word,0)<<endl;
    return 0;
}