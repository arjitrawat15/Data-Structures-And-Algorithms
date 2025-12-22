//Iterative Postorder using 1 stack
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
void postorder2(node* root)
{
    if(root==NULL)
    {
        cout<<"NULL";
        return;
    }
    stack<node*>st;
    node* curr=root;
    while(curr!=NULL || !st.empty())
    {
        if(curr!=NULL)
        {
            st.push(curr);
            curr=curr->left;
        }
        else
        {
            node* temp=st.top()->right;
            if(temp==NULL)
            {
                temp=st.top();
                st.pop();
                cout<<temp->data<<" ";
                while(temp==st.top()->right && !st.empty())
                {
                    temp=st.top();
                    st.pop();
                    cout<<temp->data<<" ";
                }
            }
            else
            {
                curr=temp;
            }
        }
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
    cout<<"Postorder Traversal is: ";
    postorder2(root);
    return 0;
}