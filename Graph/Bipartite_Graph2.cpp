//To calculate whether a graph is a bipartite graph or not using DFS.
// TC -> O(N + 2E) + O(N)
// SC -> O(N) + O(N)
#include<iostream>
#include<vector>
using namespace std;
bool isBipartite(int node,int col,vector<int> & colour,vector<vector<int>>& adj)
{
    colour[node]=col;
    for(auto it:adj[node])
    {
        if(colour[it]==-1)
        {
            if(isBipartite(it,!col,colour,adj)==false)
            {
                return false;
            }      
        }
        else if(colour[it]==colour[node])
        {
            return false;
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
    vector<int> colour(n+1,-1);
    for(int i=1;i<=n;i++)
    {
        if(colour[i]==-1)
        {
            if(isBipartite(i,0,colour,adj)==false)
            {
                cout<<"It is not a bipartite graph"<<endl;
                return 0;
            }
        }
    }
    cout<<"It is a bipartite graph"<<endl;
    return 0;
}