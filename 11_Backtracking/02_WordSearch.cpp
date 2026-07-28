// Statement

// Given a 2-D grid of characters board and a string word, return true if the word is present in the grid, otherwise return false.
// For the word to be present it must be possible to form it with a path in the board with horizontally or vertically neighboring cells. The same cell may not be used more than once in a word.

class Solution {
public:
    bool helper(vector<vector<char>>& board, string& word,int r, int c,int index){
        if(index==word.size()){
            return true;
        };
        if(r<0||c<0||r==board.size()||c==board[0].size()||board[r][c]!=word[index]){
            return false;
        }
        index++;
        char temp=board[r][c];
        board[r][c]='#'; //for the condition that same cell can only be used once
        
        bool result=helper(board,word,r,c+1,index)||
            helper(board,word,r+1,c,index)||
            helper(board,word,r,c-1,index)||
            helper(board,word,r-1,c,index);
        
        board[r][c]=temp;
        return result;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int row=board.size();
        int column=board[0].size();
        for(int r=0;r<row;r++){
            for(int c=0;c<column;c++){
                if(helper(board,word,r,c,0)) return true;
            }
        }
        return false;
    }
};
