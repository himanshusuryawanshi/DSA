class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto& flight:flights){
            adj[flight[0]].push_back({flight[1],flight[2]});
        }
        vector<int> ans(n,INT_MAX);
        ans[src] = 0;
        for(int i=0;i<n;i++) cout<<ans[i]<<" ";
        queue<pair<int,int>> q; 
        q.push({src,0});
        while(!q.empty() and k>=0){
            int size = q.size();
            while(size--){
                int source = q.front().first;
                int current = q.front().second;
                q.pop();

                for(int i=0;i<adj[source].size();i++){
                    int dest = adj[source][i].first;
                    int price = adj[source][i].second;
                    if( ans[source] != INT_MAX and price + current < ans[dest]){
                        ans[dest] = price+current;
                        q.push({dest, ans[dest]});
                    }
                }
            }
            k--;
        }
        
        if(ans[dst]!=INT_MAX) return ans[dst];

        return -1;
    }
};
