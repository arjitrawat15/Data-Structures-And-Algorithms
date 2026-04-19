//To find the maximum XOR of two numbers in two different arrays.
// TC-> O(N x 32) + O(M x 32)
#include<iostream>
#include<vector>
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
            int bit=(num>>i) & 1; //to get the bit at ith position
            if(curr->child[1-bit]) //if the bit at the i th position is opposite means we include it to get the maximum no.  
            // as 1^0 = 1 && 0^1= 1 (XOR)
            {
                maxi=maxi | (1<<i); // set at ith position
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
    int n,m;
    cout<<"Enter the size of array1 and array2: ";
    cin>>n>>m;
    vector<int>arr1(n);
    vector<int>arr2(m);
    cout<<"Enter the first array: ";
    for(int i=0;i<n;i++)
    {
        cin>>arr1[i];
        t.insert(arr1[i]); //insert every element of arr1 in trie
    }
    cout<<"Enter the second array: ";
    for(int i=0;i<m;i++)
    {
        cin>>arr2[i];
    }
    int maxi=0;
    for(auto it:arr2)
    {
        maxi=max(maxi,t.getMax(it));
    }
    cout<<"Maximum XOR of two numbers from two different arrays are: "<<maxi<<endl;
    return 0;
}