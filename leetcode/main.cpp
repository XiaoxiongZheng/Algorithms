#include <iostream>
#include "WordLadder.cpp"

using namespace std;

int main() {
    Solution s;

    unordered_set<string> dict;
    string start = "hit", end = "cog";
    dict.insert("hot");
    dict.insert("dot");
    dict.insert("dog");
    dict.insert("lot");
    dict.insert("log");
    cout << s.ladderLength(start, end, dict) << endl;

    return 0;
}