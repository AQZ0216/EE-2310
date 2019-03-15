#include <iostream>

using namespace std;

int gcd(int p1, int p2)
{
    int temp;
    if(p1 < p2)
    {
        temp = p1;
        p1 = p2;
        p2 = temp;
    }

    if(p1 % p2 == 0)
    {
        return p2;
    }
    p1 = p1 - p2;
    return gcd(p1, p2);


}

int gcd_n(int *p, int n)
{
    if(n == 1)
    {
        return *p;
    }

    return gcd(gcd_n(p, n-1), *(p+n-1));
}

int main()
{
    int n;
    cin >> n;

    int *p = new int[n];
    for(int i = 0; i < n; i++)
    {
        cin >> *(p+i);
    }

    cout << gcd_n(p, n) << endl;
    return 0;
}
