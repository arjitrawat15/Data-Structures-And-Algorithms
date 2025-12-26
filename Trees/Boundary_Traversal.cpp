//To calculate the boundary traversal of a binary tree
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
bool isLeaf(node* curr)
{
    if(curr->left==NULL && curr->right==NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void left_boundary(node* root,vector<int>& res)
{
    node* curr=root->left;
    while(curr!=NULL)
    {
        if(!isLeaf(curr))
        {
            res.push_back(curr->data);
        }
        if(curr->left!=NULL)
        {
            curr=curr->left;
        }
        else
        {
            curr=curr->right;
        }
    }
}
void right_boundary(node* root,vector<int>& res)
{
    node* curr=root->right;
    vector<int>temp;
    while(curr!=NULL)
    {
        if(!isLeaf(curr))
        {
            temp.push_back(curr->data);
        }
        if(curr->right!=NULL)
        {
            curr=curr->right;
        }
        else
        {
            curr=curr->left;
        }
    }
    for(int i=temp.size()-1;i>=0;i--)
    {
        res.push_back(temp[i]);
    }
}
void addLeaves(node* root,vector<int>& res)
{
    if(root == NULL) return;

    if(isLeaf(root))
    {
        res.push_back(root->data);
    }
    addLeaves(root->left,res);
    addLeaves(root->right,res);
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
    vector<int>res;
    if(!isLeaf(root)) res.push_back(root->data);
    left_boundary(root,res);
    addLeaves(root,res);
    right_boundary(root,res);
    cout<<"Boundary traversal of Binary tree is: "; //TC-> O(N)+O(h)+O(h) ~ O(N) SC->O(N)
    for(int i=0;i<res.size();i++)
    {
        cout<<res[i]<<" ";
    }
    return 0;
}