//To calculate the vertical order traversal of a binary tree
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
//Approach 1-> Using level order traversal TC->O(N)Xlogn for multiset as return in sorted order if overlapping SC-> O(2N)
void vertical_order_traversal(node* root)
{
    vector<vector<int>>ans;
    if(root==NULL)
    {
        return ;
    }
    map<int,map<int,multiset<int>>>mpp;
    queue<pair<node*,pair<int,int>>>q;
    q.push({root,{0,0}});
    while(!q.empty())
    {
        auto it=q.front();
        q.pop();
        node* curr=it.first;
        int x=it.second.first;
        int y=it.second.second;
        mpp[x][y].insert(curr->data);
        if(curr->left!=NULL)
        {
            q.push({curr->left,{x-1,y+1}});
        }
        if(curr->right!=NULL)
        {
            q.push({curr->right,{x+1,y+1}});
        }
    }
    for(auto p:mpp)
    {
        vector<int>cols;
        for(auto q:p.second)
        {
            for(int x:q.second)
            {
                cout<<x<<" ";
            }
        }
        cout<<endl;
    }
}
//Approach 2-> Using Inorder traversal TC->O(N)xlog n SC->O(N)
void helper(node* root,int x,int y,map<int,map<int,multiset<int>>>& mpp)
{
    if(root == NULL) return;

    mpp[x][y].insert(root->data);
    
    helper(root->left,x-1,y+1,mpp);
    helper(root->right,x+1,y+1,mpp);
}
void vertical_order_traversal2(node* root)
{
    vector<vector<int>>ans;
    map<int,map<int,multiset<int>>> mpp;
    helper(root,0,0,mpp);
    for(auto p:mpp)
    {
        vector<int>cols;
        for(auto q:p.second)
        {
            for(int x:q.second)
            {
                cout<<x<<" ";
            }
        }
        cout<<endl;
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
    cout<<"Vertical order traversal using level order is: ";
    vertical_order_traversal(root);
    cout<<"Vertical order traversal using inorder order is: ";
    vertical_order_traversal2(root);
}