#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        
        vector<vector<pair<int,int>>> adj(n);
        for (auto& road : roads) {
            int u = road[0], v = road[1], w = road[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        
        int mod = 1e9 + 7;

        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);

        dist[0] = 0;
        ways[0] = 1;

        priority_queue<pair<long long,int>,
                       vector<pair<long long,int>>,
                       greater<pair<long long,int>>> pq;

        pq.push({0, 0});

        while (!pq.empty()) {
            auto [d, node] = pq.top();
            pq.pop();

            if (d > dist[node]) continue;

            for (auto [neighbor, weight] : adj[node]) {
                long long newDist = d + weight;

                if (newDist < dist[neighbor]) {
                    dist[neighbor] = newDist;
                    ways[neighbor] = ways[node];
                    pq.push({newDist, neighbor});
                }
                else if (newDist == dist[neighbor]) {
                    ways[neighbor] = (ways[neighbor] + ways[node]) % mod;
                }
            }
        }

        return ways[n-1];
    }
};