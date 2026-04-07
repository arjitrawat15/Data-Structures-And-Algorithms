//To calculate the course schedule whether it is possible to finish all the courses or not if [ai, bi] are pre-requisties of 
//doing course b before doing course a using Kahn's algorithm (BFS).
// TC -> 2 X O(N + E) + 2 X O(N)
// SC -> O(N) + O(N)
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
        adj[v].push_back(u); // [a,b] where b comes before a , so it is a reverse
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
    vector<int> topo;
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
    if(topo.size()==n)
    {
        cout<<"It is possible to finish all the courses"<<endl;
    }
    else
    {
        cout<<"Not possible to finish all the courses"<<endl;
    }
    return 0;
}