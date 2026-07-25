class Solution {
public:
//DFS
    void dfs(vector<vector<char>>& grid, int row, int col,vector<vector<bool>>& visited){
        visited[row][col] = true;
        int n=grid.size();int m=grid[0].size();
        if((col-1>=0) && !visited[row][col-1] && grid[row][col-1]=='1'){
           visited[row][col-1] = true;
           dfs(grid,row,col-1,visited);
        }
        if((col+1<m) && !visited[row][col+1] && grid[row][col+1]=='1'){
           visited[row][col+1] = true;
           dfs(grid,row,col+1,visited);
        }
        if((row-1>=0) && !visited[row-1][col] && grid[row-1][col]=='1'){
           visited[row-1][col] = true;
           dfs(grid,row-1,col,visited);
        }
        if((row+1<n) && !visited[row+1][col] && grid[row+1][col]=='1'){
           visited[row+1][col] = true;
           dfs(grid,row+1,col,visited);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();int m=grid[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        int ans = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1' and !visited[i][j]){
                    ans++;
                    dfs(grid,i,j,visited);
                }
            }
        }
        return ans;
    }
};