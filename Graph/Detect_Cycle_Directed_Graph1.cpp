//To detect whether there exists a cycle or not in a directed graph using DFS.
// TC -> O(N + E) + O(N) 
// SC -> O(N) + O(N) + O(N)
#include<iostream>
#include<vector>
using namespace std;
bool dfs(int node,vector<int>& vis,vector<int>& pathvis,vector<vector<int>>& adj)
{
    vis[node]=1;
    pathvis[node]=1;
    for(auto it:adj[node])
    {
        if(!vis[it])
        {
            if(dfs(it,vis,pathvis,adj)==true)
            {
                return true;
            }
        }
        else if(pathvis[it]==1)
        {
            return true;
        }
    }
    pathvis[node]=0;
    return false;
}
int main()
{ 
    int n,m;
    cout<<"Enter the number of vertices: ";
    cin>>n;
    cout<<"Enter the number of edges: ";
    cin>>m;
    cout<<"Enter the edges: ";
    vector<vector<int>>adj(n);
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    vector<int> vis(n,0);
    vector<int> pathvis(n,0);
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            if(dfs(i,vis,pathvis,adj)==true)
            {
                cout<<"There exists a cycle in the graph"<<endl;
                return 0;
            }
        }
    }
    cout<<"There does not exists a cycle in the graph"<<endl;
    return 0;
}