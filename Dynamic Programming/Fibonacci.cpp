// Find the fibonacci term for the nth number using recursion and dynamic programming.
#include<iostream>
#include<vector>
using namespace std;
int recursion(int n) // TC-> expo
{
    if(n<=1)
    {
        return n;
    }
    return recursion(n-1)+recursion(n-2);
}
int memo(int n,vector<int>& dp) // TC-> O(N) SC-> O(N+N) for recursion and dp array
{
    if(n<=1)
    {
        return n;
    }
    if(dp[n]!=-1) return dp[n];
    return dp[n]=memo(n-1,dp)+memo(n-2,dp);
}
int tabulation(int n,vector<int>& dp) // TC-> O(N) SC-> O(N) for dp array
{
    dp[0]=0;
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
    cout<<"Enter the nth fibonacci term to be generated: ";
    cin>>n;
    cout<<"Nth term of fibonacci series using recursion is: "<<recursion(n)<<endl;
    vector<int>dp1(n+1,-1);
    cout<<"Nth term of fibonacci series using memoization is: "<<memo(n,dp1)<<endl;
    vector<int>dp2(n+1,-1);
    cout<<"Nth term of fibonacci series using tabulation is: "<<tabulation(n,dp2)<<endl;
    return 0;
}