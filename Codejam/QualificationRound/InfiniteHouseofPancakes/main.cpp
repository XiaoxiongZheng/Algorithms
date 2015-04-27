#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ifstream ifs(
            "/Users/zhengxx/Projects/cplusplus/Algorithms/Codejam/QualificationRound/InfiniteHouseofPancakes/sample.txt");
    ofstream ofs(
            "/Users/zhengxx/Projects/cplusplus/Algorithms/Codejam/QualificationRound/InfiniteHouseofPancakes/output.txt");
    int n;
    ifs >> n;

    int c = 0;
    while (c++ < n) {
        int a[1001];
        a[0] = 1, a[2] = 2;
        for (int i = 3; i <= 1001; i++)
            if (i % 2) a[i] = min(i, a[i - 1] + 1);
            else a[i] = min(i, min(2 * a[i / 2] + 1, a[i - 1] + 1));

        int d, dp[1001];
        ifs >> d;
        int max_val;
        for (int i = 1; i <= d; i++)
        {
            int temp;
            ifs >> temp;
            if (i == 1)
                dp[1] = a[temp];
            else
            {
                if (dp[i - 1] < a[temp])
                    dp[i] = a[temp] + 1;
            }
        }

    }

    return 0;
}
