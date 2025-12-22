//Iterative Postorder using 2 stack
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
void postorder1(node* root)
{
    if(root==NULL)
    {
        cout<<"NULL";
        return;
    }
    stack<node*>st1;
    stack<node*>st2;
    st1.push(root);
    while(!st1.empty())
    {
        node* curr=st1.top();
        st1.pop();
        st2.push(curr);
        if(curr->left!=NULL)
        {
            st1.push(curr->left);
        }
        if(curr->right!=NULL)
        {
            st2.push(curr->right);
        }
    }
    while(!st2.empty())
    {
        node* curr=st2.top();
        st2.pop();
        cout<<curr->data<<" ";
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
    cout<<"Postorder Traversal is: ";
    postorder1(root);
    return 0;
}