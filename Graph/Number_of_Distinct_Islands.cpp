//To return the number of distinct islands in a matrix using DFS. 
//TC-> O(N X M X log K) + O(N x M x 4)  ~ O(N x M X log K) 
//SC-> O(N X M) + O(N X M) + O(N X M) ~ O(N X M)
#include<iostream>
#include<vector>
#include<set>
#include<queue>
using namespace std;
void dfs(int r,int c,vector<pair<int,int>>& vec,vector<vector<int>> & grid,vector<vector<int>>& vis,int row0,int col0,int delr[],int delc[],int n,int m)
{
    vis[r][c]=1;
    vec.push_back({r-row0,c-col0});
    for(int i=0;i<4;i++)
    {
        int nr=r+delr[i];
        int nc=c+delc[i];
        if(nr>=0 && nc>=0 && nr<n && nc<m && !vis[nr][nc] && grid[nr][nc]==1)
        {
            dfs(nr,nc,vec,grid,vis,row0,col0,delr,delc,n,m);
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
    vector<vector<int>>grid(n,vector<int>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>grid[i][j];
        }
    }
    vector<vector<int>> vis(n,vector<int>(m,0));
    set<vector<pair<int,int>>> st;
    int delr[4]={-1,0,+1,0};
    int delc[4]={0,-1,0,+1};
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]==1 && !vis[i][j])
            {
                vector<pair<int,int>> vec;
                dfs(i,j,vec,grid,vis,i,j,delr,delc,n,m);
                st.insert(vec);
            }
        }
    }
    cout<<"Number of distinct islands in the matrix are: "<<st.size()<<endl;
    return 0;
}