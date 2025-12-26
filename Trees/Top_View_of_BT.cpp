//To calculate top view of a binary tree
#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node* left;
    node* right;

    node(int val)
    {
        data=val;
        left=right=NULL;
    }
};
node* insert(node* root,int val)
{
    if(root==NULL)
    {
        return new node(val);
    }
    queue<node*>q;
    q.push(root);
    while(!q.empty())
    {
        node* temp=q.front();
        q.pop();
        if(temp->left==NULL)
        {
            temp->left=new node(val);
            break;
        }
        else
        {
            q.push(temp->left);
        }
        if(temp->right==NULL)
        {
            temp->right=new node(val);
            break;
        }
        else
        {
            q.push(temp->right);
        }
    }
    return root;
}
vector<int> top_view(node* root) //TC-> O(N)xlog n SC->O(2N)
{
    if(root==NULL)
    {
        return;
    }
    map<int,int>mpp; //level,data
    queue<pair<node*,int>>q; //node,level
    q.push({root,0});
    while(!q.empty())
    {
        auto it=q.front();
        q.pop();
        node* curr=it.first;
        int line=it.second;
        if(mpp.find(line)==mpp.end())
        {
            mpp[line]=curr->data;
        }
        if(curr->left!=NULL)
        {
            q.push({curr->left,line-1});
        }
        if(curr->right!=NULL)
        {
            q.push({curr->right,line+1});
        }
    }
    for(auto it:mpp)
    {
        cout<<it.second<<" ";
    }
}
int main()
{
    node* root=NULL;
    int n,val;
    cout<<"Enter the number of nodes: ";
    cin>>n;
    cout<<"Enter the nodes: ";
    for(int i=0;i<n;i++)
    {
        cin>>val;
        root=insert(root,val);
    }
    cout<<"Top View of a binary tree is: ";
    top_view(root);
    return 0;
}