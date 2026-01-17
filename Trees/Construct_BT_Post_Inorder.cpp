//To construct a binary tree from postorder and inorder traversal of a binary tree
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
// Postorder -> 4 5 2 6 7 3 1
// Inorder-> 4 2 5 1 6 3 7
node* construct(vector<int>& postorder,int ps,int pe,vector<int>& inorder,int is,int ie,unordered_map<int,int>& mpp)
{
    if(ps>pe || is>ie)
    {
        return NULL;
    }
    node* root=new node(postorder[pe]);
    int index=mpp[postorder[pe]];
    int no=index-is;
    root->left=construct(postorder,ps,ps+no-1,inorder,is,index-1,mpp);
    root->right=construct(postorder,ps+no,pe-1,inorder,index+1,ie,mpp);
    return root;
}
node* construct_bt(vector<int>& inorder,vector<int>& postorder) // TC->O(N) SC->O(N)
{
    unordered_map<int,int> mpp;
    for(int i=0;i<inorder.size();i++)
    {
        mpp[inorder[i]]=i;
    }
    return construct(postorder,0,postorder.size()-1,inorder,0,inorder.size()-1,mpp);
}
void inorder_traversal(node* root)
{
    if(root==NULL) return;
    inorder_traversal(root->left);
    cout<<root->data<<" ";
    inorder_traversal(root->right);
}
int main()
{
    int n,val;
    cout<<"Enter the number of nodes: ";
    cin>>n;
    vector<int> inorder(n),postorder(n);
    cout<<"Enter the inorder traversal: ";
    for(int i=0;i<n;i++)
    {
        cin>>inorder[i];
    }
    cout<<"Enter the postorder traversal: ";
    for(int i=0;i<n;i++)
    {
        cin>>postorder[i];
    }
    node* root=construct_bt(inorder,postorder);
    cout<<"Inorder of the tree created is: ";
    inorder_traversal(root);
    return 0;
}