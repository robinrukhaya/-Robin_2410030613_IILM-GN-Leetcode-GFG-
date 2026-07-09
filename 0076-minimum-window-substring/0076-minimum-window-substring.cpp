class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int>need;
        for(char c: t){
            need[c]++;
        }

        unordered_map<char,int> window;
        int left = 0;
        int count = 0;
        int required = need.size();

        int minLen = INT_MAX;
        int start = 0;

        for (int right = 0;right < s.size();right++){
            window[s[right]]++;
            if(window[s[right]] == need[s[right]]){
                count++;
            }
            while(count == required){
                int len  = right - left +1;
            
                if(len < minLen){
                    minLen = len;
                    start = left;
                }
                window[s[left]]--;
                if(window[s[left]] < need[s[left]]){
                    count--;
                }
                left++;
            }
        }
        if(minLen == INT_MAX)
            return "";
        
        return s.substr(start,minLen);
    }
};