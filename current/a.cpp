#include <bits/stdc++.h>

using namespace std;

int main() {

    int l, c, auxi;
    char auxc;

    map<char, int> x;
    vector<vector<char>> ml;
    vector<vector<char>> mc;
    vector<int> vl;
    vector<int> vc;

    cin>>l>>c;

    for(int i = 0; i<l; i++){
        if(i=l-1){
            for(int j = 0; j<c; j++){
                if(j != c-1){
                    cin>>auxi;
                    ml[i][j] = auxi;
                }else{
                    cin>>auxc;
                    vl[i] = auxc;
                }
            }
        }else{
            for(int j = 0; j<c; j++){
                cin>>auxi;
                vc.push_back(auxi);
            }
        }
    }


    return 0;
}