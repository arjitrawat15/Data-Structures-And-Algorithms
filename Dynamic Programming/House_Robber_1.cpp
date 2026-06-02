//Find the maximum sum of non adjacent elements using recursion and dynamic programming
#include<iostream>
#include<vector>
using namespace std;
int recursion(int ind,vector<int>& arr) // TC-> expo
{
    if(ind==0) return arr[0];
    if(ind<0) return 0;
    int pick=arr[ind]+recursion(ind-2,arr);
    int notpick=0+recursion(ind-1,arr);
    return max(pick,notpick);
}
int memo(int ind,vector<int>& arr,vector<int>& dp) // TC-> O(N) SC->O(N+N)
{
    if(ind==0) return arr[0];
    if(ind<0) return 0;
    if(dp[ind]!=-1) return dp[ind];
    int pick=arr[ind]+memo(ind-2,arr,dp);
    int notpick=0+memo(ind-1,arr,dp);
    return dp[ind]=max(pick,notpick);
}
int tabulation(int n,vector<int>& arr,vector<int>& dp) // TC-> O(N) SC->O(N)
{
    dp[0]=arr[0];
    for(int i=1;i<n;i++)
    {
        int pick=arr[i];
        if(i>1)
        {
            pick+=dp[i-2];
        }
        int notpick=0+dp[i-1];
        dp[i]=max(pick,notpick);
    }  
    return dp[n-1];
}
int main()
{
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    vector<int>arr(n);
    cout<<"Enter the array: ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"Maximum sum of non-adjacent elements using recursion is: "<<recursion(n-1,arr)<<endl;
    vector<int>dp1(n,-1);
    cout<<"Maximum sum of non-adjacent elements using memoization is: "<<memo(n-1,arr,dp1)<<endl;
    vector<int>dp2(n,-1);
    cout<<"Maximum sum of non-adjacent elements using tabulation is: "<<tabulation(n,arr,dp2)<<endl;
    return 0;
}