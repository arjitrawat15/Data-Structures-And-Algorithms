#include<iostream>
#include<vector>
using namespace std;
class Segment_Tree
{
    public:
    int size;
    vector<int> seg;
    Segment_Tree(int n,vector<int>& arr)
    {
        size=n;
        seg.resize(4*n,0);
        build(0,n-1,arr,0);
    }
    int gcd(int a,int b)
    {
        if(a==0)
        {
            return b;
        }
        return gcd(b%a,a);
    }
    int lcm(int a,int b)
    {
        return (a*b)/gcd(a,b);
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
        seg[node]=lcm(seg[2*node+1],seg[2*node+2]);
    }
    int query(int l,int r,int low,int high,int node)
    {
        if(l>high || r<low) return 1;
        else if(l>=low && r<=high) return seg[node];
        int mid=l+(r-l)/2;
        int left=query(l,mid,low,high,2*node+1);
        int right=query(mid+1,r,low,high,2*node+2);
        return lcm(left,right);
    }
    int range_query(int l,int r)
    {
        return query(0,size-1,l,r,0);
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
    Segment_Tree st(n,arr);
    int l,r;
    cout<<"Enter query range: ";
    cin>>l>>r;
    cout<<"LCM of the range is: "<<st.range_query(l, r)<<endl;
    return 0;
}