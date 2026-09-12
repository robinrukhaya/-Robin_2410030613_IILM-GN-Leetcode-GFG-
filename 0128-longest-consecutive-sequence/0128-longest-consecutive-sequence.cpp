class Solution {
public:
    int longestConsecutive(vector<int>& arr)
{
    unordered_set<int> st(arr.begin(), arr.end());

    int ans = 0;

    for (int num : st)
    {
        // Check if num is the starting point
        if (st.find(num - 1) == st.end())
        {
            int current = num;
            int length = 1;

            // Check consecutive numbers
            while (st.find(current + 1) != st.end())
            {
                current++;
                length++;
            }

            ans = max(ans, length);
        }
    }

    return ans;
    }
};