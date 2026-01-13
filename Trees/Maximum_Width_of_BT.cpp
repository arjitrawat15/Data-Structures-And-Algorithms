//To calculate the maximum width of a binary tree
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
int maximum_width(node* root) //TC->O(N) SC->O(N)
{
    long long ans=0;
    queue<pair<node*,long long>>q;
    q.push({root,0});
    while(!q.empty())
    {
        int size=q.size();
        long long mini=q.front().second;
        long long first,last;
        for(int i=0;i<size;i++)
        {
            node* curr=q.front().first;
            long long curr_id=q.front().second-mini;
            q.pop();
            if(i==0) 
            {
                first=curr_id;
            }
            if(i==size-1)
            {
                last=curr_id;
            }
            if(curr->left)
            {
                q.push({curr->left,2*curr_id+1});
            }
            if(curr->right)
            {
                q.push({curr->right,2*curr_id+2});
            }
        }
        ans=max(ans,last-first+1);
    }
    return ans;
}
int main()
{
    node* root=NULL;
    int n,val,target;
    cout<<"Enter the number of nodes: ";
    cin>>n;
    cout<<"Enter the nodes: ";
    for(int i=0;i<n;i++)
    {
        cin>>val;
        root=insert(root,val);
    }
    int ans=maximum_width(root);
    cout<<"Maximum width of binary tree is: "<<ans<<endl;
    return 0;
}