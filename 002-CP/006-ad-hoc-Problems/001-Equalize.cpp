// Codeforces: Manthan CodeFest '18, C. Equalize
#include <iostream>
using namespace std;

#define m 1000000007
#define SWAP(a, b, c) ((c) = (a), (a) = (b), (b) = (c))

int main()
{
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    int cost = 0;
    for (int i = 0; i < n;)
    {
        if (a[i] != b[i])
        {
            if ((a[i] != a[i + 1]) && (b[i] != b[i + 1]))
            {
                int temp;
                SWAP(a[i], a[i + 1], temp);
                i += 2;
            }
            else
            {
                a[i] = b[i];
                i++;
            }
            cost++;
        }
        else
        {
            i++;
        }
    }
    cout << cost << endl;
    return 0;
}