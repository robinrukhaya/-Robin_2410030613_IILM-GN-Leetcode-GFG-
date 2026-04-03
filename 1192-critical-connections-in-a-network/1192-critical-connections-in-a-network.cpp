class Solution {
public:
    void dfs(int node,int parent,vector<vector<int>>& adj,vector<bool>& visited ,
        vector<int>& tin,vector<int>& low,int&  timer,vector<vector<int>> &bridges) {
            visited[node] = true;
            tin[node] = low[node] = timer++;

            for(auto neighbor : adj[node]) {
                if(neighbor == parent) continue;

                if(!visited[neighbor]) {
                    dfs(neighbor, node,adj,visited,tin,low,timer,bridges);
                    low[node] = min(low[node], low[neighbor]);

                    if(low[neighbor] > tin[node]) {
                        bridges.push_back({node,neighbor});
                    }
                }  else {
                    low[node] = min(low[node], tin[neighbor]);
                }
        
            }
        
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        vector<int> tin(n, -1), low(n, -1);
        vector<bool> visited(n, false);
        int timer = 0;
        vector<vector<int>> bridges;
    
        for(auto conn : connections) {
            adj[conn[0]].push_back(conn[1]);
            adj[conn[1]].push_back(conn[0]);
        }
    


        for (int i = 0; i < n;i++) {
            if(!visited[i]) {
            dfs(i,-1,adj,visited,tin,low,timer,bridges);
            }
        }
        return bridges;
    }
};