//Statement

// Given the roots of two binary trees root and subRoot, return true if there is a subtree of root with the same structure and node values of subRoot and false otherwise.
// A subtree of a binary tree tree is a tree that consists of a node in tree and all of this node's descendants. The tree tree could also be considered as a subtree of itself.

class Solution {
public:
    bool isSametree(TreeNode* p,TreeNode* q){
        if(!p&&!q) return true;
        if(!p||!q) return false;
        return p->val==q->val &&
            isSametree(p->left,q->left) &&
            isSametree(p->right,q->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root) return false;
        if(isSametree(root,subRoot)) return true;
        return isSubtree(root->left,subRoot) ||
            isSubtree(root->right,subRoot);
    }
};