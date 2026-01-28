// Binary Tree Tilt
// Given the root of a binary tree, return the sum of every tree node's tilt.
// The tilt of a tree node is the absolute difference between the sum of all left subtree node values and all right subtree node values. 
// If a node does not have a left child, then the sum of the left subtree node values is treated as 0. The rule is similar if the node does not have a right child.
// TC->O(N) SC->O(h)
int findTilt(TreeNode* root) 
    {
        int sum=0;
        int ans=solve(root,sum);
        return sum;   
    }
    int solve(TreeNode* root,int& sum)
    {
        if(root==NULL)
        {
            return 0;
        }
        int left=solve(root->left,sum);
        int right=solve(root->right,sum);
        sum+=abs(left-right);
        return root->val+left+right;
    }
