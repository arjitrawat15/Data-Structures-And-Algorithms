# Invert Binary tree
## Given the root of a binary tree, invert the tree, and return its root.
// TC-> O(N) SC->O(N)
node * invert(node* root) 
{
  if(root==NULL)
  {
    return NULL;
  }
  root->left=invert(root->left);
  root->right=invert(root->right);
  swap(root->left,root->right);
  return root;
}
