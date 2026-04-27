// Statement

// Given the roots of two binary trees p and q, return true if the trees are equivalent, otherwise return false.
// Two binary trees are considered equivalent if they share the exact same structure and the nodes have the same values.


class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p&&!q){
            return true;
        }
        if(!p||!q){
            return false;
        }
        bool left=isSameTree(p->left,q->left);
        bool right=isSameTree(p->right,q->right);
        return p->val==q->val && left && right;
    }
};

//Or

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> qp;
        queue<TreeNode*> qq;
        qp.push(p);
        qq.push(q);
        while (!qp.empty() && !qq.empty()) {
            TreeNode* nodep = qp.front(); qp.pop();
            TreeNode* nodeq = qq.front(); qq.pop();
            if (!nodep && !nodeq) continue;
            if (!nodep || !nodeq) return false;
            if (nodep->val != nodeq->val) return false;
            qp.push(nodep->left);
            qp.push(nodep->right);
            qq.push(nodeq->left);
            qq.push(nodeq->right);
        }

        return qp.empty() && qq.empty();
    }
};