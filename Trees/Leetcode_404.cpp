// Sum of Left Leaves
// Given the root of a binary tree, return the sum of all left leaves.
// TC->O(N) SC->O(N)
int sumOfLeftLeaves(node* root) 
    {
        queue<node*>q;
        q.push(root);
        int sum=0;
        while(!q.empty())
        {
            node* curr=q.front();
            q.pop();
            if(curr->left!=NULL)
            {
                if(curr->left->left==NULL && curr->left->right==NULL)
                {
                    sum+=curr->left->val;
                }
                q.push(curr->left);
            }
            if(curr->right!=NULL)
            {
                q.push(curr->right);
            }
        }
        return sum;
    }
