//To detect whether there exists a cycle or not in a directed graph using Kahn's algorithm (BFS).
// TC -> 2 X O(N + E) + O(N) 
// SC -> O(N) + O(N) + O(N)
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
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
    vector<int> indegree(n,0);
    queue<int> q;
    for(int i=0;i<n;i++)
    {
        for(auto it:adj[i])
        {
            indegree[it]++;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(indegree[i]==0)
        {
            q.push(i);
        }
    }
    vector<int>topo;
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        topo.push_back(node);
        for(auto it:adj[node])
        {
            indegree[it]--;
            if(indegree[it]==0)
            {
                q.push(it);
            }
        }
    }
    if(topo.size()<n)
    {
        cout<<"There exists a cycle in the graph"<<endl;
    }
    else
    {
        cout<<"There does not exists a cycle in the graph"<<endl;
    }
    return 0;
}