#include <bits/stdc++.h>
#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed << std::setprecision(1) << (x)
#define ll int int
#define pii pair<int, int>
#define pll pair<int int, int int>
#define vi vector<int>
#define vll vector<int int>
#define mii map<int, int>
#define si set<int>
#define sc set<char>
#define MAX 112345
using namespace std;

int c = 0;
vector<char> p;
int grid[7][7] = {0};
//inverted up and down cuz of matrix index
//          left, down, right, up
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

//diagonals
//            DL, UR, UL, DR
int dix[4] = {-1, 1, -1, 1};
int diy[4] = {1, -1, -1, 1};

//k is path size
//x and y coordinates
bool canGo(int gx, int gy){
    //check if it has been visited of if it is out of bounds
    if(gx < 0 || gy<0 || gx>=7 || gy>=7){
        return false;
    }
    if(grid[gy][gx] != 0)
        return false;
    return true;
}

bool isValid(int gx, int gy){
    if(gx < 0 || gy<0 || gx>=7 || gy>=7){
        return false;
    }
    return true;
}

void search(int k, int x, int y)
{
/*     for(int i = 0; i<7; i++){
        for(int j = 0; j<7; j++){
            if(i == y && x == j)
                cout<<"X";
            else
                cout<<grid[i][j];
        }
        cout<<endl;
    }
    cout<<endl; */
    //maybe has to be 49
    if(k==48){
        //check if reached bottom left
        if(y==6 && x==0){
            c++;
            return;
        }
    }else{
        //if reached the end and path size is not 48
        if(y==6 && x==0){
            return;
        }
        //check for the optimizations
        //check if it is frontfacing a wall or a blocked path and divides the grid into 2 paths(cant go up or down but can go sideways and vice versa)
        if(!canGo(x+dx[0], y+dy[0]) && !canGo(x+dx[2], y+dy[2]) && canGo(x+dx[1], y+dy[1]) && canGo(x+dx[3], y+dy[3])){
            return;
        }
        if(!canGo(x+dx[1], y+dy[1]) && !canGo(x+dx[3], y+dy[3]) && canGo(x+dx[0], y+dy[0]) && canGo(x+dx[2], y+dy[2])){
            return;
        }
        //check if the upper right cell is visited and if the right and up cell are unvisited
        //this means that we cant visit all squares because we either wont be able to visit up or right cells
        //do this for every diagonal and their respectives cells (ex: upper left, up and left)
        //upper right - up - right
        if(isValid(x+dix[1], y+diy[1]) && isValid(x+dx[3], y+dy[3]) && isValid(x+dx[2], y+dy[2])){
            if(!canGo(x+dix[1], y+diy[1]) && canGo(x+dx[3], y+dy[3]) && canGo(x+dx[2], y+dy[2])){
                return;
            }
        }

        //checking downLeft corner - down - left
        if(isValid(x+dix[0], y+diy[0]) && isValid(x+dx[1], y+dy[1]) && isValid(x+dx[0], y+dy[0])){
            if(!canGo(x+dix[0], y+diy[0]) && canGo(x+dx[1], y+dy[1]) && canGo(x+dx[0], y+dy[0])){
                return;
            }
        }


        //checking upper left corner - up - left
        if(isValid(x+dix[2], y+diy[2]) && isValid(x+dx[3], y+dy[3]) && isValid(x+dx[0], y+dy[0])){
            if((!canGo(x+dix[2], y+diy[2])) && canGo(x+dx[3], y+dy[3]) && canGo(x+dx[0], y+dy[0])){
                return;
            }
        }

        //checking lower right
        if(isValid(x+dix[3], y+diy[3]) && isValid(x+dx[1], y+dy[1]) && isValid(x+dx[2], y+dy[2])){
            if(!canGo(x+dix[3], y+diy[3]) && canGo(x+dx[1], y+dy[1]) && canGo(x+dx[2], y+dy[2])){
                return;
            }
        }



         //mark cell as visited
        grid[y][x] = 1;
        
        //if the direction is not defined in the path:
        if(p[k]=='?'){
            //loop in every direction
            for(int i = 0; i<4; i++){
                if(canGo(x+dx[i], y+dy[i])){
                    search(k+1, x+dx[i], y+dy[i]);
                }
            }
        }else{
            char dir = p[k];
            //cout<<dir<<" K:"<<k<<endl;
            if(dir == 'L'){
                if(canGo(x+dx[0], y+dy[0])){
                    search(k+1, x+dx[0], y+dy[0]);
                }
            }else if(dir == 'D'){
                if(canGo(x+dx[1], y+dy[1])){
                    search(k+1, x+dx[1], y+dy[1]);
                }
            }else if(dir == 'R'){
                if(canGo(x+dx[2], y+dy[2])){
                    search(k+1, x+dx[2], y+dy[2]);
                }
            }else if(dir == 'U'){
                if(canGo(x+dx[3], y+dy[3])){
                    search(k+1, x+dx[3], y+dy[3]);
                }
            }

        }
        //free cell
        grid[y][x] = 0;
        return;
    }
}

int main() {
    char aux;
    for(int i = 0; i<48; i++){
        cin>>aux;
        p.push_back(aux);
    }

    search(0, 0, 0);

    cout<<c<<endl;

    return 0;
}