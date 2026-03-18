//To calculate the topological sort of a directed acyclic graph using DFS.
// TC -> O(N + E) + O(N) + O(N)
// SC -> O(N) + O(N) + O(N)
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
void topo_sort(int node,stack<int>& st,vector<vector<int>>& adj,vector<int> & vis)
{
    vis[node]=1;
    for(auto it:adj[node])
    {
        if(!vis[it])
        {
            topo_sort(it,st,adj,vis);
        }
    }
    st.push(node);
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
    stack<int> st;
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            topo_sort(i,st,adj,vis);
        }
    }
    vector<int> topo;
    while(!st.empty())
    {
        int x=st.top();
        st.pop();
        topo.push_back(x);
    }
    cout<<"Topological sort is: ";
    for(int x:topo)
    {
        cout<<x<<" ";
    }
    return 0;
}