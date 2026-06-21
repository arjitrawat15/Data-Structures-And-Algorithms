//to find the path from start to end which minimise the sum of cost of all numbers along the path.
#include<iostream>
#include<vector>
using namespace std;
int recursion(int i,int j,vector<vector<int>>& grid) // TC-> expo
{
    if(i==0 && j==0) return grid[0][0];
    if(i<0 || j<0) return 1e9;
    int up=grid[i][j] + recursion(i-1,j,grid);
    int left=grid[i][j] + recursion(i,j-1,grid);
    return min(up,left);
}
int memo(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& dp) // TC-> O(N X M) SC-> O(N X M) + O(path len)
{
    if(i==0 && j==0) return grid[0][0];
    if(i<0 || j<0) return 1e9;
    if(dp[i][j]!=-1) return dp[i][j];
    int up=grid[i][j] + memo(i-1,j,grid,dp);
    int left=grid[i][j] + memo(i,j-1,grid,dp);
    return dp[i][j]=min(up,left);
}
int tabulation(vector<vector<int>>& grid,vector<vector<int>>& dp) // TC-> O(N X M) SC-> O(N X M)
{
    int n=grid.size();
    int m=grid[0].size();
    dp[0][0]=grid[0][0];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(i==0 && j==0) continue;
            int up=grid[i][j],left=grid[i][j];
            if(i>0)
            {
                up+=dp[i-1][j];
            }
            else
            {
                up=1e9;
            }
            if(j>0)
            {
                left+=dp[i][j-1];
            }
            else
            {
                left=1e9;
            }
            dp[i][j]=min(up,left);
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
    cout<<"Minimum path sum using recursion is: "<<recursion(n-1,m-1,grid)<<endl;
    vector<vector<int>> dp(n,vector<int>(m,-1));
    cout<<"Minimum path sum using memoization is: "<<memo(n-1,m-1,grid,dp)<<endl;
    vector<vector<int>> dp2(n,vector<int>(m,0));
    cout<<"Minimum path sum using tabulation is: "<<tabulation(grid,dp2)<<endl;
    return 0;
}