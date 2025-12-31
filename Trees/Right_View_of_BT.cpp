//To calculate right view of a binary tree
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
void helper(node* root,vector<int>& res,int level)
{
    if(root==NULL)
    {
        return;
    }
    if(level==res.size())
    {
        res.push_back(root->data);
    }
    if(root->right) helper(root->right,res,level+1);
    if(root->left) helper(root->left,res,level+1);
}
void right_view(node* root) //TC->O(N) SC->O(h)
{
    vector<int>res;
    helper(root,res,0);
    cout<<"Right view of binary tree is: ";
    for(int i=0;i<res.size();i++)
    {
        cout<<res[i]<<" ";
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
    right_view(root);
    return 0;
}