// Statement

// Implement an algorithm to serialize and deserialize a binary tree.
// Serialization is the process of converting an in-memory structure into a sequence of bits so that it can be stored or sent across a network to be reconstructed later in another computer environment.
// You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure. There is no additional restriction on how your serialization/deserialization algorithm should work.
// Note: The input/output format in the examples is the same as how NeetCode serializes a binary tree. You do not necessarily need to follow this format.

class Codec {
public:
    void serializeHelper(TreeNode* node, string& out) {
        if (!node) {
            out += "N,";
            return;
        }
        out += to_string(node->val) + ",";
        serializeHelper(node->left, out);
        serializeHelper(node->right, out);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string result;
        serializeHelper(root, result);
        return result;
    }

    TreeNode* deserializeHelper(const string& data, int& pos) {
        // read one token up to the next comma
        int start = pos;
        while (data[pos] != ',') pos++;
        string token = data.substr(start, pos - start);
        pos++; // skip the comma

        if (token == "N") return NULL;

        TreeNode* root = new TreeNode(stoi(token));
        root->left = deserializeHelper(data, pos);
        root->right = deserializeHelper(data, pos);
        return root;
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int pos = 0;
        return deserializeHelper(data, pos);
    }
};


// Or

class Codec {
public:
    string s="";
    void serializeHelper(TreeNode* node){
        if(!node){
            s=s+"N ";
            return;
        }
        s=s+to_string(node->val)+" "; 
        serializeHelper(node->left);
        serializeHelper(node->right);
        return;
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        serializeHelper(root);
        return s;
    }
    TreeNode* deserializeHelper(queue<int>& q){
        if(q.empty()||q.front()==-1001){
            if(!q.empty()) q.pop();
            return NULL;
        }
        TreeNode* root=new TreeNode(q.front());
        q.pop();
        root->left=deserializeHelper(q);
        root->right=deserializeHelper(q);
        return root;
    }


    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue <int> q;
        string s="";
        for(int i=0;i<data.size();i++){
            if(data[i]!=' '){
                if(data[i]=='N'){
                    s=s+"-1001";
                }
                else{
                    s=s+data[i];
                }
            }
            else{
                q.push(stoi(s));
                s="";
            }
        }
        TreeNode* root=deserializeHelper(q);
        return root;
    }
};
