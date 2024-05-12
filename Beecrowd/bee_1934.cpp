#include <bits/stdc++.h>
#define DBG(x) cout << "[" << #x << "]: " << x << endl
using namespace std;

void solveVector(map<string, int>& solved, vector<string>& v, int& total, set<string>& notSolved){
    map<string, int> notSolvedOcurrences;
    for(int i = 0; i<v.size(); i++){
        if(solved.find(v[i])==solved.end()){
            notSolvedOcurrences[v[i]]+=1;
        }
    }

    if(notSolvedOcurrences.size()!=1)
        return;

    int value = total;
    int oc;
    string solving;
    for(int i = 0; i<v.size(); i++){
        if(notSolvedOcurrences.find(v[i])==notSolvedOcurrences.end()){
            value = value-solved[v[i]];
        }
        else{
            oc = notSolvedOcurrences[v[i]];
            solving = v[i];
        }
    }


    //DBG(value);
    //DBG(total);
    value = value/oc;
    notSolved.erase(solving);
    solved[solving]= value;
    return;

}


int main() {

    int l, c, auxi;
    string auxc;

    map<string, int> solved;
    vector<int> vl;
    vector<int> vc;

    set<string> notSolved;

    cin>>l>>c;

    vector<vector<string>> ml(l, vector<string>(c));
    vector<vector<string>> mc(c, vector<string>(l));

    for(int i = 0; i<l+1; i++){

        if(i<l){
            for(int j = 0; j<c+1; j++){
                if(j < c){
                    cin>>auxc;
                    ml[i][j] = auxc;
                    mc[j][i] = auxc;
                    //DBG(auxc);
                    notSolved.insert(auxc);
                }else{
                    cin>>auxi;
                    //DBG(auxi);
                    vl.push_back(auxi);
                }
            }
        }else{
            for(int j = 0; j<c; j++){
                cin>>auxi;
                vc.push_back(auxi);
            }
        }
    }


    while(!notSolved.empty()){
        for(int i = 0; i<ml.size(); i++){
            solveVector(solved, ml[i], vl[i], notSolved);
        }

        for(int i = 0; i<mc.size(); i++){
            solveVector(solved, mc[i], vc[i], notSolved);
        }
    }

    for(auto x:solved){
        cout<<x.first<<" "<<x.second<<endl;
    }


    return 0;
}