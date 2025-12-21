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
        node* curr=q.front();
        q.pop();
        if(curr->left==NULL)
        {
            curr->left=new node(val);
            break;
        }
        else
        {
            q.push(curr->left);
        }
        if(curr->right==NULL)
        {
            curr->right=new node(val);
            break;
        }
        else
        {
            q.push(curr->right);
        }
    }
    return root;
}
void inorder(node* root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main()
{
    int n,val;
    node* root=NULL;
    cout<<"Enter the number of nodes: ";
    cin>>n;
    cout<<"Enter the nodes: ";
    for(int i=0;i<n;i++)
    {
        cin>>val;
        root=insert(root,val);
    }
    cout<<"Inorder Traversal is: ";
    inorder(root);
    return 0;
}