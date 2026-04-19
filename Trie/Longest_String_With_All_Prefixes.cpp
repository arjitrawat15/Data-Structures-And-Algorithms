//To find the longest string which has all its prefix as a string in the array.
//TC-> O(N x len)
#include<iostream>
#include<vector>
using namespace std;
struct node
{
    node* child[26];
    bool isLeaf;
    node()
    {
        for(int i=0;i<26;i++)
        {
            child[i]=NULL;
        }
        isLeaf=false;
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
    void insert(string word)
    {
        node* curr=root;
        int n=word.size();
        for(int i=0;i<n;i++)
        {
            int ch=word[i]-'a';
            if(!curr->child[ch]) //doesn't exist
            {
                curr->child[ch]=new node();
            }
            curr=curr->child[ch];
        }
        curr->isLeaf=true;
    }
    bool checkifPrefixExists(string word)
    {
        node* curr=root;
         int n=word.size();
        for(int i=0;i<n;i++)
        {
            int ch=word[i]-'a';
            if(curr->child[ch])
            {
                curr=curr->child[ch];
                if(curr->isLeaf==false)
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};
int main()
{
    Trie t;
    int n;
    cout<<"Enter the size of array"<<endl;
    cin>>n;
    cout<<"Enter the strings: ";
    vector<string> arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        t.insert(arr[i]);
    }
    string longest="";
    for(auto it:arr)
    {
        if(t.checkifPrefixExists(it))
        {
            if(it.size()>longest.size())
            {
                longest=it;
            }
            else if(it.size()==longest.size() && it<longest) //lexicographically smaller
            {
                longest=it;
            }
        }
    }
    if(longest=="") 
    {
        cout<<"None";
    }
    else
    {
        cout<<"Longest string with all prefixes is: "<<longest<<endl;
    }
    return 0;
}