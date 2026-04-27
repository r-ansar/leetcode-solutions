class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return NULL;
        TreeNode* left=invertTree(root->left);
        TreeNode* right=invertTree(root->right);
        TreeNode* temp=left;
        root->left=right;
        root->right=temp;
        return root;
    }
};
