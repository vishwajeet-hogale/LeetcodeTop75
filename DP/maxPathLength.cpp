#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int dp[1001] = {0};
int dfs(int src, vector<vector<int>> &graph, int des, vector<int> &vis)
{
    if (src == des)
        return 0;

    vis[src] = 1;

    int ans = INT_MIN;
    int res = 0;
    for (int i = 0; i < graph.size(); i++)
    {
        if (graph[src][i] == 1 && !vis[i])
            res += 1 + dfs(i, graph, des, vis);
        if (res > ans)
            ans = res;
    }

    return ans;
}
int main()
{
    vector<vector<int>> graph({{0, 1, 0, 0, 0, 0}, {1, 0, 1, 1, 0, 0}, {0, 1, 0, 1, 1, 0}, {1, 1, 1, 0, 0, 0}, {0, 0, 1, 0, 0, 1}, {0, 0, 0, 0, 1, 0}});
    vector<int> vis(graph.size(), 0);
    cout << dfs(0, graph, 2, vis) << endl;
    return 0;
}