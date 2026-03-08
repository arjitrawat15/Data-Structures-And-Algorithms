//To calculate the breadth first search traversal of a graph. TC-> O(N) + O(2E) SC->O(3N)
#include<iostream>
#include<vector>
#include<queue>
#include<utility>
using namespace std;
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
    vector<int>bfs;
    queue<int>q;
    q.push(src);
    vis[src]=1;
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        bfs.push_back(node);
        for(int it:adj[node])
        {
            if(!vis[it])
            {
                q.push(it);
                vis[it]=1;
            }
        }
    }
    cout<<"Breadth first traversal of the graph is: ";
    for(int i=0;i<bfs.size();i++)
    {
        cout<<bfs[i]<<" ";
    }
    return 0;
}