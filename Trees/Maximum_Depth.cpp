//To check to maximum depth or height of a binary tree 
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
int maxDepth1(node* root) //using recursion TC-> O(N) SC->O(h)
{
    if(root==NULL) return 0;
    int left=1+maxDepth1(root->left);
    int right=1+maxDepth1(root->right);
    return max(left,right);
}
int maxDepth2(node* root) //using Level-Order-Traversal TC->O(N) SC->O(N)
{
    if(root==NULL)
    {
        return 0;
    }
    queue<node*>q;
    q.push(root);
    int depth=0;
    while(!q.empty())
    {
        depth++;
        int size=q.size();
        for(int i=0;i<size;i++)
        {
            node* temp=q.front();
            q.pop();
            if(temp->left!=NULL)
            {
                q.push(temp->left);
            }
            if(temp->right!=NULL)
            {
                q.push(temp->right);
            }
        }
    }
    return depth;
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
    int ans=maxDepth1(root);
    int ans2=maxDepth2(root);
    cout<<"Maximum Depth of a Tree using Recursion is: "<<ans<<endl;
    cout<<"Maximum Depth of a Tree using Level-Order-Traversal is: "<<ans2<<endl;
    return 0;

}
