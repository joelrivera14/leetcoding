class Solution {
public:
    int m, n;
    vector<vector<char>>grid;
    vector<vector<int>> directions = {{0,1},{1,0},{-1,0},{0,-1}};
    vector<vector<bool>>seen;
    int numIslands(vector<vector<char>>& grid) {
        this->grid = grid;
        m = grid.size();
        n = grid[0].size();
        seen = vector(m,vector<bool>(n,false));
        int islands =0;
        for(int row = 0; row<m; ++row){
            for(int col = 0; col<n; ++col){
                if(grid[row][col] == '1' && !seen[row][col]){
                    ++islands;
                    seen[row][col] = true;
                    dfs(row,col);
                }
            }
        }
        return islands;
    }
    void dfs (int row, int col){
        for(vector<int>dir : directions){
            int nextRow = row + dir[0];
            int nextCol = col + dir[1];
            if(isValid(nextRow,nextCol) && !seen[nextRow][nextCol]){
                seen[nextRow][nextCol] = true;
                dfs(nextRow,nextCol);
            }
        }
    }
    bool isValid(int row, int col){
        return 0<=row && row<m && 0 <= col && col<n && grid[row][col] == '1';
    }
};