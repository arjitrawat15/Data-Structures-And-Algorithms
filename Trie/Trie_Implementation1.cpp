// To perform insertion, searching, startswith and deletion operations in a trie.
// TC-> O(N) for all the operations (N is the length of a word).
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
    bool search(string word)
    {
        node* curr=root;
        int n=word.size();
        for(int i=0;i<n;i++)
        {
            int ch=word[i]-'a';
            if(!curr->child[ch]) //doesn't exist
            {
                return false;
            }
            curr=curr->child[ch];
        }
        return curr->isLeaf;
    }
    bool startsWith(string prefix)
    {
        node* curr=root;
        int n=prefix.size();
        for(int i=0;i<n;i++)
        {
            int ch=prefix[i]-'a';
            if(!curr->child[ch]) //doesn't exist
            {
                return false;
            }
            curr=curr->child[ch];
        }
        return true;
    }
    bool isEmpty(node* root)
    {
        for(int i=0;i<26;i++)
        {
            if(root->child[i])
            {
                return false; //not empty
            }
        }
        return true;
    }
    node* deleteword(node* curr,string key,int i)
    {
        if(curr==NULL) return NULL;
        if(i==key.size())
        {
            if(curr->isLeaf)
            {
                curr->isLeaf=false;
            }
            if(isEmpty(curr))
            {
                delete (curr);
                curr=NULL;
            }
            return curr;
        }
        int ind=key[i]-'a';
        curr->child[ind]=deleteword(curr->child[ind],key,i+1); //recursion
        if(isEmpty(curr) && curr->isLeaf==false)
        {
            delete (curr);
            curr=NULL;
        }
        return curr;
    }
    void remove(string key)
    {
        if(!search(key)) return;   
        root=deleteword(root,key,0);
        if(root==NULL)
        {
            root=new node();
        }
    }
};
int main()
{
    Trie t;
    //Insertion 
    t.insert("apple");
    t.insert("apps");
    t.insert("apxl");
    t.insert("bac");
    t.insert("bat");

    //Searching
    if(t.search("apps")) cout<<"True"<<endl;
    else cout<<"False"<<endl;
    if(t.search("apxy")) cout<<"True"<<endl;
    else cout<<"False"<<endl;

    //Startswith (checking if prefix of any word)
    if(t.startsWith("appl")) cout<<"True"<<endl;
    else cout<<"False"<<endl;

    //Deletion
    t.remove("apple");
    if(t.search("apple")) cout<<"True"<<endl;
    else cout<<"False"<<endl;

    return 0;
}