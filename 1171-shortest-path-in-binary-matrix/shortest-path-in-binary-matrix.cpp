class Solution {
public:
    vector<vector<int>> grid;
    vector<vector<int>> directions = {{0,1},{1,0},{0,-1},{-1,0},
                                    {1,1},{1,-1},{-1,1},{-1,-1}};
    int n;
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] == 1) return -1;
        this->grid = grid;
        n = grid.size();
        queue<vector<int>> path;
        vector<vector<bool>>seen(n,vector<bool>(n,false));
        seen[0][0] = true;
        path.push({0,0,1});
        while(!path.empty()){
            vector<int> current  = path.front();
            path.pop();
            int row = current[0], col = current[1], steps = current[2];
            if(row == n-1 && col == n-1) return steps;
            for(auto& dir : directions){
                int nextRow = row + dir[0], nextCol = col + dir[1];
                if(isValid(nextRow,nextCol) && !seen[nextRow][nextCol]){
                    seen[nextRow][nextCol] = true;
                    path.push({nextRow, nextCol, steps+1});
                }
            }
        }
        return -1;
    }

    bool isValid(int row, int col){
        return 0<=row && row<n && 0<= col && col<n && grid[row][col] == 0;
    }
};