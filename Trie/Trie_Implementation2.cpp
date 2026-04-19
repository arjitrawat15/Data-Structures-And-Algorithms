// To perform insertion, countwordsEqualto, countwordsStartingwith and erase operations in a trie.
// TC-> O(N) for all the operations (N is the length of a word).
#include<iostream>
#include<vector>
using namespace std;
struct node
{
    node* child[26];
    int endswith=0;
    int countpref=0;
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
            curr->countpref++;
        }
        curr->endswith++;
    }
    int countwordsEqualto(string word)
    {
        node* curr=root;
        int n=word.size();
        for(int i=0;i<n;i++)
        {
            int ch=word[i]-'a';   
            if(!curr->child[ch]) //doesn't exist
            {
                return 0;
            }
            curr=curr->child[ch];
        }
        return curr->endswith; //how many times word is present in trie
    }
    int countwordsStartingwith(string prefix)
    {
        node* curr=root;
        int n=prefix.size();
        for(int i=0;i<n;i++)
        {
            int ch=prefix[i]-'a';   
            if(!curr->child[ch]) //doesn't exist
            {
                return 0;
            }
            curr=curr->child[ch];
        }
        return curr->countpref; //prefix of how many words
    }
    void erase(string word) //doesn't delete the node just remove its existence
    {
        node* curr=root;
        int n=word.size();
        for(int i=0;i<n;i++)
        {
            int ch=word[i]-'a'; 
            if(curr->child[ch]) //exists
            {
                curr=curr->child[ch];
                curr->countpref--;
            }
            else
            {
                return;
            }
        }
        curr->endswith--;
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
        return curr->endswith!=0;
    }
};
int main()
{
    Trie t;
    t.insert("apple");
    t.insert("apple");
    t.insert("apps");
    t.insert("apps");
    //Count words equal to
    cout<<"Apple is present in trie -> "<<t.countwordsEqualto("apple")<<" times"<<endl;
    cout<<"Apps is present in trie -> "<<t.countwordsEqualto("apps")<<" times"<<endl;

    //Count words starting with
    cout<<"Words that start with app are "<<t.countwordsStartingwith("app")<<endl;

    //Erase
    t.erase("apple");
    t.erase("apple");
    if(t.search("apple")) cout<<"True"<<endl;
    else cout<<"False"<<endl;
    return 0;
}