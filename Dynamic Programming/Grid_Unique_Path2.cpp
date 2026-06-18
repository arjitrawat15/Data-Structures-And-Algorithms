//To find total no of unique paths from start (0,0) to destination (n-1,m-1) but with obstacles. 
#include<iostream>
#include<vector>
using namespace std;
int recursion(int i,int j,vector<vector<int>>& grid) // TC-> expo
{
    if(i<0 || j<0) return 0;
    if(grid[i][j]==1) return 0;
    if(i==0 && j==0) return 1;
    int up=recursion(i-1,j,grid);
    int left=recursion(i,j-1,grid);
    return up+left;
}
int memo(int i,int j,vector<vector<int>>& dp,vector<vector<int>>& grid) // TC-> O(N X M) SC-> O(N X M) + O(path len)
{
    if(i<0 || j<0) return 0;
    if(grid[i][j]==1) return 0;
    if(i==0 && j==0) return 1;
    if(dp[i][j]!=-1) return dp[i][j];
    int up=memo(i-1,j,dp,grid);
    int left=memo(i,j-1,dp,grid);
    return dp[i][j]=up+left;
}
int tabulation(vector<vector<int>>& dp,int n,int m,vector<vector<int>>& grid) // TC-> O(N X M) SC-> O(N X M)
{
    if(grid[0][0]==1) return 0;
    dp[0][0]=1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(i==0 && j==0) continue;
            if(grid[i][j]==1) continue;
            int up=0,left=0;
            if(i>0) up=dp[i-1][j];
            if(j>0) left=dp[i][j-1];
            dp[i][j]=up+left;
        }
    }
    return dp[n-1][m-1];
}
int main()
{
    int n,m;
    cout<<"Enter the number of rows: ";
    cin>>n;
    cout<<"Enter the number of cols: ";
    cin>>m;
    vector<vector<int>>grid(n,vector<int>(m,0));
    cout<<"Enter the grid: ";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>grid[i][j];
        }
    }
    cout<<"No of unique paths using recursion is: "<<recursion(n-1,m-1,grid)<<endl;
    vector<vector<int>> dp(n,vector<int>(m,-1));
    cout<<"No of unique paths using memoization is: "<<memo(n-1,m-1,dp,grid)<<endl;
    vector<vector<int>> dp2(n,vector<int>(m,0));
    cout<<"No of unique paths using tabulation is: "<<tabulation(dp2,n,m,grid)<<endl;
    return 0;
}