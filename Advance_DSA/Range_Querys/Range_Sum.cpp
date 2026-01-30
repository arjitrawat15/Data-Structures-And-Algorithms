To calculate the sum of a range and update a value at a index.
( Brute force ) 
TC-> O(N x N) SC->(1)

#include<bits/stdc++.h>
using namespace std;
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
            arr[index]=val;
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
            int ans=0;
            for(int i=l;i<=r;i++)
            {
                ans+=arr[i];
            }
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
