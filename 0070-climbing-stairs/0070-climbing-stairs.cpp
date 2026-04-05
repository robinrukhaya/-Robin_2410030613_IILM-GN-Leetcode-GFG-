class Solution {
public:
    int climbStairs(int n) {
        if ( n== 1) return 1;
        if (n== 2) return 2;

        int prev2 = 1;
        int prev = 2;

        for(int i =3 ;i <=n;i++) {
            int curr = prev2+prev;
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};