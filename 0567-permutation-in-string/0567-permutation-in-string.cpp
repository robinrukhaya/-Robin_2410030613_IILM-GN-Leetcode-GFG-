class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> need;
        for(char c: s1){
            need[c]++;
        }
        unordered_map<char,int> window;
        int left = 0;
        for(int right = 0; right < s2.size();right++){
            window[s2[right]]++;
            if(right - left +1 > s1.size()){
                window[s2[left]]--;

                if(window[s2[left]] == 0){
                    window.erase(s2[left]);
                }
                left++;
            } 
        
            if(window == need){
                return true;
            }
        }
        return false;
    }
};