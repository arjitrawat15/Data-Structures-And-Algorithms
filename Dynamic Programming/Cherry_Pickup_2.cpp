//to calculate the total no of chocolates picked by Alice starts at (0,0) and Bob starts at (0,m-1). Also they can't pick from same cell.
#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int recursion(int i,int j1,int j2,vector<vector<int>>& grid) // TC-> expo
{
    int n=grid.size();
    int m=grid[0].size();
    if(j1<0 || j2<0 || j1>=m || j2>=m) return -1e9;
    if(i==n-1)
    {
        if(j1==j2) return grid[i][j1];
        else return grid[i][j1]+grid[i][j2];
    }
    int maxi=-1e9;
    for(int dj1=-1;dj1<=1;dj1++)
    {
        for(int dj2=-1;dj2<=1;dj2++)
        {
            if(j1==j2)
            {
                maxi=max(maxi, (grid[i][j1] + recursion(i+1,j1+dj1,j2+dj2,grid)));
            }
            else
            {
                maxi=max(maxi, (grid[i][j1] + grid[i][j2] + recursion(i+1,j1+dj1,j2+dj2,grid)));
            }
        }
    }
    return maxi;
}
int memo(int i,int j1,int j2,vector<vector<int>>& grid,vector<vector<vector<int>>>& dp) // TC-> O(N X M X M X 9) SC-> O(N X M X M) + O(N)
{
    int n=grid.size();
    int m=grid[0].size();
    if(j1<0 || j2<0 || j1>=m || j2>=m) return -1e9;
    if(i==n-1)
    {
        if(j1==j2) return grid[i][j1];
        else return grid[i][j1]+grid[i][j2];
    }

    if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
    int maxi=-1e9;
    for(int dj1=-1;dj1<=1;dj1++)
    {
        for(int dj2=-1;dj2<=1;dj2++)
        {
            if(j1==j2)
            {
                maxi=max(maxi, (grid[i][j1] + memo(i+1,j1+dj1,j2+dj2,grid,dp)));
            }
            else
            {
                maxi=max(maxi, (grid[i][j1] + grid[i][j2] + memo(i+1,j1+dj1,j2+dj2,grid,dp)));
            }
        }
    }
    return dp[i][j1][j2]=maxi;
}
int tabulation(vector<vector<int>>& grid,vector<vector<vector<int>>>& dp) // TC-> O(N X M X M X 9) SC-> O(N X M X M)
{
    int n=grid.size();
    int m=grid[0].size();
    for(int j1=0;j1<m;j1++)
    {
        for(int j2=0;j2<m;j2++)
        {
            if(j1==j2)
            {
                dp[n-1][j1][j2]=grid[n-1][j1];
            }
            else
            {
                dp[n-1][j1][j2]=grid[n-1][j1] + grid[n-1][j2];
            }
        }
    }
    for(int i=n-2;i>=0;i--)
    {
        for(int j1=0;j1<m;j1++)
        {
            for(int j2=0;j2<m;j2++)
            {
                int maxi=-1e9;
                for(int dj1=-1;dj1<=1;dj1++)
                {
                    for(int dj2=-1;dj2<=1;dj2++)
                    {
                        if(j1+dj1>=0 && j1+dj1<m && j2+dj2>=0 && j2+dj2<m)
                        {
                            if(j1==j2)
                            {
                                maxi=max(maxi, (grid[i][j1] + dp[i+1][j1+dj1][j2+dj2]));
                            }
                            else
                            {
                                maxi=max(maxi, (grid[i][j1] + grid[i][j2] + dp[i+1][j1+dj1][j2+dj2]));
                            }
                        }
                    }
                }
                dp[i][j1][j2]=maxi;
            }
        }
    }
    return dp[0][0][m-1];
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
    cout<<"Maximum chocolates picked by Alice and Bob using recursion is: "<<recursion(0,0,m-1,grid)<<endl;

    vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
    cout<<"Maximum chocolates picked by Alice and Bob using memoization is: "<<memo(0,0,m-1,grid,dp)<<endl;

    vector<vector<vector<int>>> dp2(n,vector<vector<int>>(m,vector<int>(m,0)));
    cout<<"Maximum chocolates picked by Alice and Bob using tabulation is: "<<tabulation(grid,dp2)<<endl;
    return 0;
}