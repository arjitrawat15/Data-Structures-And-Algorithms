// to calculate the minimum falling path sum where can start from any cell on first row till any cell on last row.
// variable starting -> variable ending
#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int recursion(int i,int j,vector<vector<int>>& grid) // TC-> expo
{
    int m=grid[0].size();
    if(j<0 || j>=m) return 1e9;
    if(i==0) return grid[0][j];

    int up=grid[i][j] + recursion(i-1,j,grid);
    int left_diag=grid[i][j] + recursion(i-1,j-1,grid);
    int right_diag=grid[i][j] + recursion(i-1,j+1,grid);

    return min(up,min(left_diag,right_diag));
}
int memo(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& dp) // TC-> O(N X M) SC-> O(N X M) + O(N)
{
    int m=grid[0].size();
    if(j<0 || j>=m) return 1e9;
    if(i==0) return grid[0][j];

    if(dp[i][j]!=-1) return dp[i][j];

    int up=grid[i][j] + memo(i-1,j,grid,dp);
    int left_diag=grid[i][j] + memo(i-1,j-1,grid,dp);
    int right_diag=grid[i][j] + memo(i-1,j+1,grid,dp);

    return dp[i][j]= min(up,min(left_diag,right_diag));
}
int tabulation(vector<vector<int>>& grid,vector<vector<int>>& dp) // TC-> O(N X M) SC-> O(N X M)
{
    int n=grid.size();
    int m=grid[0].size();
    for(int j=0;j<m;j++)
    {
        dp[0][j]=grid[0][j];
    }
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            int up=grid[i][j] + dp[i-1][j];
            int left_diag=grid[i][j];
            if(j>0) left_diag+=dp[i-1][j-1];
            else left_diag=1e9;
            int right_diag=grid[i][j];
            if(j+1<m) right_diag+=dp[i-1][j+1];
            else right_diag=1e9;
            
            dp[i][j]=min(up,min(left_diag,right_diag));
        }
    }
    int mini=INT_MAX;
    for(int j=0;j<m;j++)
    {
        mini=min(mini,dp[n-1][j]);
    }
    return mini;
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
    int mini1=INT_MAX;
    for(int j=0;j<m;j++)
    {
        mini1=min(mini1,recursion(n-1,j,grid));
    }
    cout<<"Minimum falling path sum using recusrion is: "<<mini1<<endl;

    vector<vector<int>> dp(n,vector<int>(m,-1));
    int mini2=INT_MAX;
    for(int j=0;j<m;j++)
    {
        mini2=min(mini2,memo(n-1,j,grid,dp));
    }
    cout<<"Minimum falling path sum using memoization is: "<<mini2<<endl;

    vector<vector<int>> dp2(n,vector<int>(m,0));
    cout<<"Minimum falling path sum using tabulation is: "<<tabulation(grid,dp2)<<endl;
    return 0;
}