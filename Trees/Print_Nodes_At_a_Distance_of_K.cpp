//To print all the nodes from a node at a distance of K. 
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
void markParents(node* root,unordered_map<node*,node*>& mpp) //TC->O(N) SC->O(N)
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
void print_nodes_at_distance(node* root,node* target,int k) // Total = TC->O(N) for markParents + O(N) ~ O(2N) SC->O(3N)
{
    unordered_map<node*,node*>mpp;
    markParents(root,mpp);

    unordered_map<node*,bool> vis;
    queue<pair<node*,int>>q;
    q.push({target,0});
    vis[target]=true;
    while(!q.empty())
    {
        int size=q.size();
        if(q.front().second==k) break;
        for(int i=0;i<size;i++)
        {
            node* curr=q.front().first;
            int dist=q.front().second;
            q.pop();
            if(curr->left && !vis[curr->left])
            {
                q.push({curr->left,dist+1});
                vis[curr->left]=true;
            }
            if(curr->right && !vis[curr->right])
            {
                q.push({curr->right,dist+1});
                vis[curr->right]=true;
            }
            if(mpp.find(curr)!=mpp.end() && !vis[mpp[curr]])
            {
                q.push({mpp[curr],dist+1});
                vis[mpp[curr]]=true;
            }
        }
    }
    cout<<"Nodes at a distance of K from Node "<<target->data<<" are: ";
    while(!q.empty())
    {
        node* curr=q.front().first;
        q.pop();
        cout<<curr->data<<" ";
    }
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
    cout<<"Enter the target node: ";
    cin>>val2;
    node* target=findNode(root,val2);
    cout<<"Enter the distance: ";
    cin>>k;
    print_nodes_at_distance(root,target,k);
    return 0;
}