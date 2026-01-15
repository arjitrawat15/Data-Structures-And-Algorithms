//To count the total number of nodes in a complete binary tree.
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
//Brute force: Use dfs traversal TC->O(N) SC->O(N)
void count_nodes1(node* root,int& cnt)
{
    if(root==NULL)
    {
        return;
    }
    cnt++;
    count_nodes1(root->left,cnt);
    count_nodes1(root->right,cnt);
}
//optimised Approach: Cal height of left subtree and right subtree if equal then no of nodes= 2^l -1 else 1+left+right
//TC->O(log^2 n) SC->O(log n) for complete binary tree 
int findLeftHeight(node* root)
{
    int height=0;
    while(root!=NULL)
    {
        height++;
        root=root->left;
    }
    return height;
}
int findRightHeight(node* root)
{
    int height=0;
    while(root!=NULL)
    {
        height++;
        root=root->right;
    }
    return height;
}
int count_nodes(node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int left=findLeftHeight(root->left);
    int right=findRightHeight(root->right);
    if(left==right)
    {
        return (1<<(left+1))-1; // 2^h - 1
    }
    return 1+count_nodes(root->left)+count_nodes(root->right);
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
    int ans=count_nodes(root);
    cout<<"Number of nodes in the binary tree are: "<<ans<<endl;
    return 0;
}
