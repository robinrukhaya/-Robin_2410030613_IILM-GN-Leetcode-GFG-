class Solution {
public:

    bool check(string &longer, string &shorter)
    {
        if(longer.size()!= shorter.size()+1)
            return false;
        int i = 0;
        int j = 0;

        while ( i < longer.size()) {
            if (j < shorter.size() && longer[i] == shorter[j]){
                i++;
                j++;
            }
            else{
                i++;
            }
        }
        return (j == shorter.size());
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),[](string &a,string &b){
            return a.size()< b.size();
        });

        int n = words.size();

        vector<int> dp(n,1);

        int maxi = 1;

        for (int i = 0; i <n;i++){
            for (int prev = 0;prev <i;prev++){
                if(check(words[i],words[prev]) && dp[prev] + 1 > dp[i]){
                    dp[i] = dp[prev]+1;
                }
            }
            maxi = max(maxi,dp[i]);
        }
        return maxi;
        
    }
};