//
// Created by zhengxx on 15/7/25.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        string bits = "";
        int cnt = 0;
        while (n) {
            if (n & 0x1) bits += "1";
            else bits += "0";
            n >>= 1;
        }
        while(bits.size() < 32) {
          bits += "0";
        }
        //cout << bits << endl;
        uint32_t result = 0;
        for (int i = 0; i < 32; i++) {
            result <<= 1;
            if (bits[i] == '1') {
                result += 1;
            }
        }
        return result;
    }
};