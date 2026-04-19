//To count the number of distinct substrings present in a string
// TC-> O(N^2)
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
    int countDistinctSubstrings(string word)
    {
        int n=word.size();
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            node* curr=root;
            for(int j=i;j<n;j++)
            {
                int ch=word[j]-'a';
                if(!curr->child[ch])
                {
                    cnt++;
                    curr->child[ch]=new node();
                }
                curr=curr->child[ch];
            }
        }
        return cnt+1;
    }
};
int main()
{
    Trie t;
    string word;
    cout<<"Enter the string: ";
    cin>>word;
    cout<<"Number of distinct substrings in a string is: "<<t.countDistinctSubstrings(word)<<endl;
    return 0;
}