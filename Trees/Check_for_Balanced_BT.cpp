//To check whether a binary tree is balanced or not
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
int maxDepth(node* root) 
{
    if(root==NULL) return 0;
    int left=1+maxDepth(root->left);
    int right=1+maxDepth(root->right);
    return max(left,right);
}
//Approach 1->Brute force:  Using Maxdepth func for calculating height of both sides
//TC->O(N^2) SC->O(N)
bool checkbalanced1(node* root)
{
    if(root==NULL)
    {
        return true;
    }
    int left=maxDepth(root->left);
    int right=maxDepth(root->right);

    if(abs(left-right)>1) return false;

    bool lh=checkbalanced1(root->left);
    bool rh=checkbalanced1(root->right);
    return lh && rh;
}
//Approach 2-> Optimised : Cal height and check for balanced tree in one func
//TC->O(N) SC->O(N)
int dfs(node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int left=dfs(root->left);
    if(left==-1)
    {
        return -1;
    }
    int right=dfs(root->right);
    if(right==-1)
    {
        return -1;
    }
    if(abs(left-right)>1) return -1;
    return 1+max(left,right);
}
bool checkbalanced2(node* root)
{
    return dfs(root) != -1;
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
    bool ans1=checkbalanced1(root);
    bool ans2=checkbalanced2(root);
    cout << boolalpha; //for printing true or false
    cout<<"Check for Balanced tree using brute force: "<<ans1<<endl;
    cout<<"Check for Balanced tree using optimised approach: "<<ans2<<endl;
    return 0;
}
