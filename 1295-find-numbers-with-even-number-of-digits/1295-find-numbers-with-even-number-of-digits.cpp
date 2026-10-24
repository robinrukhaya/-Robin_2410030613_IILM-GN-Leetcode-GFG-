class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count = 0;
        for(int i = 0; i < nums.size();i++){
            int digits = 0;
            int n = nums[i];

            while(n > 0){
                digits++;
                n = n/10;
            }
            if(digits%2 == 0){
                count++;
            }
        }
        return count;
    }
    
};