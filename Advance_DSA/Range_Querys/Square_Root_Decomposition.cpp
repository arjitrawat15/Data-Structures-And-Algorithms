#include<bits/stdc++.h>
using namespace std;
void update(int index,int val,vector<int>& sqr,vector<int>& arr)
{
    int change=val-arr[index];
    sqr[index/sqr.size()]+=change;
    arr[index]=val;
}
int range_sum(int l,int r,vector<int>& sqr,vector<int>& arr)
{
    int blocks=sqr.size();
    int n=arr.size();
    if(l<0) l=0;
    if(r>n-1) r=n-1;
    int sb=l/blocks;
    int eb=r/blocks;
    int sum=0;
    if(sb==eb)
    {
        for(int i=l;i<=r;i++)
        {
            sum+=arr[i];
        }
    }
    else
    {
        for(int i=sb+1;i<eb;i++)
        {
            sum+=sqr[i];
        }
        int start=l;
        int end=(l/blocks+1)*blocks;
        while(start<end)
        {
            sum+=arr[start];
            start++;
        }
        start=(r/blocks)*blocks;
        end=r;
        while(start<=end)
        {
            sum+=arr[start];
            start++;
        }
    }
    return sum;
}
int main()
{
    int n;
    cout<<"Enter the number of elements in array ";
    cin>>n;
    vector<int>arr(n);
    cout<<"Enter the array elements ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int blocks=ceil(sqrt(n));
    vector<int>sqr(blocks,0);
    for(int i=0;i<n;i++)
    {
        sqr[i/blocks]+=arr[i];
    }
    update(0,11,sqr,arr);
    int ans=range_sum(0,6,sqr,arr);
    cout<<ans;
}