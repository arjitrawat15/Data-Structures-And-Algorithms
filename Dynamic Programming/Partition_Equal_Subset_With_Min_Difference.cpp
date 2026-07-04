//to find the minimum absolute difference between the sum of two partitions of an array.
#include<iostream>
#include<vector>
#include<climits>
using namespace std;
bool subsetsumequalstotarget(int target,vector<int>& arr,vector<vector<int>>& dp) // from previous question
{
    int n=arr.size();
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
int min_absolute_difference(vector<int>& arr) // TC-> O(N X total) + O(total/2) SC-> O(N X total)
{
    int n=arr.size();
    int total=0;
    for(int x:arr)
    {
        total+=x;
    }
    vector<vector<int>> dp(n,vector<int>(total+1,0));
    subsetsumequalstotarget(total,arr,dp);
    int mini=INT_MAX;
    for(int i=0;i<=total/2;i++)
    {
        if(dp[n-1][i]==true)
        {
            int s1=i;
            int s2=total-i;
            mini=min(mini,abs(s1-s2));
        }
    }
    return mini;
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
    cout<<"Minimum absolute difference between two partitions is: "<<min_absolute_difference(arr)<<endl;
    return 0;
}