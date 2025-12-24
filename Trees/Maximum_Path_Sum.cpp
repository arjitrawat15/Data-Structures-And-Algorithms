//To calculate the maximum path sum of a binary tree
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
//One and only Approach TC->O(N) SC->O(N)
int solve(node* root,int &maxi)
{
    if(root==NULL)
    {
        return 0;
    }

    int leftsum=max(0,solve(root->left,maxi));
    int rightsum=max(0,solve(root->right,maxi));

    maxi=max(maxi,root->data+leftsum+rightsum);

    return root->data+max(leftsum,rightsum);
}
int max_path_sum(node* root)
{
    int maxi=INT_MIN;
    int val=solve(root,maxi);
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
    int ans=max_path_sum(root);
    cout<<"Maximum path sum is: "<<ans<<endl;
    return 0;
}