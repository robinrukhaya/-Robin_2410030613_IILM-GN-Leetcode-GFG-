class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n, 1e9);
        dist[src] = 0;
        for(int i = 0; i <= k; i++) {
        vector<int> temp = dist; 
        for(auto flight : flights) {
            int from = flight[0];
            int to = flight[1];
            int price = flight[2];
            if(dist[from] + price < temp[to]) {
                temp[to] = dist[from] + price;
            }
        }
        dist = temp; 
    }
    if(dist[dst] == 1e9) return -1;
    return dist[dst];
    }
};