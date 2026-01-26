// Subtree of another tree
// Given the roots of two binary trees root and subRoot, return true if there is a subtree of root with the same structure and node values of subRoot and false otherwise.
// Tc-> O(N) SC-> O(h)
bool isSubtree(node* root, node* subRoot) 
    {
        if(root==NULL)
        {
            return false;
        }
        if(root->val==subRoot->val && isSame(root,subRoot))
        {
            return true;
        }
        bool left=isSubtree(root->left,subRoot);
        bool right=isSubtree(root->right,subRoot);
        return left || right;
    }
    bool isSame(node* root,node* subRoot)
    {
        if(root==NULL || subRoot==NULL)
        {
            return (root==subRoot);
        }
        return root->val==subRoot->val && isSame(root->left,subRoot->left) && isSame(root->right,subRoot->right);
    }
