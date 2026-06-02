//Find the maximum sum of non adjacent elements but last and first element are also adjacent using recursion and dynamic programming
#include<iostream>
#include<vector>
using namespace std;
int rob(int start,int end,vector<int>& arr) // TC-> O(N) SC->O(1) using space optimisation technique
{
    int prev=arr[start];
    int prev2=0;
    for(int i=start+1;i<=end;i++)
    {
        int pick=arr[i];
        if(i-start>1)
        {
            pick+=prev2;
        }
        int notpick=0+prev;
        int curr=max(pick,notpick);
        prev2=prev;
        prev=curr;
    }  
    return prev;
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
    cout<<"Maximum sum of non-adjacent elements using tabulation is: "<< max(rob(1,n-1,arr),rob(0,n-2,arr))<<endl;
    return 0;
}