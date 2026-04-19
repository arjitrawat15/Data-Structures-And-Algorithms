//To find the maximum XOR with element of array for queries but element should be less than ai where queries(i)=xi,ai
// TC->  O(Q X 32) + O(N X 32) for main part
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct node
{
    node* child[2];
    node()
    {
        child[0]=NULL;
        child[1]=NULL;
    }
};
class Trie
{
    public:
    node* root;
    Trie()
    {
        root=new node();
    }
    void insert(int num)
    {
        node* curr=root;
        for(int i=31;i>=0;i--)
        {
            int bit=(num>>i) & 1; //to get the bit at the i th position
            if(!curr->child[bit]) //does not contain the bit
            {
                curr->child[bit]=new node();
            }
            curr=curr->child[bit];
        }
    }
    int getMax(int num)
    {
        int maxi=0;
        node* curr=root;
        for(int i=31;i>=0;i--)
        {
            int bit=(num>>i) & 1;
            if(curr->child[1-bit])
            {
                maxi=maxi | (1<<i); 
                curr=curr->child[1-bit];
            }
            else
            {
                curr=curr->child[bit];
            }
        }
        return maxi;
    }
};
int main()
{
    Trie t;
    int n,q;
    cout<<"Enter the size of array: ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the array: ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter the number of queries: ";
    cin>>q;
    vector<vector<int>> queries(q,vector<int>(2));
    cout<<"Enter the queries: ";
    for(int i=0;i<q;i++)
    {
        cin>>queries[i][0];
        cin>>queries[i][1];
    }
    sort(arr.begin(),arr.end()); // O(N logN)
    vector<pair<int,pair<int,int>>> Q;
    for(int i=0;i<q;i++)
    {
        Q.push_back({queries[i][1],{queries[i][0],i}});
    }
    sort(Q.begin(),Q.end()); // O(Q log Q)
    vector<int> ans(q);
    int ind=0;
    for(int i=0;i<q;i++) // O(Q X 32) + O(N X 32)
    {
        int ai=Q[i].first;
        int xi=Q[i].second.first;
        int index=Q[i].second.second;
        while(ind<arr.size() && arr[ind]<=ai)
        {
            t.insert(arr[ind]);
            ind++;
        }
        if(ind==0)
        {
            ans[index]=-1;
        }
        else
        {
            ans[index]=t.getMax(xi);
        }
    }
    cout<<"Maximum XOR with elements of array are: ";
    for(auto it:ans)
    {
        cout<<it<<" ";
    } 
    return 0;
}