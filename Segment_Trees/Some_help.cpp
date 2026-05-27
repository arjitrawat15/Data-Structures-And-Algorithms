/* Bob is playing a game called “Some Help”. In this game, there are N soldiers, where N is an even number. There are also N treasure chests, each 
with a bonus value given by the array Bonus. Here, Bonus[i] denotes the bonus value for the ith chest. The power of each soldier is described by an array 
A of size N. For each i, the power of the ith soldier is an integer between 1 and N/2, and each number between 1 and N/2 occurs exactly twice in A.
The game has N rounds and each round proceeds as follows:
1. For each ith player, Bob finds the first player on their right whose power is a multiple of the power of the ith player. Let’s call this player R.
2. If no such player R is found, Bob does nothing.
3. If such a player R is found, Bob can choose a chest in the range [i, R] that gives the maximum bonus. Let’s call the bonus of this chest as X.
4. The total XP is initially zero and for each round it is increased by X.
Find the total XP that Bob can obtain from all N rounds. */
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
    int query(int l,int r,int low,int high,int node)  
    {
        if(l>high || r<low) return  0;
        else if(l>=low && r<=high) return seg[node];
        int mid=l+(r-l)/2;
        int left=query(l,mid,low,high,2*node+1);
        int right=query(mid+1,r,low,high,2*node+2);
        return max(left,right);
    }
    int range_query(int l,int r)
    {
        return query(0,size-1,l,r,0);
    }
};
vector<int> getDivisors(int num)
{
    vector<int> res;
    for(int i=1;i*i<=num;i++)
    {
        if(num%i==0)
        {
            res.push_back(i);
            if(num/i != i) res.push_back(num/i);
        }
    }
    return res;
}
int main()
{
    int n;
    cout<<"Enter the size of power array: ";
    cin>>n;
    vector<int> arr(n);
    vector<int> bonus(n);
    cout<<"Enter the power array: ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter the bonus array: ";
    for(int i=0;i<n;i++)
    {
        cin>>bonus[i];
    }
    Segment_tree t(n,bonus);
    int size=n/2;
    vector<int> divisor(size+1,-1);
    int total=0;
    for(int i=n-1;i>=0;i--)
    {
        vector<int> vec=getDivisors(arr[i]);
        for(auto it:vec)
        {
            divisor[it]=i;
        }
        int r=divisor[arr[i]];
        if(divisor[arr[i]]==-1)
        {
            continue;
        }
        else
        {
            if(r<n)
            {
                total+=t.range_query(i,r);
            }
        }
    }
    cout<<"Total XP points is: "<<total<<endl;
    return 0;
}