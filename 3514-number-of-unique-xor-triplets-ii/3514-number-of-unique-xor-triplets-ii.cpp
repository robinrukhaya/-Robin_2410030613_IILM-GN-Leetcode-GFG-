class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int maxVal = *max_element(nums.begin(), nums.end());
        int limit = 1;
        while (limit <= maxVal) limit <<= 1;
        limit <<= 1; 

        vector<bool> present(limit, false);
        for (int v : nums) present[v] = true;
        vector<int> vals;
        for (int v = 0; v < limit; v++) if (present[v]) vals.push_back(v);

        vector<bool> pairXor(limit, false);
        for (int a : vals)
            for (int b : vals)
                pairXor[a ^ b] = true;

        vector<bool> tripleXor(limit, false);
        for (int p = 0; p < limit; p++)
            if (pairXor[p])
                for (int c : vals)
                    tripleXor[p ^ c] = true;

        return count(tripleXor.begin(), tripleXor.end(), true);
    }
};