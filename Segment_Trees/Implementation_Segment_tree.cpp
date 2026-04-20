#include<iostream>
#include<vector>
#include<climits>
using namespace std;
class Segment_tree
{
    public:
    int size;
    vector<int> seg;
    Segment_tree(int n,vector<int>& arr)
    {
        size=n;
        seg.resize(4*n,0);
        build(0,n-1,arr,0);
    }
    void build(int l,int r,vector<int>& arr,int node)
    {
        if(l==r)
        {
            seg[node]=arr[l];
            return;
        }
        int mid=l+(r-l)/2;
        build(l,mid,arr,2*node+1);
        build(mid+1,r,arr,2*node+2);
        seg[node]=max(seg[2*node+1],seg[2*node+2]);
    }
    void print()
    {
        for(int i=0;i<4*size;i++)
        {
            cout<<seg[i]<<" ";
        }
        cout<<endl;
    }
};
int main()
{
    int n;
    cout<<"Enter the no of elements: ";
    cin>>n;
    vector<int>arr(n);
    cout<<"Enter the elements: ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    Segment_tree st(n,arr);
    cout<<"Segment Tree: ";
    st.print();
    return 0;
}
