//To find out the number of land which can't move out of the boundary using BFS.
//TC-> O(N X M) + O(N X M) + O(N x M x 4)  ~ O(N x M) 
//SC-> O(N X M) + O(N X M) ~ O(N X M)
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
    queue<pair<int,int>>q;
    for(int i=0;i<n;i++) //for boundary 1's 
    {
        for(int j=0;j<m;j++)
        {
            if((i==0 || j==0 || i==n-1 || j==m-1) && grid[i][j]==1)
            {
                vis[i][j]=1;
                q.push({i,j});
            }
        }
    }
    int delr[4]={-1,0,+1,0};
    int delc[4]={0,-1,0,+1};
    while(!q.empty())
    {
        int r=q.front().first;
        int c=q.front().second;
        q.pop();
        for(int k=0;k<4;k++)
        {
            int nr=r+delr[k];
            int nc=c+delc[k];
            if(nr>=0 && nc>=0 && nr<n && nc<m && grid[nr][nc]==1 && !vis[nr][nc])
            {
                vis[nr][nc]=1;
                q.push({nr,nc});
            }
        }
    }
    int cnt=0;
    for(int i=0;i<n;i++) 
    {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]==1 && !vis[i][j])
            {
                cnt++;
            }
        }
    }
    cout<<"Number of land which cannot move out of the boundary is: "<<cnt<<endl;
    return 0;
}