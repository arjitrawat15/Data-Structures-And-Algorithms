Square Root Decomposition 
There are given N queries and for each query - 
Option 1. Update the value at index i by given new value (1,index,val) is given 
Option 2. Return the sum from l index to r index of the array.  (2,l,r) is given
//Total time complexity -> O( Q x sqrt(N)) Space complexity -> O(sqrt(N))

#include<bits/stdc++.h>
using namespace std;
void update(int index,int val,vector<int>& sqr,vector<int>& arr) // TC-> O(1)
{
    int change=val-arr[index];
    sqr[index/sqr.size()]+=change;
    arr[index]=val;
}
int range_sum(int l,int r,vector<int>& sqr,vector<int>& arr) // O(sqrt(N))
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
    cout<<"Enter the number of elements in array: ";
    cin>>n;
    vector<int>arr(n);
    cout<<"Enter the array elements: ";
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
    int q;
    cout<<"Enter the no of queries: ";
    cin>>q;
    for(int i=0;i<q;i++)
    {
        int ch;
        cout<<"Enter the choice: ";
        cin>>ch;
        if(ch==1)
        {
            cout<<"Enter the index to be changed: ";
            int index;
            cin>>index;
            cout<<"Enter the new value: ";
            int val;
            cin>>val;
            update(0,11,sqr,arr);
            cout<<"Value added successfully"<<endl;
            cout<<"Array after updation is: ";
            for(int i=0;i<n;i++)
            {
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
        else if(ch==2)
        {
            int l,r;
            cout<<"Enter the range: ";
            cin>>l;
            cin>>r;
            int ans=range_sum(l,r,sqr,arr);
            cout<<"Sum of the range is: "<<ans<<endl;
        }
        else
        {
            cout<<"Wrong choice !";
            break;
        }
    }
    return 0;
}
