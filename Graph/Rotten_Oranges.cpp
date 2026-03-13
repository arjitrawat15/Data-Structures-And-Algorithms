//To calculate the minimum number of time taken to rotten all the fresh oranges in the frid
//TC-> O(N X M) + O(N x M x 4)  ~ O(N x M) 
//SC-> O(N X M) + O(N X M) ~ O(N X M)
#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
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
    queue<pair<pair<int,int>,int>>q;
    int cntf=0; // count the number of fresh oranges 
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]==2)
            {
                q.push({{i,j},0});
                vis[i][j]=1;
            }
            else if(grid[i][j]==1)
            {
                cntf++;
            }
        }
    }
    int delr[4]={-1,0,+1,0};
    int delc[4]={0,-1,0,+1};
    int time=0;
    int cnt=0; //count of how many fresh oranges are rotten
    while(!q.empty())
    {
        int r=q.front().first.first;
        int c=q.front().first.second;
        int t=q.front().second;
        q.pop();
        time=max(t,time);
        for(int k=0;k<4;k++)
        {
            int nrow=delr[k]+r;
            int ncol=delc[k]+c;
            if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]==1)
            {
                q.push({{nrow,ncol},t+1});
                vis[nrow][ncol]=1;
                cnt++;
            }
        }
    }
    if(cntf!=cnt) 
    {
        cout<<"Some oranges cannot be rotten"<<endl;
    }
    else
    {
        cout<<"Minimum number of time taken to rot all the fresh oranges are: "<<time<<endl;
    }
    return 0;
}