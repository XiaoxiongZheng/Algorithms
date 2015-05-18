//
// Created by zhengxx on 15/5/18.
//

/**
 * divide two integers
 * https://leetcode.com/problems/divide-two-integers/
 * time = O(logn), space = O(1)
 */

typedef long long ll;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0) return INT_MAX;

        ll ldd = abs((ll)dividend), ldi = abs((ll)divisor);
        if (ldd < ldi) return 0;
        ll d = ldi, ans = 0;
        while (ldd >= ldi) {
            ll d = ldi, cnt = 0;
            while (ldd >= d) {
                d <<= 1;
                if (cnt == 0) cnt = 1;
                else cnt <<= 1;
            }
            ans += cnt;
            d >>= 1;
            ldd -= d;
        }
        ans = (dividend < 0 ^ divisor < 0) ? -ans : ans;
        if (ans > INT_MAX) return INT_MAX;
        else return ans;
    }
};