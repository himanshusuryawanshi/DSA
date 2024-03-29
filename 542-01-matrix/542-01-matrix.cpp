class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        vector<vector<int>> vis(n, vector<int>(m,0));
        vector<vector<int>> ans(n, vector<int>(m,0));
        
        queue<pair<pair<int,int>,int> > q;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j] == 0)
                {
                    q.push({{i,j}, 0});
                    vis[i][j] = 1;
                }
                else
                {
                    vis[i][j] = 0;
                }
            }
        }
        
        int delr[] = {0, -1, 0, +1};
        int delc[] = {-1, 0, +1, 0};
        
        while(!q.empty())
        {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int dis = q.front().second;
            q.pop();
            ans[row][col] = dis;
            
            for(int i=0;i<4;i++)
            {
                int nrow = row + delr[i];
                int ncol = col + delc[i];
                
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol])
                {
                    vis[nrow][ncol] = 1;
                    q.push({{nrow,ncol},dis+1});
                }
            }
        }
        return ans;
    }
};