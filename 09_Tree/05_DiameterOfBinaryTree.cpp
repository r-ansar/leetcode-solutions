//Statement

// The diameter of a binary tree is defined as the length of the longest path between any two nodes within the tree. The path does not necessarily have to pass through the root.
// The length of a path between two nodes in a binary tree is the number of edges between the nodes. Note that the path can not include the same node twice.
// Given the root of a binary tree root, return the diameter of the tree.

class Solution {
public:
    int ans=0;
    int dfs(TreeNode* root){
        if (!root) return 0;
        int left=dfs(root->left);
        int right=dfs(root->right);
        ans=max(ans,left+right);
        return 1+max(left,right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return ans;
    }
};

//Or

class Solution {
public:
    int height(TreeNode* root){
        if(!root)return 0;
        int left=height(root->left);
        int right=height(root->right);
        return 1+max(left,right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root)return 0;
        int left=height(root->left);
        int right=height(root->right);
        int curr=left+right;
        return max(curr,max(diameterOfBinaryTree(root->left),diameterOfBinaryTree(root->right)));
    }
};