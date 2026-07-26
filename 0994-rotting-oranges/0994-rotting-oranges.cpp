class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int ans = 0, n = grid.size(), m = grid[0].size();
        queue<pair<int, int>> q;
        int fresh = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
                if (grid[i][j] == 1)
                    fresh++;
            }
        }
        while (!q.empty() and fresh) {
            int size = q.size();
            while (size--) {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                if ((row + 1 < n) and grid[row + 1][col] == 1) {
                    grid[row + 1][col] = 2;
                    q.push({row + 1, col});
                    fresh--;
                }
                if ((col + 1 < m) and grid[row][col + 1] == 1) {
                    grid[row][col + 1] = 2;
                    q.push({row, col + 1});
                    fresh--;
                }
                if ((row - 1 >= 0) and grid[row - 1][col] == 1) {
                    grid[row - 1][col] = 2;
                    q.push({row - 1, col});
                    fresh--;
                }
                if ((col - 1 >= 0) and grid[row][col - 1] == 1) {
                    grid[row][col - 1] = 2;
                    q.push({row, col - 1});
                    fresh--;
                }
            }
            ans++;
        }

        if (fresh)
            return -1;
        return ans;
    }
};