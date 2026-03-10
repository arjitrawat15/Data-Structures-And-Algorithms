//To calculate the total number of islands using BFS.
//TC-> O(N X M) + O(N x M x 9)  ~ O(N x M) 
//SC-> O(N X M) + O(N X M) ~ O(N X M)
#include<iostream>
#include<vector>
#include<utility>
#include<queue>
using namespace std;
void bfs(int row,int col,vector<vector<int>>& vis,vector<vector<char>>& grid,int n,int m)
{
    vis[row][col]=1;
    queue<pair<int,int>> q;
    q.push({row,col});
    while(!q.empty())
    {
        int r=q.front().first;
        int c=q.front().second;
        q.pop();
        for(int delr=-1;delr<=1;delr++)
        {
            for(int delc=-1;delc<=1;delc++)
            {
                if(delr==0 && delc==0) continue;
                int nrow=delr+r;
                int ncol=delc+c;
                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]=='1')
                {
                    q.push({nrow,ncol});
                    vis[nrow][ncol]=1;
                }
            }
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
    int cnt=0;
    vector<vector<int>>vis(n,vector<int>(m,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]=='1' && !vis[i][j])
            {
                bfs(i,j,vis,grid,n,m);
                cnt++;
            }
        }
    }
    cout<<"Number of Islands are: "<<cnt<<endl;
    return 0;
}