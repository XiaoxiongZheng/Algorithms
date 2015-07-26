//
// Created by zhengxx on 15/7/26.
//

#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<long> us;
        long ans = n;
        while (true) {
            ans = sumDigital(ans);
            if (ans == 1) return true;
            else if (us.find(ans) != us.end()) return false;
            else us.insert(ans);
        }
    }

private:
    long sumDigital(long n) {
        long ans = 0;
        while (n) {
            int tmp = n % 10;
            ans += tmp * tmp;
            n /= 10;
        }
        return ans;
    }
};