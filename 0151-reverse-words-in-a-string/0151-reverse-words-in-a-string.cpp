class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        string temp = "";

        for (int i = 0;i < s.size();i++){
            if(s[i] != ' '){
                temp += s[i];
            }
            else {
                if(temp != ""){
                    words.push_back(temp);
                    temp = "";
                }
            }
        }
        if (temp != "") {
            words.push_back(temp);
        }
        reverse(words.begin(),words.end());
        string result = "";

        for (int i = 0; i < words.size();i++){
            if (i > 0) result += " ";
            result += words[i];
        }
        return result;
    }
};