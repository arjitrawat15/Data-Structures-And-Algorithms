//To calculate whether a graph is a bipartite graph or not using BFS.
// TC -> O(N + 2E)
// SC -> O(N) + O(N)
#include<iostream>
#include<vector>
#include<queue>
#include<utility>
using namespace std;
bool isBipartite(int n,vector<vector<int>> & adj)
{
    vector<int> colour(n+1,-1);
    queue<int> q;
    q.push(0);
    colour[0]=0;
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        for(auto it:adj[node])
        {
            if(colour[it]==-1)
            {
                colour[it]=!colour[node];
                q.push(it);
            }
            else if(colour[it]==colour[node])
            {
                return false;
            }
        }
    }
    return true;
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
    if(isBipartite(n,adj))
    {
        cout<<"It is a bipartite graph"<<endl;
    }
    else
    {
        cout<<"It is not a bipartite graph"<<endl;
    }
    return 0;
}