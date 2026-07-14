// Statement

// Given the root of a non-empty binary tree, return the maximum path sum of any non-empty path.
// A path in a binary tree is a sequence of nodes where each pair of adjacent nodes has an edge connecting them. A node can not appear in the sequence more than once. The path does not necessarily need to include the root.
// The path sum of a path is the sum of the node's values in the path.

class Solution {
public:
    int maxSum=INT_MIN;
    int helper(TreeNode* node){
        if(!node) return 0;
        int left=helper(node->left);
        int right=helper(node->right);
        maxSum=max(maxSum,(node->val+left+right));
        return max(0,node->val+max(left,right));
    }
    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        helper(root);
        return maxSum;
    }
};