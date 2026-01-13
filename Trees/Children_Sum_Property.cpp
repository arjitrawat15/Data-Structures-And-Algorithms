//To implement children sum property in a binary tree (node->data = node->left->data + node->right->data)
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
void child_sum_property(node* root) //TC->O(N) SC->O(N)
{
    if(root==NULL) return;
    int child=0;
    if(root->left)
    {
        child+=root->left->data;
    }
    if(root->right)
    {
        child+=root->right->data;
    }
    if(child>=root->data)
    {
        root->data=child;
    }
    else
    {
        if(root->left) root->left->data=root->data;
        if(root->right) root->right->data=root->data;
    }
    child_sum_property(root->left);
    child_sum_property(root->right);
    int total=0;
    if(root->left)
    {
        total+=root->left->data;
    }
    if(root->right)
    {
        total+=root->right->data;
    }
    if(root->left || root->right)
    {
        root->data=total;
    }
}   
void preorder(node* root)
{
    if(root==NULL) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
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
    child_sum_property(root);
    cout<<"After applying children sum property, binary tree is ";
    preorder(root);
    return 0;
}