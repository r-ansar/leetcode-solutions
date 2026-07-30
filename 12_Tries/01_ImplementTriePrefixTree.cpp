// Statement

// A prefix tree (also known as a trie) is a tree data structure used to efficiently store and retrieve keys in a set of strings. Some applications of this data structure include auto-complete and spell checker systems.

// Implement the PrefixTree class:

// PrefixTree() Initializes the prefix tree object.
// void insert(String word) Inserts the string word into the prefix tree.
// boolean search(String word) Returns true if the string word is in the prefix tree (i.e., was inserted before), and false otherwise.
// boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.

class PrefixTree {
public:
    PrefixTree* arr[26];
    bool eow;
    PrefixTree(){
        eow=false;
        for(int i=0;i<26;i++){
            arr[i]=NULL;
        }

    }
    
    void insert(string word) {
        PrefixTree* node=this;
        for(char c:word){
            int idx=c-'a';
            if(node->arr[idx]==NULL){
                node->arr[idx]=new PrefixTree();
            }
            node=node->arr[idx];
        }
        node->eow=true;
    }
    
    bool search(string word) {
        PrefixTree* node=this;
        for(char c:word){
            int idx=c-'a';
            if(node->arr[idx]==NULL){
                return false;
            }
            node=node->arr[idx];
        }
        return node->eow;
    }
    
    bool startsWith(string prefix) {
        PrefixTree* node=this;
        for(char c:prefix){
            int idx=c-'a';
            if(node->arr[idx]==NULL){
                return false;
            }
            node=node->arr[idx];
        }
        return true;
    }
};
