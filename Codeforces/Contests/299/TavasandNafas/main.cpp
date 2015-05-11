#include <iostream>
using namespace std;

const string s1[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
const string s2[10] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
const string s3[10] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

int score;

int main() {
    cin >> score;
    if (score < 10) cout << s1[score] << endl;
    else if (score < 20) cout << s2[score % 10] << endl;
    else if (score % 10 == 0) cout << s3[score / 10] << endl;
    else {
        int k = score / 10, b = score % 10;
        cout << s3[k] << "-" << s1[b] << endl;
    }
    return 0;
}