#include<iostream>
#include<bits/stdc++.h>
using namespace std;


//if the sum becomes negative, take it as zero

struct seq_sum {
    int l,r;double s;
};

/* 
Version 1 : naive approach 
Use of three loops i,j,k
Time complexity : O(N^3)
*/
seq_sum find1(vector<double> arr,int n){
    double cmax = 0.0;
    int ci = -1,cj = -1;
    for(int i =0;i<n;i++){
        for(int j = i;j<n;j++){
            double s = 0.0;
            for(int k = i;k<=j;k++){
                s += arr[k];
            }
            if(s>cmax){
                cmax = s;
                ci = i;
                cj = j;
            }
        }
    }
    seq_sum res;
    res.l=ci;
    res.r = cj;
    res.s = cmax;
    return res;
}

/* version 2 : Removal of one loop (innermost loop k)
    Time complexity : O(N^2)
*/
seq_sum find2(vector<double> arr,int n){
    double cmax = 0.0;
    int ci = -1,cj = -1;
    for(int i =0;i<n;i++){
        double s = 0.0;
        for(int j = i;j<n;j++){
            s += arr[j];
            
            if(s>cmax){
                cmax = s;
                ci = i;
                cj = j;
            }
        }
    }
    seq_sum res;
    res.l=ci;
    res.r = cj;
    res.s = cmax;
    return res;
}
/* Version 3 : Using pre computations to improve time complexity; something better than quadratic
*/
seq_sum find3(vector<double> arr,int n){
    vector<double> acc(n+1);
    acc[0] = 0.0;
    for(int i=1;i<=n;i++){
        acc[i] = acc[i-1] + arr[i-1];
    }
    //arr[j] - arr[i] : sum of the sequence between i and j; gives sum of subsequence between i and j
    double cmax = 0.0;
    int ci = -1,cj = -1;
    for(int i =1;i<=n;i++){
        double s;
        for(int j = i;j<n;j++){
            s = acc[j] - acc[i-1];
            
            if(s>cmax){
                cmax = s;
                ci = i-1;
                cj = j-1;
            }
        }
    }
    seq_sum res;
    res.l=ci;
    res.r = cj;
    res.s = cmax;
    return res;
}
/* 
Version 4 : Use the concept of divide and conquer to find the max sum subsequence
Time complexity : O(N*log N)
Recursive 
*/
seq_sum bigger_3(seq_sum s_l_r,seq_sum s_l, seq_sum s_r){
    if(s_l_r.s>=s_l && s_l_r.s>=s_r.s)
        return s_l_r;
    else if(s_l.s>s_l_r.s && s_l.s>s_r.s)
        return s_l;
    else if(s_r.s>s_l_r.s && s_r.s>s_l.s)
        return s_r;
}
seq_sum find_sum(vector<double> &arr,int l,int r){
    // base cases 
    if(i>j){
        seq_sum s ={-1,-1,0.0};
        return s;
    }
    if(l== r){
        seq_sum s = {l,r,(arr[l]>0)?arr[l]:0.0};
        return s;
    }
    int m = (l+r)/2;
    double lmax,rmax;
    lmax = DBL_MIN,rmax = DBL_MIN;double sum = 0;
    int ci ,cj ;
    for(int i = m;i>=l;i--){
        sum += arr[i];
        if(sum > lmax){
            lmax = sum;
            ci = i;
            // cj = m;
        }
    }
    sum = 0.0;
    for(int i = m+1;i<=rl;i++){
        sum += arr[i];
        if(sum > rmax){
            rmax = sum;
            cj= i;
            // cj = m;
        }
    }
    seq_sum s_l_r;
    s_l_r.l = ci;
    s_l_r.r = cj;
    s_l_r.s = lmax+rmax;
    seq_sum s_l = find_sum(arr,l,m);
    seq_sum s_r = find_sum(arr,m+1,r); 
    return bigger_3(s_l_r,s_l,s_r);
}
seq_sum find4(vector<double> arr,int n){
    return find_sum(arr,0,n-1);
}

/* 
Version 5 : Converting N*log N to Linear time complexity 
Linear 
*/ 
seq_sum find_sum(vector<double> &arr,int l,int r){
    double cmax = 0.0;int ci = -1,cj = -1;  
    int max_l = -1,max_r = -1;double max_end = 0.0;
    for(int i =0;i<n;i++){
        if(max_end + arr[i] > 0){
            max_end += arr[i];
            max_r = i;
        }
        else{
            max_end = 0.0;
            max_l = i + 1;  
        }
        if(max_end > cmax){
            cmax = max_end;
            ci = max_l;
            cj = max_r;
        }
    }
    seq_sum res = {ci,cj,cmax};
    return res;

}
int main(){
    vector<double> arr({31,-41,59,26,-53,58,97,-93,-23,84});
    int n = 10;
    seq_sum s;
    s = find4(arr,n);
    cout<<"Left : "<<s.l<<" Right : "<<s.r<<" Sum : "<<s.s<<endl;
    return 0;
}