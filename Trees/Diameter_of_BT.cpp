//To calculate the diameter of a binary tree
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
//Approach 1->Brute force: Cal height for both the sides, add them up and return the maximum out of them from every node
//TC->O(N*N) SC->O(N)
void help(node* root,int &maxi)
{
    if(root==NULL)
    {
        return ;
    }
    int left=maxDepth(root->left);
    int right=maxDepth(root->right);
    maxi=max(maxi,left+right);
    help(root->left,maxi);
    help(root->right,maxi);
}
int diameter_of_bt1(node* root)
{
    int maxi=0;
    help(root,maxi);
    return maxi;
}
//Approach 2->Brute force: Cal height and diameter within one function
//TC->O(N) SC->O(N)
int help2(node* root,int &maxi)
{
    if(root==NULL)
    {
        return 0;
    }
    int left=help2(root->left,maxi);
    int right=help2(root->right,maxi);
    maxi=max(maxi,left+right);
    return 1+max(left,right);
}
int diameter_of_bt2(node* root)
{
    int maxi=0;
    int ans=help2(root,maxi);
    return maxi;
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
    int ans1=diameter_of_bt1(root);
    int ans2=diameter_of_bt2(root);
    cout<<"Diameter of binary tree using Brute force is: "<<ans1<<endl;
    cout<<"Diameter of binary tree using Optimised sol is: "<<ans2<<endl;
    return 0;
}