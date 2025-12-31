//To calculate the path of a node from the root node in a binary tree
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
bool getPath(node* root,vector<int>& res,int target) //TC->O(N) SC->O(h
{
    if(root==NULL)
    {
        return false;
    }
    res.push_back(root->data);
    if(root->data==target)
    {
        return true;
    }
    bool left=getPath(root->left,res,target);
    bool right=getPath(root->right,res,target);
    if(left || right)
    {
        return true;
    }
    res.pop_back();
    return false;
}
int main()
{
    node* root=NULL;
    int n,val,target;
    cout<<"Enter the number of nodes: ";
    cin>>n;
    cout<<"Enter the nodes: ";
    for(int i=0;i<n;i++)
    {
        cin>>val;
        root=insert(root,val);
    }
    cout<<"Enter the target node: ";
    cin>>target;
    if(target==root->data)
    {
        cout<<root->data;
        return 0;
    }
    vector<int>res;
    bool found=getPath(root,res,target);
    if(found==true)
    {
        cout<<"Path from the root node to the target node: ";
        for(int i=0;i<res.size();i++)
        {
            cout<<res[i]<<" ";
        }
    }
    else
    {
        cout<<"Target node not present in the binary tree";
    }
    return 0;
}