//
// Created by zhengxx on 15/7/26.
//


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        vector<bool> prime(n, true);
        prime[0] = false, prime[1] = false;
        for (int i = 0; i * i < n; i++) {
            if (prime[i]) {
                for (int j = i * i; j < n; j+=i) {
                    prime[j] = false;
                }
            }
        }
        return count(prime.begin(), prime.end(), true);
    }
};