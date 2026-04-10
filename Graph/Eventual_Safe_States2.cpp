//To calculate the safe nodes in a graph using BFS.
//Safe node-> if every possible path starting from that node leads to a terminal node
//Terminal node-> if the node has no outgoing edges
//Intution-> Reverse the edges and find out topo sort(will only give safe nodes as it does not work for cyclic graph so returns only safe nodes).
//TC-> 2 X O(N + E) + O(2N)
//SC-> O(4N) 
#include<iostream>
#include<vector>
#include<algorithm>
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
        adj[v].push_back(u); // reversing the edges 
    }
    vector<int>indegree(n,0);
    queue<int> q;
    vector<int> safe_nodes;
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
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        safe_nodes.push_back(node);
        for(auto it:adj[node])
        {
            indegree[it]--;
            if(indegree[it]==0)
            {
                q.push(it);
            }
        }   
    }
    sort(safe_nodes.begin(),safe_nodes.end());
    cout<<"Safe states are: ";
    for(auto it:safe_nodes)
    {
        cout<<it<<" ";
    }
    return 0;
}