class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> lastLower(26, -1);
        vector<int> firstUpper(26, -1);

        // Store positions
        for (int i = 0; i < word.size(); i++) {
            char ch = word[i];

            if (islower(ch)) {
                lastLower[ch - 'a'] = i;
            } else {
                int idx = ch - 'A';

                // store only first uppercase occurrence
                if (firstUpper[idx] == -1) {
                    firstUpper[idx] = i;
                }
            }
        }

        int count = 0;

        // Check condition
        for (int i = 0; i < 26; i++) {
            if (lastLower[i] != -1 &&
                firstUpper[i] != -1 &&
                lastLower[i] < firstUpper[i]) {
                count++;
            }
        }

        return count;
    }
};