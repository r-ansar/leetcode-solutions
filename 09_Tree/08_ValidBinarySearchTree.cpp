//Statement

// Given the root of a binary tree, return true if it is a valid binary search tree, otherwise return false.
// A valid binary search tree satisfies the following constraints:
// The left subtree of every node contains only nodes with keys less than the node's key.
// The right subtree of every node contains only nodes with keys greater than the node's key.
// Both the left and right subtrees are also binary search trees.


class Solution {
public:
    bool globalCheck(TreeNode* root,int min,int max){
        if(!root) return true;
        if(root->val<=min || root->val>=max) return false;
        return globalCheck(root->left,min,root->val) &&
            globalCheck(root->right,root->val,max);
    }
    bool isValidBST(TreeNode* root) {
        return globalCheck(root,-1001,1001);
    }
};