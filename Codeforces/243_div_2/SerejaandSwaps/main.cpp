#include <iostream>
#include <queue>
#include <climits>
#include <string>

using namespace std;
int a[200];

int n, k;

struct cmp{
    bool operator () (int &a, int &b)
    {
        return a > b;
    }
};

int cal(int l, int r)
{
    priority_queue<int, vector<int>, cmp> pq;
    int sum = 0;
    for (int i = l; i <= r; i++)
    {
        sum += a[i];
        pq.push(a[i]);
    }
    int count = k;
    int vis[200] = {0};
    while (count--) {
        int max_val = INT_MIN, max_pos;
        for (int i = 0; i < n; i++) {
            if ((i >= l && i <= r) || vis[i]) continue;
            if (a[i] > max_val)
            {
                max_val = a[i];
                max_pos = i;
            }
        }
        if (max_val > pq.top())
        {
            vis[max_pos] = 1;
            sum = sum - pq.top() + max_val;
            pq.pop();
            pq.push(max_val);
        }
    }
    return sum;
}

int main() {
    while (cin >> n >> k)
    {
        int max_v = INT_MIN;
        int c = 0;
        while (c < n)
            cin >> a[c++];
        for (int i = 0; i < n; i++)
            for (int j = i; j < n; j++)
            {
                max_v = max(max_v, cal(i, j));
            }
        cout << max_v << endl;
    }
}