
#include <iostream>
#include <vector>
using namespace std;


int min_val(int x, int y)
{
    return x > y ? y : x;
}
int main() {
    
    int count;
    while (cin >> count)
    {
        vector<int> x(count, 0);
        vector<int> y(count, 0);
        vector<int> status(count, 0);
        int i = 0;
        while (i < count){
            cin >> x[i] >> y[i];
            i++;
        }
        status[0] = min_val(x[0], y[0]);

        for (int i = 1; i < count; i++)
        {
            status[i] = min_val(abs(x[i] - x[0]), abs(y[i]-y[0]));
            for (int j = 1; j < i; j++)
            {
                status[i] = min_val(status[i], status[j] + min_val(abs(x[i] - x[j]), abs(y[i] - y[j])));
            }
        }
        cout << status[count - 1] << endl;
    }
    return 0;
}
