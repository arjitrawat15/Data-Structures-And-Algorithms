//Representation of a Directed Graph in form of Adjacency Matrix And Adjacency List considering 1-based indexing
#include<iostream>
#include<vector>
#include<utility>
using namespace std;
int main()
{
    int n,m;
    cout<<"Enter the number of vertices: ";
    cin>>n;
    cout<<"Enter the number of edges: ";
    cin>>m;
    vector<pair<int,int>> edges;
    cout<<"Enter the edges: ";
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        edges.push_back({u,v});
    }
    //Representation in form of Adjacency Matrix
    vector<vector<int>> mat(n+1,vector<int>(n+1,0));
    for(int i=0;i<m;i++)
    {
        int u=edges[i].first;
        int v=edges[i].second;
        mat[u][v]=1;
    }
    cout<<"Representation of Adjacency Matrix: "<<endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    //Representation in form of Adjacency List
    vector<vector<int>>adj(n+1);
    for(int i=0;i<m;i++)
    {
        int u=edges[i].first;
        int v=edges[i].second;
        adj[u].push_back(v);
    }
    cout<<"Representation of Adjacency List: "<<endl;
    for(int i=1;i<=n;i++)
    {
        cout<<i<<" -> ";
        for(auto it:adj[i])
        {
            cout<<it<<" -> ";
        }
        cout<<endl;
    }
    return 0;
}