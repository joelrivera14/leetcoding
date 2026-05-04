class Solution {
public:
    int m, n;
    vector<vector<int>> grid;
    vector<vector<int>> directions = {{0,1},{1,0},{0,-1},{-1,0}};
    vector<vector<bool>>seen;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        this->grid = grid;
        m = grid.size();
        n = grid[0].size();
        seen = vector(m,vector<bool>(n,false));
        int maxArea = 0;
        for(int row = 0; row<m; row++){
            for(int col = 0; col<n; col++){
                if(grid[row][col] == 1 && !seen[row][col]){
                    int area = dfs(row, col);
                    maxArea = max(maxArea, area);
                }
            }
        }
        return maxArea;
    }

    int dfs(int row, int col){
        if(row<0|| col<0 || row>= m || col >= n) return 0;
        if(seen[row][col] || grid[row][col] == 0) return 0;
        seen[row][col] = true;
        
        int area = 1;
        for(vector<int> dir: directions){
            int nextRow = row + dir[0];
            int nextCol = col + dir[1];
            area += dfs(nextRow,nextCol);
        }
        return area;
    }
};