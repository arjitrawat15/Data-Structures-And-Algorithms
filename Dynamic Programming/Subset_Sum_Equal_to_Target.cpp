//to find whether there exists a subset in array whose sum is equal to the given target
#include<iostream>
#include<vector>
using namespace std;
bool recursion(int ind,int target,vector<int>& arr) // TC-> expo
{ 
    if(target==0) return true;
    if(ind==0)
    {
        return arr[0]==target;
    }
    bool nottake=recursion(ind-1,target,arr);
    bool take=false;
    if(arr[ind]<=target)
    {
        take=recursion(ind-1,target-arr[ind],arr);
    }
    return take || nottake;
}
bool memo(int ind,int target,vector<int>& arr,vector<vector<int>>& dp) // TC-> O(N X target) SC-> O(N X target) + O(N)
{
    if(target==0) return true;
    if(ind==0)
    {
        return arr[0]==target;
    }
    if(dp[ind][target]!=-1) return dp[ind][target];
    bool nottake=memo(ind-1,target,arr,dp);
    bool take=false;
    if(arr[ind]<=target)
    {
        take=memo(ind-1,target-arr[ind],arr,dp);
    }
    return dp[ind][target]= take || nottake;
}
bool tabulation(int target,vector<int>& arr)  // TC-> O(N X target) SC-> O(N X target)
{
    int n=arr.size();
    vector<vector<int>> dp(n,vector<int>(target+1,0));
    for(int i=0;i<n;i++)
    {
        dp[i][0]=true;
    }
    if(arr[0]<=target)
    {
        dp[0][arr[0]]=true;
    }
    for(int i=1;i<n;i++)
    {
        for(int t=1;t<=target;t++)
        {
            bool nottake=dp[i-1][t];
            bool take=false;
            if(arr[i]<=t)
            {
                take=dp[i-1][t-arr[i]];
            }
            dp[i][t]= take || nottake;   
        }
    }
    return dp[n-1][target];
}
int main()
{
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    vector<int>arr(n);
    cout<<"Enter the elements of array: ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int target;
    cout<<"Enter the target sum: ";
    cin>>target;
    cout<<"Subset Sum equals to target using recursion is: "<<recursion(n-1,target,arr)<<endl;
    vector<vector<int>> dp(n,vector<int>(target+1,-1));
    cout<<"Subset Sum equals to target using memoization is: "<<memo(n-1,target,arr,dp)<<endl;
    cout<<"Subset Sum equals to target using tabulation is: "<<tabulation(target,arr)<<endl;
    return 0;
}