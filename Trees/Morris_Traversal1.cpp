//to find the inorder of the binary tree using Morris traversal in O(1) Space complexity using the concept of threaded binary tree.
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
void morris_traversal(node* root) // TC->O(N) SC->O(1)
{
    vector<int>inorder;
    node* curr=root;
    while(curr!=NULL)
    {
        if(curr->left==NULL) //no left subtree
        {
            inorder.push_back(curr->data);
            curr=curr->right;
        }
        else 
        {
            node* prev=curr->left;
            while(prev->right!=NULL && prev->right!=curr) // go to the rightmost node of left subtree
            {
                prev=prev->right;
            }
            if(prev->right==NULL) //make thread 
            {
                prev->right=curr;
                curr=curr->left;
            }
            else //remove thread as already present
            {
                prev->right=NULL;
                inorder.push_back(curr->data);
                curr=curr->right;
            }
        }
    }
    cout<<"Inorder of binary tree using Morris traversal is: ";
    for(int i=0;i<inorder.size();i++)
    {
        cout<<inorder[i]<<" ";
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
    morris_traversal(root);
    return 0;
}