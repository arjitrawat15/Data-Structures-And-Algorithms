// All the traversals in one algorithm
#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node* right;
    node* left;

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
    queue<node*> q;
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
void pre_post_inorder(node* root)
{
    if(root==NULL)
    {
        cout<<"NULL";
        return;
    }
    stack<pair<node*,int>>st;
    st.push({root,1});
    vector<int>pre,post,in;
    while(!st.empty())
    {
        auto it=st.top();
        st.pop();
        if(it.second==1)
        {
            pre.push_back(it.first->data);
            it.second++;
            st.push(it);
            if(it.first->left!=NULL)
            {
                st.push({it.first->left,1});
            }
        }
        else if(it.second==2)
        {
            in.push_back(it.first->data);
            it.second++;
            st.push(it);
            if(it.first->right!=NULL)
            {
                st.push({it.first->right,1});
            }
        }
        else
        {
            post.push_back(it.first->data);
        }
    }
    cout<<"Preorder Traversal is: ";
    for(int i=0;i<pre.size();i++)
    {
        cout<<pre[i]<<" ";
    }
    cout<<endl;
    cout<<"Inorder Traversal is: ";
    for(int i=0;i<in.size();i++)
    {
        cout<<in[i]<<" ";
    }
    cout<<endl;
    cout<<"Postorder Traversal is: ";
    for(int i=0;i<post.size();i++)
    {
        cout<<post[i]<<" ";
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
    pre_post_inorder(root);
    return 0;
}