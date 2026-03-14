//To detect cycle in an undirected graph using BFS.
//TC-> O(N + 2E) + O(N) 
//SC-> O(N) + O(N) 
#include<iostream>
#include<vector>
#include<queue>
#include<utility>
using namespace std;
bool DetectCycle(int i,int p,vector<vector<int>> & adj,vector<int>& vis)
{
    vis[i]=1;
    queue<pair<int,int>>q;
    q.push({i,p});
    while(!q.empty())
    {
        int node=q.front().first;
        int parent=q.front().second;
        q.pop();
        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                vis[it]=1;
                q.push({it,node});
            }
            else if(it != parent)
            {
                return true;
            }
        }
    }
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
    vector<vector<int>>adj(n+1);
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool isCycle=false;
    vector<int> vis(n+1,0);
    for(int i=1;i<=n;i++) // for multiple components in the graph
    {
        if(!vis[i])
        {
            if(DetectCycle(i,-1,adj,vis)==true)
            {
                isCycle=true;
            }
        }
    }
    if(isCycle)
    {
        cout<<"There exists a cycle in the graph"<<endl;
    }
    else
    {
        cout<<"There does not exist a cycle in the graph"<<endl;
    }
    return 0;
}