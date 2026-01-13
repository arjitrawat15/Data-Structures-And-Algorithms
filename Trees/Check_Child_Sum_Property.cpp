//To check children sum property in a binary tree
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
bool check(node* root) //TC-O(N) SC->O(h)
{
    if(root==NULL || (root->left==NULL && root->right==NULL))
    {
        return true;
    }
    int sum=0;
    if(root->left)
    {
        sum+=root->left->data;
    }
    if(root->right)
    {
        sum+=root->right->data;
    }
    return root->data==sum && check(root->left) && check(root->right);
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
    bool ans=check(root);
    if(ans)
    {
        cout<<"Binary tree has children sum property "<<endl;
    }
    else
    {
        cout<<"Binary tree does not have children sum property "<<endl;
    }
    return 0;
}