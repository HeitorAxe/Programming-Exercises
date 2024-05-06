#include<bits/stdc++.h>
#define ll long long
using namespace std;

class Solution {
public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<pair<pair<int, int>, int>> q;
        q.push({{entrance[1], entrance[0]}, 0});
        vector<vector<bool>> vis(maze.size(),
                                 vector<bool>(maze[0].size(), true));

        while (!q.empty()) {
            pair<pair<int, int>, int> cell = q.front();
            int x = cell.first.first;
            int y = cell.first.second;
            int count = cell.second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int adjx = x + dx[i];
                int adjy = y + dy[i];
                if (adjx < 0 || adjy < 0 || adjx >= maze[0].size() ||
                    adjy >= maze.size()){
                    if(x==entrance[1] && y==entrance[0])
                        continue;
                    else
                        return count;
                }
                if (maze[adjy][adjx] == '.' && vis[adjy][adjx]) {
                    q.push({{adjx, adjy}, count+1});
                    vis[adjy][adjx] = false;
                }
            }
        }

        return -1;
    }
};