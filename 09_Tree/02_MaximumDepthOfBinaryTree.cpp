//Statement

// Given the root of a binary tree, return its depth.
// The depth of a binary tree is defined as the number of nodes along the longest path from the root node down to the farthest leaf node.

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        int left=maxDepth(root->left);
        int right=maxDepth(root->right);        
        return 1+max(left,right);
    }
};
