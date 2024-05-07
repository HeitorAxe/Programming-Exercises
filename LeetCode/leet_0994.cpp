#include<bits/stdc++.h>
#define ll long long
using namespace std;

class Solution {
public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    bool isValid(vector<vector<bool>>& vis, int x, int y){
        if (x < 0 || y < 0 || x >= vis[0].size() || y >= vis.size())
            return false;
        return true;
    }
    void bfs(vector<vector<int>>& grid, vector<vector<int>>& minValues, int x, int y, vector<vector<bool>>& reached){
        queue<pair<pair<int, int>, int>> q;
        vector<vector<bool>> vis(grid.size(),vector<bool>(grid[0].size(), false));
        q.push({{x, y}, 0});
        vis[y][x] = true;
        while(!q.empty()){
            pair<pair<int, int>, int> cell = q.front();
            int cx = cell.first.first;
            int cy = cell.first.second;
            int dis = cell.second;
            reached[cy][cx] = true;
            q.pop();
            printf("Checking: %d %d\n", cx, cy);
            printf("Current DIS: %d\n", dis);
            printf("Current MinVALUE: %d\n", minValues[cy][cx] );
            minValues[cy][cx] = min(minValues[cy][cx], dis);
            printf("Current MinVALUE: %d\n", minValues[cy][cx] );
            for(int i = 0; i<4; i++){
                int adjx = cx + dx[i];
                int adjy = cy + dy[i];
                printf("TESTIN x: %d; y: %d\n", adjx, adjy);
                if(isValid(vis, adjx, adjy) && !vis[adjy][adjx] && grid[adjy][adjx]==1){
                    int newDis = dis+1;
                    printf("PUSHING %d %d WITH DIS = %d\n", adjx, adjy, newDis);
                    vis[adjy][adjx] = true;
                    q.push({{adjx, adjy}, newDis});
                }
            }
        }
    }
    int orangesRotting(vector<vector<int>>& grid) {
        vector<vector<int>> minValues(grid.size(),vector<int>(grid[0].size(), 10000));
        vector<vector<bool>> reached(grid.size(),vector<bool>(grid[0].size(), false));
        for(int i = 0; i<grid.size(); i++){
            for(int j = 0; j<grid[0].size(); j++){
                if(grid[i][j]==2){
                    printf("x: %d; y: %d\n", j, i);
                    bfs(grid, minValues, j, i, reached);
                }
            }
        }
        int m = 0;
        for(int i = 0; i<grid.size(); i++){
            for(int j = 0; j<grid[0].size(); j++){
                if(grid[i][j]!=0 && !reached[i][j])
                    return -1;
                if(minValues[i][j]!=10000){
                    m = max(m, minValues[i][j]);
                    printf("%d ",minValues[i][j]);
                }
            }
        }
        return m;
    }
};