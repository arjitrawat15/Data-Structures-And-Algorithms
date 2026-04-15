//To calculate the order of characters in alien language. (Using Kahn's algorithm)
//TC-> 2 X O(N+E) + O(2N)
//SC-> O(2N)
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the number of words: ";
    cin>>n;
    int k;
    cout<<"Enter the number of starting alphabets: ";
    cin>>k;
    cout<<"Enter the words: ";
    vector<string> words(n);
    for(int i=0;i<n;i++)
    {
        cin>>words[i];
    }
    vector<vector<int>> adj(k);
    for(int i=0;i<n-1;i++)
    {
        string s1=words[i];
        string s2=words[i+1];
        int len=min(s1.size(),s2.size());
        for(int ptr=0;ptr<len;ptr++)
        {
            if(s1[ptr]!=s2[ptr])
            {
                adj[s1[ptr]-'a'].push_back(s2[ptr]-'a');
                break;
            }
        }
    }
    vector<int> indegree(k,0);
    for(int i=0;i<k;i++)
    {
        for(auto it:adj[i])
        {
            indegree[it]++;
        }
    }
    queue<int>q;
    for(int i=0;i<k;i++)
    {
        if(indegree[i]==0)
        {
            q.push(i);
        }
    }
    vector<int> order;
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        order.push_back(node);
        for(auto it:adj[node])
        {
            indegree[it]--;
            if(indegree[it]==0)
            {
                q.push(it);
            }
        }   
    }
    if(order.size()<k)
    {
        cout<<"Cycle detected, invalid dictionary"<<endl;
        return 0;
    }
    string ans="";
    for(auto it:order)
    {
        ans=ans+char(it+'a');
    }
    cout<<"Order of the characters in alien dictionary is: "<<ans;
    return 0;
}