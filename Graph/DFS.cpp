//To calculate the depth first search traversal of a graph. TC-> O(N) + O(2E) SC->O(3N)
#include<iostream>
#include<vector>
#include<queue>
#include<utility>
using namespace std;
void dfs(int node,vector<int>& vis,vector<int>& ans,vector<vector<int>>& adj)
{
    vis[node]=1;
    ans.push_back(node);
    for(auto it: adj[node])
    {
        if(!vis[it])
        {
            dfs(it,vis,ans,adj);
        }
    }
}
int main()
{
    int n,m;
    cout<<"Enter the number of vertices: ";
    cin>>n;
    cout<<"Enter the number of edges: ";
    cin>>m;
    cout<<"Enter the edges: ";
    vector<vector<int>>adj(n+1);
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int src;
    cout<<"Enter the starting node: ";
    cin>>src;
    vector<int>vis(n+1,0);
    vector<int>ans;
    dfs(src,vis,ans,adj);
    cout<<"Depth first traversal of the graph is: ";
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}