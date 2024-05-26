#include <bits/stdc++.h>
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


int k;
int ma = 0;
const int INF = numeric_limits<int>::max();

void dijkstra(vector<vector<pii>>& graph, int source) {
    int n = graph.size();
    vector<int> distance(n, INF);
    distance[source] = 0;

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, source});

    while (!pq.empty()) {
        int u = pq.top().second;
        int dist_u = pq.top().first;
        pq.pop();

        if (dist_u > distance[u])
            continue;

        for (const auto& neighbor : graph[u]) {
            int v = neighbor.second;
            int weight_uv = neighbor.first;
            if (max(distance[u], weight_uv) < distance[v]) {
                distance[v] = max(distance[u], weight_uv);
                pq.push({distance[v], v});
            }

        }
    }
    sort(distance.begin(), distance.end());
    cout<<distance[k-1]<<endl;
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m >> k;
    int a1, a2, a3;
    vector<vector<pii>> graph(n);
    for (int i = 0; i < m; i++) {
        cin >> a1 >> a2 >>a3;
        graph[a1 - 1].push_back({a3,(a2 - 1)});
        graph[a2 - 1].push_back({a3,(a1 - 1)});
    }

    dijkstra(graph, 0);

    return 0;
}

