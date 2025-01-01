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

// Direction vectors
int dRow[] = { -1, 0, 1, 0 };
int dCol[] = { 0, 1, 0, -1 };
 
// Function to check if a cell
// is be visited or not
bool isValid(vector<vector<bool>>& vis,
             int row, int col, int ROW, int COL)
{
    if (row < 0 || col < 0
        || row >= ROW || col >= COL)
        return false;
 
    if (vis[row][col])
        return false;
 

    return true;
}
 

int BFS(vector<vector<int>>& grid, vector<vector<bool>>& vis,
         int row, int col, vector<pair<int, int>>& notVisited)
{

    queue<pair<int, int> > q;

    q.push({ row, col });
    vis[row][col] = true;
    int sum = 0;
    while (!q.empty()) {
 
        pair<int, int> cell = q.front();
        int x = cell.first;
        int y = cell.second;
        sum+=grid[x][y];
 
        q.pop();

        for (int i = 0; i < 4; i++) {
            int adjx = x + dRow[i];
            int adjy = y + dCol[i];
            if (isValid(vis, adjx, adjy, grid.size(), grid[0].size()) && grid[adjx][adjy]!=0) {
                q.push({ adjx, adjy });
                vis[adjx][adjy] = true;
            }
        }
    }
    return sum;
}
 


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m,aux;
    char c;
    vector<vector<int>> g;
    vector<vector<bool>> vis;
    vector<pair<int, int>> notVisited;
    cin>>n>>m;
    for(int i = 0; i<n; i++){
        vector<int> a;
        vector<bool> visa;
        for(int j=0; j<m; j++){
            cin>>c;
            if(c=='.')
                aux=1;
            else
                aux=0;
            visa.push_back(false);
            a.push_back(aux);
            if(aux!=0)
                notVisited.push_back({i, j});
        }
        g.push_back(a);
        vis.push_back(visa);
    }
    int ma = 0;
    int count=0;
    for(int i=0 ; i<notVisited.size(); i++){
        if(!vis[notVisited[i].first][notVisited[i].second]){
            ma = max(BFS(g, vis, notVisited[i].first, notVisited[i].second, notVisited), ma);
            count++;

        }
    }
        
    cout<<count<<endl;
        


    return 0;
}


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

bool colorGraph(vector<vector<int>>& G,vector<int>& color,int pos, int c){
	
	if(color[pos] != -1 && color[pos] !=c)
		return false;
		
	color[pos] = c;
	bool ans = true;
	for(int i=0;i<G.size();i++){
		if(G[pos][i]){
			if(color[i] == -1)
				ans &= colorGraph(G,color,i,1-c);
				
			if(color[i] !=-1 && color[i] != 1-c)
				return false;
		}
		if (!ans)
			return false;
	}
	
	return true;
}

bool isBipartite(vector<vector<int>>& G){
	vector<int> color;
	for(int i=0;i<G.size();i++){
		color.push_back(-1);
    }
		
	int pos = 0;
	if(colorGraph(G,color,pos,1)){
        for(auto x:color){
            if(x==-1)
                x=1;
            cout<<x+1<<" ";
        }
        cout<<endl;
        return true;
    }
    cout<<"IMPOSSIBLE"<<endl;
    return false;
	
}

int main()
{
    vector<vector<int>> G;
    int n, m, a1, a2;
    cin>>n>>m;
    for(int i =0; i<n; i++){
        vector<int> aux;
        for(int j =0; j<n; j++){
            aux.push_back(0);
        }
        G.push_back(aux);
    }
    for(int i = 0; i<m; i++){
        cin>>a1>>a2;
        G[a1-1][a2-1] = 1;
    }

	isBipartite(G);
	return 0;
} 
