//Iterative Postorder without using any stack
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
void postorder3(node* root)
{
    if(root==NULL)
    {
        cout<<"NULL";
        return;
    }
    queue<node*>q;
    q.push(root);
    vector<int>post;
    while(!q.empty())
    {
        node* curr=q.front();
        q.pop();
        post.push_back(curr->data);
        if(curr->right!=NULL)
        {
            q.push(curr->right);
        }
        if(curr->left!=NULL)
        {
            q.push(curr->left);
        }
    }
    reverse(post.begin(),post.end());
    for(int i=0;i<post.size();i++)
    {
        cout<<post[i]<<" ";
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
    postorder3(root);
    return 0;
}