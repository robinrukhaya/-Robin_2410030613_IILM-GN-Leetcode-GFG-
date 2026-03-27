class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<long long, long long>>> adj(n);

        for (auto& road : roads) {
            int u = road[0];
            int v = road[1];
            int t = road[2];
            adj[u].push_back({v,t});
            adj[v].push_back({u,t});
        }
        vector<long long> dist(n, LLONG_MAX);
        vector<long long> ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;

        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,
            greater<pair<long long,long long>>> pq;
        pq.push({0,0});

        int mod = 1e9 + 7;

        while (!pq.empty()) {
            auto [d,node] = pq.top();
            pq.pop();

            for (auto [neighbor,time] : adj[node]) {
                long long newDist = d + time;
               if (newDist < dist[neighbor])  {
                dist[neighbor] = newDist;
                ways[neighbor] = ways[node];
                pq.push({newDist, neighbor});

               }
               else if (newDist == dist[neighbor]) {
                ways[neighbor] = (ways[neighbor]+ways[node]) % mod;
               }
            }

        }
        return ways[n-1];
    }
};
