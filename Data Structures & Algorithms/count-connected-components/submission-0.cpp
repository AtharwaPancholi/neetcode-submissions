class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for(auto edge: edges){
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
            vector<int> vis(n,0);
            int components=0;
            for(int i=0; i<n; i++){
                if(!vis[i]){
                    components++;
                    dfs(i,adj,vis);
                }
            }
        return components;
    }
    void dfs(int node, vector<int> adj[], vector<int>& vis){
        vis[node]=1;
        for(auto it: adj[node]){
            if(!vis[it]){
                dfs(it,adj,vis);
            }
        }
    }
};
