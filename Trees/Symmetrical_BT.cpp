//To check whether a binary tree if symmetrical or not ( mirror of itself)
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
bool isSymmetric(node* p,node* q) //TC-> O(N) SC->O(h) FOR LEFT-SUBTREE -> ROOT LEFT RIGHT AND FOR RIGHT-SUBTREE -> ROOT RIGHT LEFT
{
    if(p==NULL || q==NULL)
    {
        return (p==q);
    }
    bool lh=isSymmetric(p->left,q->right);
    bool rh=isSymmetric(p->right,q->left);
    return (p->data==q->data) && lh && rh;
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
    if(root == NULL)
    {
        cout << "It is a symmetrical binary tree";
        return 0;
    }
    bool ans=isSymmetric(root->left,root->right);
    if(ans)
    {
        cout<<"It is a symmetrical binary tree ";
    }
    else
    {
        cout<<"Not a symmetrical binary tree ";
    }
    return 0;
}
