//to count the number of partitions which will have the same given difference. 
#include<iostream>
#include<vector>
using namespace std;
int count_subsets_with_given_sum(int target,vector<int>& arr) // from prev ques
{
    int n=arr.size();
    vector<vector<int>> dp(n,vector<int>(target+1,0));
    for(int i=0;i<n;i++)
    {
        dp[i][0]=1;
    }
    if(arr[0]<=target)
    {
        dp[0][arr[0]]=1;
    }
    for(int i=1;i<n;i++)
    {
        for(int t=1;t<=target;t++)
        {
            int nottake=dp[i-1][t];
            int take=0;
            if(arr[i]<=t)
            {
                take=dp[i-1][t-arr[i]];
            }
            dp[i][t]=take+nottake;
        }
    }
    return dp[n-1][target];
}
int count_partitions_with_given_diff(int diff,vector<int>& arr) // TC-> O(N X S2) SC-> O(N X S2)
{
    int n=arr.size();
    int total=0;
    for(int x:arr)
    {
        total+=x;
    }
    // S1-S2=Diff and S1+S2=S
    // S1=S-S2 then (S-S2)-S2=Diff
    // From this S - Diff= 2S2
    // S2=(S-Diff) / 2 so calculate this to find partitions with given difference
    int new_target=total-diff;
    if(new_target<0 || new_target%2!=0) return 0;
    new_target=new_target/2;
    return count_subsets_with_given_sum(new_target,arr);
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
    int diff;
    cout<<"Enter the difference: ";
    cin>>diff;
    cout<<"Number of partitions with a given difference is: "<<count_partitions_with_given_diff(diff,arr)<<endl;
    return 0;
}