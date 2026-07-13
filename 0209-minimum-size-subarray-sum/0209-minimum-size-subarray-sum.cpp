class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0; 
        int minLen = INT_MAX;
        int left = 0;

        for(int right =0; right < nums.size();right++){
            sum += nums[right];
            while(sum >= target){
                minLen = min(minLen, right-left+1);
                sum -= nums[left];
                left++;
            }
            
            
        }
        if(minLen == INT_MAX){
            return 0;
        }   
        return minLen;
    }
};