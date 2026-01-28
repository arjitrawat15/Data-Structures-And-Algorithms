// Binary Tree Paths
// Given the root of a binary tree, return all root-to-leaf paths in any order.
// TC->O(N) SC->O(h)

vector<string> binaryTreePaths(node* root) 
    {
        string s="";
        vector<string>ans;
        paths(root,ans,s);
        return ans;
    }
    void paths(node* root,vector<string>& ans,string s)
    {
        if(root==NULL)
        {
            return;
        }
        if(root->left==NULL && root->right==NULL)
        {
            s+=to_string(root->val);
            ans.push_back(s);
            return;
        }
        paths(root->left,ans,s+to_string(root->val)+"->");
        paths(root->right,ans,s+to_string(root->val)+"->");
        return;
    }
