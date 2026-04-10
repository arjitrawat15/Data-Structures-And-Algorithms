//To calculate the safe nodes in a graph using DFS.
//Safe node-> if every possible path starting from that node leads to a terminal node
//Terminal node-> if the node has no outgoing edges
//Intution-> nodes in a cycle and connected/leading to a cycle are never safe nodes.
//TC-> O(N + E) + O(2N)
//SC-> O(4N) 
#include<iostream>
#include<vector>
using namespace std;
bool dfs(int node,vector<vector<int>>& adj,vector<int>& vis,vector<int>& pathvis,vector<int>& check)
{
    vis[node]=1;
    pathvis[node]=1;
    check[node]=0;
    for(auto it:adj[node])
    {
        if(!vis[it])
        {
            if(dfs(it,adj,vis,pathvis,check)==true)
            {
                check[node]=0;
                return true;
            }
        }
        else if(pathvis[it]==1)
        {
            check[node]=0;
            return true;
        }
    }
    check[node]=1;
    pathvis[node]=0;
    return false;
}
vector<int> eventual_safe_states(int n,vector<vector<int>>& adj)
{
    vector<int>vis(n,0);
    vector<int>pathvis(n,0);
    vector<int>check(n,0);
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            bool b=dfs(i,adj,vis,pathvis,check);
        }
    }
    vector<int> safe_nodes;
    for(int i=0;i<n;i++)
    {
        if(check[i]==1)
        {
            safe_nodes.push_back(i);
        }
    }
    return safe_nodes;
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
    vector<int> res=eventual_safe_states(n,adj);
    cout<<"Safe states are: ";
    for(auto it:res)
    {
        cout<<it<<" ";
    }
    return 0;
}