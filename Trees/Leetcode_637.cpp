// Average of levels in Binary Tree
// Given the root of a binary tree, return the average value of the nodes on each level in the form of an array.
// TC->O(N) SC->O(N)
vector<double> averageOfLevels(node* root) 
    {
        vector<double>ans;
        queue<node*>q;
        q.push(root);
        while(!q.empty())
        {
            int size=q.size();
            double avg=0.0;
            for(int i=0;i<size;i++)
            {
                node* curr=q.front();
                q.pop();
                avg+=curr->val;
                if(curr->left)
                {
                    q.push(curr->left);
                }
                if(curr->right)
                {
                    q.push(curr->right);
                }
            }
            ans.push_back(avg/size);
        }
        return ans;
    }
