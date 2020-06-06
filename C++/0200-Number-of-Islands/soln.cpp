class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        for(int i = 0; i < grid.size(); ++i)
            for(int j = 0; j < grid[0].size(); ++j)
                if(grid[i][j] == '1')
                {
                    dfs(grid, i, j);
                    ans += 1;
                }
        return ans;
    }
    
    void dfs(vector<vector<char>> & grid, int r, int c)
    {
        if(r >= 0 && r < grid.size() && c >= 0 && c < grid[0].size() && grid[r][c] == '1')
        {
            grid[r][c] = '0';
            dfs(grid, r - 1, c);
            dfs(grid, r + 1, c);
            dfs(grid, r, c - 1);
            dfs(grid, r, c + 1);
        }
    }
};