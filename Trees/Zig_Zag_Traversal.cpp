//To calculate the zig zag traversal of a binary tree
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
vector<vector<int>> zig_zag_traversal(node* root)
{
    vector<vector<int>>ans;
    if(root==NULL)
    {
        return ans;
    }
    queue<node*>q;
    q.push(root);
    bool leftoright=true;
    while(!q.empty())
    {
        int size=q.size();
        vector<int>res(size);
        for(int i=0;i<size;i++)
        {
            node* temp=q.front();
            q.pop();
            int index=(leftoright) ? i : size-1-i;
            res[index]=temp->data;
            if(temp->left!=NULL)
            {
                q.push(temp->left);
            }
            if(temp->right!=NULL)
            {
                q.push(temp->right);
            }
        }
        ans.push_back(res);
        leftoright=!leftoright;
    }
    return ans;
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
    vector<vector<int>>ans=zig_zag_traversal(root);
    cout<<"Zig Zag Traversal of binary tree is: ";
    for(auto it:ans)
    {
        for(auto x:it)
        {
            cout<<x<<" ";
        }
    }
    return 0;
}