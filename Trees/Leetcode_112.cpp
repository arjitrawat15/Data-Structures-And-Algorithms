//Path sum 1
// Given the root of a binary tree and an integer targetSum, 
//return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.
bool hasPathSum(TreeNode* root, int targetSum) 
    {
        if(root==NULL)
        {
            return false;
        }
        return solve(root,targetSum);   
    }
    bool solve(TreeNode* root,int targetSum)
    {
        if(root==NULL)
        {
            return false;
        }
        if(root->left==NULL && root->right==NULL)
        {
            return targetSum-root->val == 0;
        }
        bool left=solve(root->left,targetSum-root->val);
        bool right=solve(root->right,targetSum-root->val);
        return left || right;
    }
