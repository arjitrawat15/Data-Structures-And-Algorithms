//To calculate the count connected components using DFS.
//TC-> O(V + E) SC->O(V)
#include<iostream>
#include<vector>
using namespace std;
void dfs(int node,vector<int>& vis,vector<vector<int>>& adj)
{
    vis[node]=1;
    for(auto it: adj[node])
    {
        if(!vis[it])
        {
            dfs(it,vis,adj);
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
    int cnt=0;
    vector<int>vis(n+1,0);
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            dfs(i,vis,adj);
            cnt++;
        }
    }
    cout<<"Number of Connected Components are: "<<cnt<<endl;
    return 0;
}