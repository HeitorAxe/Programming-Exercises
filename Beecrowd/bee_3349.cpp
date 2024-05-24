#include <bits/stdc++.h>
using namespace std;
//não tenho ideia o pq n passa, 20% WA
//Só passou com C++ 20 KKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKK
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

#define N 10000000

int dp[5][N];
int v[4][N];
int w[4][N];
int groupQ[4];

int h, c, s, p;
double tw;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    double aux;

    cin >> h >> c >> s >> p >> tw;
    int m = (int)(tw * 10);

    groupQ[0] = h;
    groupQ[1] = c;
    groupQ[2] = s;
    groupQ[3] = p;

    for(int i = 0; i < h; i++) {
        cin >> aux;
        v[0][i] = (int)(aux * 10);
    }
    for(int i = 0; i < h; i++) {
        cin >> aux;
        w[0][i] = (int)(aux * 10);
    }
    for(int i = 0; i < c; i++) {
        cin >> aux;
        v[1][i] = (int)(aux * 10);
    }
    for(int i = 0; i < c; i++) {
        cin >> aux;
        w[1][i] = (int)(aux * 10);
    }
    for(int i = 0; i < s; i++) {
        cin >> aux;
        v[2][i] = (int)(aux * 10);
    }
    for(int i = 0; i < s; i++) {
        cin >> aux;
        w[2][i] = (int)(aux * 10);
    }
    for(int i = 0; i < p; i++) {
        cin >> aux;
        v[3][i] = (int)(aux * 10);
    }
    for(int i = 0; i < p; i++) {
        cin >> aux;
        w[3][i] = (int)(aux * 10);
    }

    int n = 4;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            dp[i][j] = dp[i - 1][j];
            for(int k = 0; k < groupQ[i - 1]; k++) {
                if(j >= w[i - 1][k]) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i - 1][k]] + v[i - 1][k]);
                }
            }
        }
    }

    double result = dp[n][m] / 10.0;
    cout << fixed << setprecision(1) << result << endl;

    return 0;
}

