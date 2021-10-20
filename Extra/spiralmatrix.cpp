#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int> spriralMatrix(vector<vector<int>> &matrix){
    int n = matrix.size();
    int m = matrix[0].size();
    int num = n*m,cnt = 0;
    int tr=0,br=n-1,lc=0,rc=m-1;
    int i=0,j=0;
    vector<int> r;
    char dir ='R';
    while(cnt < num){
        
        if(dir == 'R'){
            r.push_back(matrix[i][j]);
            if(j == rc){
                dir = 'D';
                tr++;
                i++;
            }
            else{
                j++;
            }
            cnt++;
        }
        else if(dir == 'D'){
            r.push_back(matrix[i][j]);
            if(i == br){
                rc--;
                dir = 'L';
                j--;
            }
            else{
                i++;
            }
            cnt++;
        }
        else if(dir == 'L'){
            r.push_back(matrix[i][j]);
            if(j == lc){
                dir = 'T';
                br--;
                i--;
            }
            else{
                j--;
            }
            cnt++;
        }
        else{
            r.push_back(matrix[i][j]);
            if(i == tr){
                dir = 'R';
                lc++;
                j++;
            }
            else{
                i--;
            }
            cnt++;
        }
    }
    return r;
}
int main(){
    
    cout<<"ENter the row and columns in r x format"<<endl;
    int row,col;
    cin>>row>>col;
    vector<vector<int>> matrix(row);
    for(int i=0;i<row;i++){
        matrix[i] = vector<int>(col);
    }
    for(int i =0;i<row;i++){
        for(int j =0;j<col;j++){
            cout<<"matrix[i][j] : "<<endl;
            cin>>matrix[i][j];
        }
    }
    vector<int> res = spriralMatrix(matrix);
    cout<<"(";
    for(int &x:res){
        cout<<x<<",";
    }
    cout<<")"<<endl;
    return 0;

}