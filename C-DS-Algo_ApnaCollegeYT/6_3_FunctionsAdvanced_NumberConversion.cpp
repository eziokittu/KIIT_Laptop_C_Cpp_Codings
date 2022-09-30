#include <bits/stdc++.h>
#include <math.h>

using namespace std;

int BinaryToDecimal(int n)
{
    int ans = 0;
    int pos = 0;
    int base = 2;
    int temp;
    while (n>0)
    {
        temp = n%10;
        ans += temp * pow(base, pos);
        n = n/10;
        pos +=1;
    }
    return ans;
}

int OctalToDecimal(int x)
{
    int ans = 0;
    int pos = 0;
    int base = 8;
    int temp;
    while (x>0)
    {
        temp = x%10;
        ans += temp * pow(base, pos);
        x = x/10;
        pos +=1;
    }
    return ans;
}

int HexadecimalToDecimal(string n)
{
    int ans = 0;
    int base = 16;
    int len = n.size();
    int pos = len-1;
    int temp;
    for (int i=0; i<len; i++)
    {
        if (n[i] >= '0' && n[i] <= '9')
            temp = n[i] - '0';
        else if (n[i] >= 'A' && n[i] <= 'F')
            temp = n[i] - 'A' + 10;
        ans += temp * pow(base, pos);
        pos--;
    }
    return ans; 
}

// not done by me
int DecimalToBinary(int n)
{
    int ans=0;
    int x=1;
    while (x<n)
    {
        x *= 2;
    }
    x /= 2;
    while (x>0)
    {
        int lastDigit = n/x;
        n -= lastDigit*x;
        x/=2;
        ans = ans*10 + lastDigit;
    }
    return ans;
}

// not done
int DecimalToOctal(int n)
{

}

// not done
int DecimalToHexadecimal(int n)
{

}

int32_t main()
{
    // Binary to Decimal 
    // int b;
    // cin >> b;
    // cout << BinaryToDecimal(b) << endl;

    // Octal to Decimal 
    // int b;
    // cin >> b;
    // cout << OctalToDecimal(b) << endl;

    // Hexadecimal to Decimal 
    // string b;
    // cin >> b;
    // cout << HexadecimalToDecimal(b) << endl;

    // Decimal to Binary
    int n;
    cin >> n;
    cout << DecimalToBinary(n) << endl;
}