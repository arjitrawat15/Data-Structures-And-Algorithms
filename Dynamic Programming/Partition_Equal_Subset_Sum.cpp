//to find whether there exists a partition for which both subsets will have equal sum.
#include<iostream>
#include<vector>
using namespace std;
bool subsetsumequalstotarget(int target,vector<int>& arr) // from previous question
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
bool partition_equal_subset_sum(vector<int>& arr) // TC-> O(N X S/2) SC-> O(N X S/2)
{
    int total=0;
    for(int x:arr)
    {
        total+=x;
    }
    if(total%2!=0) return false;
    return subsetsumequalstotarget(total/2,arr);
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
    cout<<"Partition equal subset sum exists: "<<partition_equal_subset_sum(arr)<<endl;
    return 0;
}