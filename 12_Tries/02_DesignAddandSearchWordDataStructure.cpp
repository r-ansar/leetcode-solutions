// Statement

// Design a data structure that supports adding new words and searching for existing words.

// Implement the WordDictionary class:

// void addWord(word) Adds word to the data structure.
// bool search(word) Returns true if there is any string in the data structure that matches word or false otherwise. word may contain dots '.' where dots can be matched with any letter.

class WordDictionary {
public:
    WordDictionary* arr[26]={nullptr};
    bool eow = false;
    WordDictionary() {}
    
    void addWord(string word) {
        WordDictionary* node=this;
        for(char c:word){
            int idx=c-'a';
            if(node->arr[idx]==nullptr){
                node->arr[idx]=new WordDictionary();
            }
            node=node->arr[idx];
        }
        node->eow=true;
    }
    
    bool search(string word) {
        return dfs(word,0,this);
    }
    bool dfs(string& word,int i,WordDictionary* node){
        if(!node) return false;
        if(i==word.size()) return node->eow;
        int idx=word[i]-'a';
        if(word[i]=='.'){
            for(int j=0;j<26;j++){
                if(dfs(word,i+1,node->arr[j])){
                    return true;
                }
            }
            return false;
        } else{
            return dfs(word,i+1,node->arr[idx]);
        }
    }
};
