// find minimum path sum from top to bottom where every ith row has i+1 elements forming a triangle.
// fixed starting point to variable starting point and only two directions (down and diagonal)
// 1
// 2 3
// 3 6 7
// 8 9 6 10
// answer -> 14 ( 1->2->3->8) 
#include<iostream>
#include<vector>
using namespace std;
int recursion(int i,int j,vector<vector<int>>& grid,int n) // TC-> expo ( starting from 0,0 in bottom up as only 1 fixed point we have)
{
    if(i==n-1) return grid[n-1][j];
    int down=grid[i][j] + recursion(i+1,j,grid,n);
    int diagonal=grid[i][j] + recursion(i+1,j+1,grid,n);
    return min(down,diagonal);
}
int memo(int i,int j,vector<vector<int>>& grid,int n,vector<vector<int>>& dp) // TC-> O(N X N) SC-> O(N X N) + O(N)
{
    if(i==n-1) return grid[n-1][j];
    if(dp[i][j]!=-1) return dp[i][j];
    int down=grid[i][j] + memo(i+1,j,grid,n,dp);
    int diagonal=grid[i][j] + memo(i+1,j+1,grid,n,dp);
    return dp[i][j]=min(down,diagonal);
}
int tabulation(vector<vector<int>>& grid,vector<vector<int>>& dp)  // TC-> O(N X N) SC-> O(N X N)
{
    int n=grid.size();
    for(int j=0;j<n;j++)
    {
        dp[n-1][j]=grid[n-1][j];
    }
    for(int i=n-2;i>=0;i--)
    {
        for(int j=i;j>=0;j--)
        {
            int down=grid[i][j] + dp[i+1][j];
            int diagonal=grid[i][j] + dp[i+1][j+1];
            dp[i][j]=min(down,diagonal);
        }
    }
    return dp[0][0];
}
int main()
{
    int n;
    cout<<"Enter the number of rows: ";
    cin>>n;
    vector<vector<int>>grid(n,vector<int>(n,0));
    cout<<"Enter the grid: ";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            cin>>grid[i][j];
        }
    }
    cout<<"Minimum path sum using recursion is: "<<recursion(0,0,grid,n)<<endl;
    vector<vector<int>> dp(n,vector<int>(n,-1));
    cout<<"Minimum path sum using memoization is: "<<memo(0,0,grid,n,dp)<<endl;
    vector<vector<int>> dp2(n,vector<int>(n,0));
    cout<<"Minimum path sum using tabulation is: "<<tabulation(grid,dp2)<<endl;
    return 0;
}
