class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,
          int,int>>> pq;
        
        for(int i =0;i < rows;i++){
            pq.push({matrix[i][0],i,0});
        }
        int ans  = 0;

        while(k--){
            auto[val,row,col] = pq.top();
            pq.pop();

            ans = val;

            if(col+1 <cols){
                pq.push({
                    matrix[row][col+1],row,col+1
                });
            }
        }
        return ans;
    }
};