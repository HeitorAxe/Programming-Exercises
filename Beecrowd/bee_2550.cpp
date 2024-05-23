#include <bits/stdc++.h>
using namespace std;
#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed << std::setprecision(1) << (x)
/* TYPES  */
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>
#define mii map<int, int>
#define si set<int>
#define sc set<char>

#define V 1000

typedef pair<int, int> iPair;

int printMST(vector<iPair> adj[], int parent[], int n)
{
    int sum = 0;
    for (int i = 1; i < n; i++){
        if(parent[i] != -1) { // means it has a parent in the MST
            for (auto it : adj[i]) {
                if (it.first == parent[i]) {
                    sum += it.second;
                    break;
                }
            }
        }
    }
    return sum;
}

int primMST(vector<iPair> adj[], int n)
{
    priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
    
    int key[V];
    int parent[V];
    bool inMST[V];
    
    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, inMST[i] = false, parent[i] = -1;
    
    key[0] = 0;
    pq.push({0, 0});
    
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        
        inMST[u] = true;
        
        for (auto &[v, weight] : adj[u]) {
            if (!inMST[v] && weight < key[v]) {
                key[v] = weight;
                pq.push({key[v], v});
                parent[v] = u;
            }
        }
    }
    
    for(int i = 0; i<n; i++){
        if(!inMST[i])
            return -1;
    }
    return printMST(adj, parent, n);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    while (cin >> n >> m) {
        vector<iPair> adj[V];
        int a, b, c;
        for (int i = 0; i < m; i++) {
            cin >> a >> b >> c;
            adj[a-1].emplace_back(b-1, c);
            adj[b-1].emplace_back(a-1, c);
        }
        int ans = primMST(adj, n);
        if (ans == -1)
            cout << "impossivel" << endl;
        else
            cout << ans << endl;
    }
    return 0;
}
