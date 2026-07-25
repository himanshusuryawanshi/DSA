class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();int m=grid[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        int ans = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1' and !visited[i][j]){
                    ans++;
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    visited[i][j] = true;
                    while(!q.empty()){
                        int row = q.front().first;
                        int col = q.front().second;
                        q.pop();
                        //left
                        if((col-1>=0) && !visited[row][col-1] && grid[row][col-1]=='1'){
                            visited[row][col-1] = true;
                            q.push({row,col-1});
                        }
                        //right
                        if((col+1<m) && !visited[row][col+1] && grid[row][col+1]=='1'){
                            visited[row][col+1] = true;
                            q.push({row,col+1});
                        }
                        //up
                        if((row-1>=0) && !visited[row-1][col] && grid[row-1][col]=='1'){
                            visited[row-1][col] = true;
                            q.push({row-1,col});
                        }
                        //down
                        if((row+1<n) && !visited[row+1][col] && grid[row+1][col]=='1'){
                            visited[row+1][col] = true;
                            q.push({row+1,col});
                        }
                    }
                }
            }
        }
        return ans;
    }
};