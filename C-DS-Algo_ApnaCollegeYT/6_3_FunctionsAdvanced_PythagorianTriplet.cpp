# include <bits/stdc++.h>

using namespace std;

bool check (int x, int y, int z)
{
    if (x>y && x>z) return (x*x == (y*y) + (z*z));
    else if (y>z) return (y*y == (x*x) + (z*z));
    else return (z*z == (x*x) + (y*y));
}

int32_t main()
{
    // Pythagoian Triplet
    int x,y,z;
    cin >> x >> y >> z;

    if (check(x,y,z)) cout << "They are Pythagorian Triplet.";
    else cout << "Not Pythagorian Triplet.";

    return 0;
}