#include <bits/stdc++.h>
#include <cmath>
#include <iostream>
#include <math.h>
using namespace std;
#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed << std::setprecision(1) << (x)
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>
#define mii map<int, int>
#define si set<int>
#define sc set<char>
//O Paulo q fez esse


bool is_prime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;

    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }

    return true;
}




int main()
{
    ll qtd;
    ll t = 0;
    ll ct = 0;
    ll z, x, y;
    ll z_inv = 1;

    cin >> qtd;

    while (t < qtd) {
        
        ct = 0;
        cin >> z;
        z_inv = z/2;

        x = floor(z_inv);
        y = ceil(z_inv) + 1;

        //cout << "X: " << x << "Y: " << y << "\n";

        if (z == 3 || z == 1)
        {
            if (z == 1)
            {
                cout << 0 << " " << 1 << "\n";
                ct++;
            }
            goto a;
        }

        if ((is_prime(x) == false && is_prime(y) == false) && y > x)
        {
                ct++;
                cout << x << " " << y << "\n";
        } else {
            while (ct < 1){
                if ((is_prime(x) == false && is_prime(y) == false) && y > x)
                {
                    ct++;
                    cout << x << " " << y << "\n";
                    break;
                }
                x--;
                y++;
                

            }
        }
        
        a:

        if (ct < 1)
            {
                cout << -1 << "\n";
            }

        t++;
    }


}