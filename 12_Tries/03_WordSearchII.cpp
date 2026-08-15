// Statement

// Given a 2-D grid of characters board and a list of strings words, return all words that are present in the grid.

// For a word to be present it must be possible to form the word with a path in the board with horizontally or vertically neighboring cells. The same cell may not be used more than once in a word.

class Trie {
public:
    Trie* arr[26]={nullptr};
    string word="";
    bool eow=false;
    void addword(string w){
        Trie* curr=this;
        for(char c:w){
            int indx=c-'a';
            if(!curr->arr[indx]){
                curr->arr[indx]=new Trie();
            }
            curr=curr->arr[indx];
        }
        curr->eow=true;
        curr->word=w;
    }
};
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie* root=new Trie();
        for(string w:words){
            root->addword(w);
        }
        int row=board.size();
        int col=board[0].size();
        vector<string> result;
        for(int r=0;r<row;r++){
            for(int c=0;c<col;c++){
                dfs(r,c,board,root,result);
            }
        }
        return result;
    }
    void dfs(int r,int c,vector<vector<char>>& board,Trie* node,vector<string>& result){
        if(r<0||c<0||r>=board.size()||c>=board[0].size()) return;
        char ch=board[r][c];
        int idx=ch-'a';
        if(board[r][c]=='#'||!node->arr[idx]) return;
        Trie* next=node->arr[idx];
        if(next->eow){
            result.push_back(next->word);
            next->eow=false;
        }
        board[r][c]='#';
        dfs(r+1,c,board,node->arr[idx],result);
        dfs(r-1,c,board,node->arr[idx],result);
        dfs(r,c+1,board,node->arr[idx],result);
        dfs(r,c-1,board,node->arr[idx],result);
        board[r][c]=ch;
        // prune dead trie branches (can be done without it)
        bool hasChild = false;
        for (int i = 0; i < 26; i++) {
            if (next->arr[i]) { hasChild = true; break; }
        }
        if (!hasChild) {
            node->arr[ch - 'a'] = nullptr;
            delete next;
        }

    }
};
