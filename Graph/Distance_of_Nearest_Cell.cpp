//To find the nearest 1 for every element of matrix using BFS.
//TC-> O(N X M) + O(N x M x 4)  ~ O(N x M) 
//SC-> O(N X M) + O(N X M) + O(N X M) ~ O(N X M)
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main()
{
    int n,m;
    cout<<"Enter the total rows: ";
    cin>>n;
    cout<<"Enter the total cols: ";
    cin>>m;
    cout<<"Enter the grid: ";
    vector<vector<int>>grid(n,vector<int>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>grid[i][j];
        }
    }
    vector<vector<int>> vis(n,vector<int>(m,0));
    vector<vector<int>> ans(n,vector<int>(m));
    queue<pair<pair<int,int>,int>>q;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]==1)
            {
                vis[i][j]=1;
                q.push({{i,j},0});
            }
        }
    }
    int delr[4]={-1,0,+1,0};
    int delc[4]={0,-1,0,+1};
    while(!q.empty())
    {
        int r=q.front().first.first;
        int c=q.front().first.second;
        int steps=q.front().second;
        q.pop();
        ans[r][c]=steps;
        for(int k=0;k<4;k++)
        {
            int nr=r+delr[k];
            int nc=c+delc[k];
            if(nr>=0 && nc>=0 && nr<n && nc<m && grid[nr][nc]==0 && !vis[nr][nc])
            {
                vis[nr][nc]=1;
                q.push({{nr,nc},steps+1});
            }
        }
    }
    cout<<"Matrix for the nearest 1 of every element of grid is: "<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}