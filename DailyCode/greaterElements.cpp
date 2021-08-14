#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int> greaterElements(vector<int> &arr1, vector<int> &arr2)
{
    vector<int> res;
    int k;
    for (int j = 0; j < arr1.size(); j++)
    {

        int c = 0;
        auto pos = find(arr2.begin(), arr2.end(), arr1[j]);
        for (auto x = pos; x != arr2.end(); x++)
        {
            if (*x > arr1[j])
            {
                c = *x;
                break;
            }
        }
        if (c == 0)
            c = -1;
        res.push_back(c);
    }
    cout << endl;
    return res;
}
int main()
{
    vector<int> arr1;
    arr1.push_back(2);
    // arr1.push_back(1);
    arr1.push_back(4);
    vector<int> arr2;
    arr2.push_back(1);
    arr2.push_back(2);
    arr2.push_back(3);
    arr2.push_back(4);
    vector<int> res = greaterElements(arr1, arr2);
    for (int &x : arr1)
    {
        cout << x<<",";
    }
    cout<<endl;
    for (int &x : arr2)
    {
        cout << x<<",";
    }
    cout<<endl;
    for (int &x : res)
    {
        cout << x << ",";
    }
    cout<<endl;
    return 0;
}