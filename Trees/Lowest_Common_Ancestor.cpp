//To calculate the lowest common ancestor of two nodes in a binary tree
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
node* findNode(node* root,int val) //Included in the question
{
    if(root==NULL)
    {
        return NULL;
    }
    if(root->data==val) return root;
    node* left=findNode(root->left,val);
    node* right=findNode(root->right,val);
    if(left || right)
    {
        return left? left:right;
    }
    else
    {
        return NULL;
    }
}
node* lowest_ancestor(node * root,node* p,node* q) //TC->O(N) SC->O(N)
{
    if(root==NULL || root==p || root==q)
    {
        return root;
    }
    node* left=lowest_ancestor(root->left,p,q);
    node* right=lowest_ancestor(root->right,p,q);
    if(left!=NULL && right!=NULL)
    {
        return root;
    }
    else if(right==NULL)
    {
        return left;
    }
    else
    {
        return right;
    }
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
    int val1,val2;
    cout<<"Enter the nodes to find the lowest common ancestor: ";
    cin>>val1>>val2;
    node* p=findNode(root,val1);
    node* q=findNode(root,val2);
    node* ans=lowest_ancestor(root,p,q);
    cout<<"Lowest common ancestor of "<<val1<<" and "<<val2<<" is "<<ans->data<<endl;
    return 0;
}