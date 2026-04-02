class DSU {
public:
    vector<int> parent;
    vector<int> rank;
    
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    
    int find(int x) {
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    
    void unionByRank(int x, int y) {
        int px = find(x);
        int py = find(y);
        if(px == py) return;
        if(rank[px] < rank[py]) swap(px, py);
        parent[py] = px;
        if(rank[px] == rank[py]) rank[px]++;
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DSU dsu(n*n);
        int dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}}; 
        for(int i =0;i < n;i++) {
            for(int j = 0;j < n;j++) {
                if(grid[i][j] == 1) {
                    for(auto dir : dirs) {
                        int ni = i +dir[0];
                        int nj = j + dir[1];
                        if(ni >= 0 && ni<n && nj>= 0 && nj <n && grid[ni][nj]==1) {
                            dsu.unionByRank(i*n+j, ni*n+nj);
                        }
                    }
                }
            }
        }
        vector<int> isLandSize(n*n, 0);
        for(int i =0 ;i < n ;i++) {
            for(int j = 0; j <n;j++) {
                if(grid[i][j] == 1) {
                    int root = dsu.find(i*n+j);
                    isLandSize[root]++;
                }
            }
        }
        int maxSize = 0;

        // handle case where all cells are 1
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(grid[i][j] == 1)
                    maxSize = max(maxSize, isLandSize[dsu.find(i*n+j)]);

// try converting each 0
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 0) {
                    set<int> seen;
                    int size = 1;
                    for(auto dir : dirs) {
                        int ni = i + dir[0];
                        int nj = j + dir[1];
                        if(ni>=0 && ni<n && nj>=0 && nj<n && grid[ni][nj]==1) {
                            int root = dsu.find(ni*n+nj);
                            if(seen.find(root) == seen.end()) {
                                size += isLandSize[root];
                                seen.insert(root);
                            }
                        }
                    }
                    maxSize = max(maxSize, size);
                }
            }
        }
        return maxSize;
    }
};