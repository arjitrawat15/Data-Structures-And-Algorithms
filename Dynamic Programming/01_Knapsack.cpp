//to maximise the value by adding weight to the knapsack such that it doesnt exceed the maximum capacity of the knapsack.
#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int recursion(int ind,int W,vector<int>& wt,vector<int>& val) // TC-> expo
{
    if(ind==0)
    {
        if(wt[0]<=W) return val[0];
        else return 0;
    }
    int nottake=recursion(ind-1,W,wt,val);
    int take=INT_MIN;
    if(wt[ind]<=W)
    {
        take=val[ind]+recursion(ind-1,W-wt[ind],wt,val);
    }
    return max(take,nottake);
}
int memo(int ind,int W,vector<int>& wt,vector<int>& val,vector<vector<int>>& dp) // TC-> O(N X W) SC-> O(N X W) + O(N)
{
    if(ind==0)
    {
        if(wt[0]<=W) return val[0];
        else return 0;
    }
    if(dp[ind][W]!=-1) return dp[ind][W];
    int nottake=memo(ind-1,W,wt,val,dp);
    int take=INT_MIN;
    if(wt[ind]<=W)
    {
        take=val[ind]+memo(ind-1,W-wt[ind],wt,val,dp);
    }
    return dp[ind][W]=max(take,nottake);
}
int tabulation(int maxW,vector<int>& wt,vector<int>& val) // TC-> O(N X W) SC-> O(N X W) 
{
    int n=wt.size();
    vector<vector<int>>dp(n,vector<int>(maxW+1,0));
    for(int w=wt[0];w<=maxW;w++)
    {
        dp[0][w]=val[0];
    }
    for(int i=1;i<n;i++)
    {
        for(int w=0;w<=maxW;w++)
        {
            int nottake=dp[i-1][w];
            int take=INT_MIN;
            if(wt[i]<=w)
            {
                take=val[i] + dp[i-1][w-wt[i]];
            }
            dp[i][w]=max(take,nottake);
        }
    }
    return dp[n-1][maxW];
}
int single_space_optimisation(int maxW,vector<int>& wt,vector<int>& val) // TC-> O(N X W) SC-> O(N)
{
    int n=wt.size();
    vector<int>prev(maxW+1,0);
    for(int w=wt[0];w<=maxW;w++)
    {
        prev[w]=val[0];
    }
    for(int i=1;i<n;i++)
    {
        for(int w=maxW;w>=0;w--)
        {
            int nottake=prev[w];
            int take=INT_MIN;
            if(wt[i]<=w)
            {
                take=val[i] + prev[w-wt[i]];
            }
            prev[w]=max(take,nottake);
        }
    }
    return prev[maxW];
}
int main()
{
    int n;
    cout<<"Enter the size of weight and values: ";
    cin>>n;
    vector<int> wt(n),val(n);
    cout<<"Enter the weights: ";
    for(int i=0;i<n;i++)
    {
        cin>>wt[i];
    }
    cout<<"Enter the values: ";
    for(int i=0;i<n;i++)
    {
        cin>>val[i];
    }
    int maxW;
    cout<<"Enter the maximum  capacity of knapsack: ";
    cin>>maxW;
    cout<<"Maximum value that can be achieved by recursion is: "<<recursion(n-1,maxW,wt,val)<<endl;
    vector<vector<int>> dp(n,vector<int>(maxW+1,-1));
    cout<<"Maximum value that can be achieved by memoization is: "<<memo(n-1,maxW,wt,val,dp)<<endl;
    cout<<"Maximum value that can be achieved by tabulation is: "<<tabulation(maxW,wt,val)<<endl;
    cout<<"Maximum value that can be achieved by single array space optimisation is: "<<single_space_optimisation(maxW,wt,val)<<endl;
    return 0;
}