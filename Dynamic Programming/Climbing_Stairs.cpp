// Find the total no of ways required to reach the nth stair with either 1 or 2 steps using recusrion and dynamic programming.
#include<iostream>
#include<vector>
using namespace std;
int recursion(int n) // TC-> expo
{
    if(n==0) return 1;
    if(n==1) return 1;
    return recursion(n-1)+recursion(n-2);
}
int memo(int n,vector<int>& dp) // TC-> O(N) SC->o(N+N) 
{
    if(n==0) return 1;
    if(n==1) return 1;
    if(dp[n]!=-1) return dp[n];
    return dp[n]=memo(n-1,dp)+memo(n-2,dp);
}
int tabulation(int n,vector<int>& dp) // TC-> O(N) SC-> O(N)
{
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=n;i++)
    {
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}
int main()
{
    int n;
    cout<<"Enter the nth stair to be climbed: ";
    cin>>n;
    cout<<"Total no of ways using recursion is: "<<recursion(n)<<endl;
    vector<int>dp1(n+1,-1);
    cout<<"Total no of ways using memoization is: "<<memo(n,dp1)<<endl;
    vector<int>dp2(n+1,-1);
    cout<<"Total no of ways using tabulation is: "<<tabulation(n,dp2)<<endl;
    return 0;
}