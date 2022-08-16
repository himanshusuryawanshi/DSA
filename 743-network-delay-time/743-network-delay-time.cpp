class Solution {
public:
    vector<pair<int,int>>graph[101];
    int dist[101];
    int dijektras(int source,int n){
        int vis[n+1];
        for(int i=0;i<=n;i++){
            dist[i]=INT_MAX;
            vis[i]=0;
        }
        set<pair<int,int>>s;
        s.insert({0,source});
        dist[source]=0;
        while(!s.empty()){
            auto cur=*s.begin();
            s.erase(s.begin());
            int node=cur.second;
            int d=cur.first;
            if(dist[node]<d) continue;
            vis[node]=1;
            for(auto child:graph[node]){
                int cd=child.second;
                int c=child.first;
                if(dist[c]>dist[node]+cd){
                    dist[c]=dist[node]+cd;
                    s.insert({dist[c],c});
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(dist[i]==INT_MAX) return -1;
            ans=max(ans,dist[i]);
        }
        return ans;
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        for(int i=0;i<times.size();i++){
            int u=times[i][0];
            int v= times[i][1];
            int w=times[i][2];
            graph[u].push_back({v,w});
        }
        return dijektras(k,n);
    }
};