//Statement

// You are given two integer arrays preorder and inorder.

// preorder is the preorder traversal of a binary tree
// inorder is the inorder traversal of the same tree
// Both arrays are of the same size and consist of unique values.
// Rebuild the binary tree from the preorder and inorder traversals and return its root.

class Solution {
public:
    int search(vector<int> inorder,int tofind){
        for(int i=0;i<inorder.size();i++){
            if(inorder[i]==tofind)
            return i;
        }
    }
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder,int& index,int left,int right){
        if(left>right) return NULL;
        TreeNode* root=new TreeNode(preorder[index]);
        int inorderindex=search(inorder,root->val);
        index++;
        root->left=helper(preorder,inorder,index,left,inorderindex-1);
        root->right=helper(preorder,inorder,index,inorderindex+1,right);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int index=0;
        return helper(preorder,inorder,index,0,inorder.size()-1);
    }
};
