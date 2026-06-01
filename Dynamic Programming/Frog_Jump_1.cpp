// Find the minimum energy required by the frog to jump to reach the last step by jumping from height i to j ( 1 or 2 steps ) 
// where energy=height[j]-height[i] using recursion and dynamic programming.
#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int recursion(int ind,vector<int>& arr) // TC-> expo
{
    if(ind==0) return 0;
    int one=recursion(ind-1,arr) + abs(arr[ind]-arr[ind-1]);
    int two=INT_MAX;
    if(ind>1)
    {
        two=recursion(ind-2,arr) + abs(arr[ind]-arr[ind-2]);
    }
    return min(one,two);
}
int memo(int ind,vector<int>& arr,vector<int>& dp) // TC-> O(N) SC-> O(N+N)
{
    if(ind==0) return 0;
    if(dp[ind]!=-1) return dp[ind];
    int one=memo(ind-1,arr,dp) + abs(arr[ind]-arr[ind-1]);
    int two=INT_MAX;
    if(ind>1)
    {
        two=memo(ind-2,arr,dp) + abs(arr[ind]-arr[ind-2]);
    }
    return dp[ind]=min(one,two);
}
int tabulation(int n,vector<int>& arr,vector<int>& dp) // TC-> O(N) SC->O(N)
{
    dp[0]=0;
    for(int i=1;i<n;i++)
    {
        int one=dp[i-1] + abs(arr[i]-arr[i-1]);
        int two=INT_MAX;
        if(i>1)
        {
            two=dp[i-2] + abs(arr[i]-arr[i-2]);
        }
        dp[i]=min(one,two);   
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
    cout<<"Min energy required using recursion is: "<<recursion(n-1,arr)<<endl;
    vector<int>dp1(n,-1);
    cout<<"Min energy required using memoization is: "<<memo(n-1,arr,dp1)<<endl;
    vector<int>dp2(n,-1);
    cout<<"Min energy required using tabulation is: "<<tabulation(n,arr,dp2)<<endl;
    return 0;
}
