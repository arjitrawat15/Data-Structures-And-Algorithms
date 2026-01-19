//To serialise a binary tree into a string and to de-serialise that string back to a binary tree
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
string serialise(node* root) //  TC->O(N) SC->O(N)
{
    if(root==NULL)
    {
        return "";
    }
    string s="";
    queue<node*>q;
    q.push(root);
    while(!q.empty())
    {
        node* curr=q.front();
        q.pop();
        if(curr==NULL)
        {
            s.append("#,");
        }
        else
        {
            s.append(to_string(curr->data)+',');
        }
        if(curr!=NULL)
        {
            q.push(curr->left);
            q.push(curr->right);
        }
    }
    return s;
}
node* de_serialise(string data) // TC->O(N) SC->O(N)
{
    if(data=="") return NULL;
    stringstream s(data);
    string str;
    getline(s,str,',');
    node* root=new node(stoi(str));
    queue<node*>q;
    q.push(root);
    while(!q.empty())
    {
        node* curr=q.front();
        q.pop();

        getline(s,str,',');
        if(str=="#")
        {
            curr->left=NULL;
        }
        else
        {
            node* leftnode=new node(stoi(str));
            curr->left=leftnode;
            q.push(leftnode);
        }

        getline(s,str,',');
        if(str=="#")
        {
            curr->right=NULL;
        }
        else
        {
            node* rightnode=new node(stoi(str));
            curr->right=rightnode;
            q.push(rightnode);
        }
    }
    return root;
}
void inorder(node* root)
{
    if(root==NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
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
    string data=serialise(root);
    cout<<"Serialised string is: "<<data<<endl;
    node* head=de_serialise(data);
    inorder(head);
    return 0;
}