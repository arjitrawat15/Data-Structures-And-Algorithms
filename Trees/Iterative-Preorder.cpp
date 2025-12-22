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
void preorder(node* root)
{
    if(root==NULL)
    {
        cout<<"NULL";
        return;
    }
    stack<node* >st;
    st.push(root);
    while(!st.empty())
    {
        node* curr=st.top();
        st.pop();
        cout<<curr->data<<" ";
        if(curr->right!=NULL)
        {
            st.push(curr->right);
        }
        if(curr->left!=NULL)
        {
            st.push(curr->left);
        }
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
    cout<<"Preorder Traversal is: ";
    preorder(root);
    return 0;
}