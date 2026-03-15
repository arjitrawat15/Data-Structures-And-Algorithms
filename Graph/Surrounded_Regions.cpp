//To replace all the 'O' with 'X' which are surrounded by 'X' from all the sides using DFS.
//TC-> O(N) + O(N) + O(N x M) + O(N x M x 4)  ~ O(N) + O(N x M) 
//SC-> O(N X M) + O(N X M) ~ O(N X M)
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void dfs(int r,int c,vector<vector<int>>& vis,vector<vector<char>>& grid,int delr[],int delc[],int n,int m)
{
    vis[r][c]=1;
    for(int i=0;i<4;i++)
    {
        int nr=r+delr[i];
        int nc=c+delc[i];
        if(nr>=0 && nc>=0 && nr<n && nc<m && grid[nr][nc]=='O' && !vis[nr][nc])
        {
            dfs(nr,nc,vis,grid,delr,delc,n,m);
        }
    }
}
int main()
{
    int n,m;
    cout<<"Enter the total rows: ";
    cin>>n;
    cout<<"Enter the total cols: ";
    cin>>m;
    cout<<"Enter the grid: ";
    vector<vector<char>>grid(n,vector<char>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>grid[i][j];
        }
    }
    vector<vector<int>> vis(n,vector<int>(m,0));
    int delr[4]={-1,0,+1,0};
    int delc[4]={0,-1,0,+1};
    for(int i=0;i<n;i++) // left and right boundary
    {
        if(grid[i][0]=='O' && !vis[i][0])
        {
            dfs(i,0,vis,grid,delr,delc,n,m);
        }
        if(grid[i][m-1]=='O' && !vis[i][m-1])
        {
            dfs(i,m-1,vis,grid,delr,delc,n,m);
        }
    }
    for(int j=0;j<m;j++) // upper and lower boundary
    {
        if(grid[0][j]=='O' && !vis[0][j])
        {
            dfs(0,j,vis,grid,delr,delc,n,m);
        }
        if(grid[n-1][j]=='O' && !vis[n-1][j])
        {
            dfs(n-1,j,vis,grid,delr,delc,n,m);
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]=='O' && !vis[i][j])
            {
                grid[i][j]='X';
            }
        }
    }
    cout<<"Matrix after replacing of 'O' surrounded by 'X': "<<endl; 
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<grid[i][j];
        }
        cout<<endl;
    }
    return 0;
}