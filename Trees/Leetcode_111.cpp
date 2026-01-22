# Minimum Depth of a Binary Tree
## Given a binary tree, find its minimum depth. The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
// TC->O(N) SC->O(N)
int min_depth(node* root)
{
  if(root==NULL) return 0;
  queue<node*>q;
  q.push(root);
  int depth=1;
  while(!q.empty())
  {
    int size=q.size();
    for(int i=0;i<size;i++)
      {
        node* curr=q.front();
        q.pop();
        if(curr->left==NULL && curr->right==NULL)
        {
            return depth;
        }
        if(curr->left) q.push(curr->left);
        if(curr->right) q.push(curr->right);
      }
    depth++;
  }
  return depth;
}
