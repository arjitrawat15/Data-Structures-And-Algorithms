//To check whether two trees are identical or not
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
bool identical(node* root1,node* root2)
{
    if(root1==NULL || root2==NULL)
    {
        return (root1==root2);
    }

    bool left=identical(root1->left,root2->left);
    bool right=identical(root1->right,root2->right);

    return (root1->data==root2->data) && left && right;
}
int main()
{
    node* root1=NULL;
    node* root2=NULL;
    int n,m,val1,val2;
    cout<<"Enter the number of nodes in Tree 1: ";
    cin>>n;
    cout<<"Enter the number of nodes in Tree 2: ";
    cin>>m;
    cout<<"Enter the nodes of Tree 1: ";
    for(int i=0;i<n;i++)
    {
        cin>>val1;
        root1=insert(root1,val1);
    }
    cout<<"Enter the nodes of Tree 2: ";
    for(int i=0;i<m;i++)
    {
        cin>>val2;
        root2=insert(root2,val2);
    }
    bool ans=identical(root1,root2);
    if(ans==true)
    {
        cout<<"Both the trees are identical"<<endl;
    }
    else
    {
        cout<<"They are not identical"<<endl;
    }
    return 0;
}