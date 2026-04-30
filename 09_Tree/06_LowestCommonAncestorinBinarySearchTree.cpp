//Statement

// Given a binary search tree (BST) where all node values are unique, and two nodes from the tree p and q, return the lowest common ancestor (LCA) of the two nodes.
// The lowest common ancestor between two nodes p and q is the lowest node in a tree T such that both p and q as descendants. The ancestor is allowed to be a descendant of itself.

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        if(root==p||root==q) return root;
        if(p->val<root->val && q->val<root->val) return lowestCommonAncestor(root->left,p,q);
        else if(p->val>root->val && q->val>root->val) return lowestCommonAncestor(root->right,p,q);
        return root;
    }
};

// Or

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        if(p==root||q==root) return root;
        TreeNode* left=lowestCommonAncestor(root->left, p, q);
        TreeNode* right=lowestCommonAncestor(root->right, p, q);
        if(left&&right) return root;
        return left? left:right;    
    }
};