//To calculate the minimum time taken to burn a binary tree from a node.
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
void markParents(node* root,unordered_map<node*,node*>& mpp) //TC->O(N) SC->O(N) //Use to traverse backwards by marking the parents
{
    queue<node*>q;
    q.push(root);
    while(!q.empty())
    {
        node* curr=q.front();
        q.pop();
        if(curr->left)
        {
            mpp[curr->left]=curr;
            q.push(curr->left);
        }
        if(curr->right)
        {
            mpp[curr->right]=curr;
            q.push(curr->right);
        }
    }
}
int min_time(node* root,node* target) //TC-> O(2N) SC->O(3N)
{
    unordered_map<node*,node*>mpp;
    markParents(root,mpp);

    unordered_map<node*,bool> vis;
    queue<node*>q;
    q.push(target);
    vis[target]=true;
    int time=0;
    while(!q.empty())
    {
        int size=q.size();
        bool burned=false;
        for(int i=0;i<size;i++)
        {
            node* curr=q.front();
            q.pop();
            if(curr->left && !vis[curr->left])
            {
                q.push(curr->left);
                vis[curr->left]=true;
                burned=true;
            }
            if(curr->right && !vis[curr->right])
            {
                q.push(curr->right);
                vis[curr->right]=true;
                burned=true;
            }
            if(mpp.find(curr)!=mpp.end() && !vis[mpp[curr]])
            {
                q.push(mpp[curr]);
                vis[mpp[curr]]=true;
                burned=true;
            }
            if(burned)
            {
                time++;
            }
        }
    }
    return time;
}
node* findNode(node* root,int val) //Included in the question
{
    if(root==NULL)
    {
        return NULL;
    }
    if(root->data==val) return root;
    node* left=findNode(root->left,val);
    node* right=findNode(root->right,val);
    if(left || right)
    {
        return left? left:right;
    }
    else
    {
        return NULL;
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
    int val2,k;
    cout<<"Enter the target node from where the binary tree is to be burnt: ";
    cin>>val2;
    node* target=findNode(root,val2);
    int ans=min_time(root,target);
    cout<<"Minimum time required to burn the binary tree is: "<<ans<<endl;
    return 0;
}