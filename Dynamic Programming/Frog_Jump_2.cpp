// Find the minimum energy required by the frog to jump to reach the last step by jumping at any k step from height i to j 
// where energy=height[j]-height[i] using recursion and dynamic programming.
#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int recursion(int ind,vector<int>& arr,int k) // TC-> expo
{
    if(ind==0) return 0;
    int mini=INT_MAX;
    for(int i=1;i<=k;i++)
    {
        if(ind-i>=0)
        {
            int cost=recursion(ind-i,arr,k) + abs(arr[ind]-arr[ind-i]);
            mini=min(mini,cost);
        }
    }
    return mini;
}
int memo(int ind,vector<int>& arr,vector<int>& dp,int k) // TC-> O(N) SC-> O(N+N)
{
    if(ind==0) return 0;
    if(dp[ind]!=-1) return dp[ind];
    int mini=INT_MAX;
    for(int i=1;i<=k;i++)
    {
        if(ind-i>=0)
        {
            int cost=memo(ind-i,arr,dp,k) + abs(arr[ind]-arr[ind-i]);
            mini=min(mini,cost);
        }
    }
    return dp[ind]=mini;
}
int tabulation(int n,vector<int>& arr,vector<int>& dp,int k) // TC-> O(N) SC->O(N)
{
    dp[0]=0;
    for(int i=1;i<n;i++)
    {
        int mini=INT_MAX;
        for(int j=1;j<=k;j++)
        {
            if(i-j>=0)
            {
                int cost=dp[i-j] + abs(arr[i]-arr[i-j]);
                mini=min(mini,cost);
            }
        }
        dp[i]=mini;
    }
    return dp[n-1];
}
int main()
{
    int n;
    cout<<"Enter the no of steps: ";
    cin>>n;
    vector<int>arr(n);
    cout<<"Enter the heights of the steps: ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int k;
    cout<<"Enter the k steps: ";
    cin>>k;
    cout<<"Min energy required using recursion is: "<<recursion(n-1,arr,k)<<endl;
    vector<int>dp1(n,-1);
    cout<<"Min energy required using memoization is: "<<memo(n-1,arr,dp1,k)<<endl;
    vector<int>dp2(n,-1);
    cout<<"Min energy required using tabulation is: "<<tabulation(n,arr,dp2,k)<<endl;
    return 0;
}
