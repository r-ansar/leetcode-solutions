//Statement

// Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) in the tree.
// A binary search tree satisfies the following constraints:
// The left subtree of every node contains only nodes with keys less than the node's key.
// The right subtree of every node contains only nodes with keys greater than the node's key.
// Both the left and right subtrees are also binary search trees.

class Solution {
public:
    int n=0;
    int ans;
    void inorder(TreeNode* root, int k){
        if(!root) return;
        inorder(root->left,k);
        n++;
        if(n==k){
            ans=root->val;
            return;
        }
        inorder(root->right,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        inorder(root,k);
        return ans;
    }
};
