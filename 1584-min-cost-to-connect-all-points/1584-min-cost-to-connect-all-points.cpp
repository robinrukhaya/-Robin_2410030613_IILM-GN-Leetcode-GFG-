class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<bool> visited(n,false);
        int sum = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,0});
    
    while(!pq.empty()) {
        auto [weight,node] = pq.top();
        pq.pop();
        if(visited[node]) continue;
        visited[node] = true;
        sum += weight;
        for (int j= 0; j <n;j++) {
            if(!visited[j]){
                int dist = abs(points[node][0] - points[j][0]) + abs(points[node][1] - points[j][1]);
                pq.push({dist,j});
            }
        }
    }
    return sum;

    }
};