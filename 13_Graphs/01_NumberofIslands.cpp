// Statement

// Given a 2D grid grid where '1' represents land and '0' represents water, count and return the number of islands.
// An island is formed by connecting adjacent lands horizontally or vertically and is surrounded by water. You may assume water is surrounding the grid (i.e., all the edges are water).

class Solution {
public:
    void dfs(int r,int c,vector<vector<char>>& grid,vector<vector<bool>>& vis){
        if(r<0||c<0||r>=grid.size()||c>=grid[0].size()||grid[r][c]=='0'||vis[r][c]) return;
        vis[r][c]=true;
        dfs(r-1,c,grid,vis);
        dfs(r+1,c,grid,vis);
        dfs(r,c+1,grid,vis);
        dfs(r,c-1,grid,vis);
    }
    int numIslands(vector<vector<char>>& grid) {
        int islands=0;
        int row=grid.size();
        int col=grid[0].size();
        vector<vector<bool>> vis(row,vector<bool>(col,false));
        for(int r=0;r<row;r++){
            for(int c=0;c<col;c++){
                if(!vis[r][c]&&grid[r][c]=='1'){
                    dfs(r,c,grid,vis);
                    islands++;
                }
            }
        }
        return islands;
    }
};
