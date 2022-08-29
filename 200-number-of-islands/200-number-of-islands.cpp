class Solution {
private:
    void dfs(int r, int c, vector<vector<bool>>& vis, vector<vector<char>>& grid)
    {
        vis[r][c] = true;
        int n = grid.size();
        int m = grid[0].size();
        
        vector<int> delr = {0,-1,0,+1};
        vector<int> delc = {+1,0,-1,0};
        
        for(int i=0;i<4;i++)
        {
            int nrow = r + delr[i];
            int ncol = c + delc[i];
                
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m &&
              !vis[nrow][ncol] && grid[nrow][ncol] == '1')
           {
                dfs(nrow,ncol,vis,grid);
            }
        }
        
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m,0));
        int ans = 0;
        for(int i=0;i<n;i++)
        {
         for(int j=0;j<m;j++)
         {
             if(!vis[i][j] && grid[i][j] == '1')
             {
               ans++; 
               dfs(i,j,vis,grid);   
             }
         }
        }
        return ans;
    }
};