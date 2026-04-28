//Statement

// Given a binary tree root, return the level order traversal of it as a nested list, 
// where each sublist contains the values of nodes at a particular level in the tree, from left to right.

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(!root){
            return result;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int s=q.size();
            vector<int> level;
            for(int i=0;i<s;i++){
                TreeNode* node=q.front();
                q.pop();
                level.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            result.push_back(level);
        }
        return result;
    }
};

//Or

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> result;
        vector<int> v;
        if(!root){
            return result;
        }
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            if(!node){
                result.push_back(v);
                v.clear();
                if(!q.empty()){
                    q.push(NULL);
                    continue;
                }
                else{
                    break;
                }
            }
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
            v.push_back(node->val);
        }
        return result;
    }
};
