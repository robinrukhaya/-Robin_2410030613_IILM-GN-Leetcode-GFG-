#include <vector>
#include <string>

class Solution {
public:
    std::vector<int> separateDigits(std::vector<int>& nums) {
        std::vector<int> answer;
        
        for (int num : nums) {
            // Convert the number to a string
            std::string s = std::to_string(num);
            
            // Loop through each character in the string
            for (char c : s) {
                // Convert char back to int (subtract '0' to get actual value)
                answer.push_back(c - '0');
            }
        }
        
        return answer;
    }
};