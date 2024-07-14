#include<bits/stdc++.h>

using namespace std;

#define DBG(x) cout << "[" << #x << "]: " << x << endl
#define F(x) std::fixed <<std::setprecision(1)<<(x)
#define f first 
#define s second 
#define pb push_back 
#define mp make_pair

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;

    while (t--)
    {
        vector<vector<char>> m;
        char aux;
        for(int i = 0; i<3; i++){
            vector<char> helper;
            for(int j = 0; j<3; j++){
                cin>>aux;
                helper.push_back(aux);
            }
            m.push_back(helper);
        }
        bool flag;
        char helper;
        for(int i = 0; i<3; i++){
            helper = m[i][0];
            flag = true;
            if(helper == '.') continue;
            for(int j = 0; j<3;j++){
                if(m[i][j]!=helper)
                    flag=false;
            }
            if(flag)
                break;
        }
        if(flag && helper!='.'){
            cout<<helper<<endl;
            continue;
        }
        for(int j = 0; j<3; j++){
            helper = m[0][j];
            flag = true;
            if(helper == '.') continue;
            for(int i = 0; i<3;i++){
                if(m[i][j]!=helper){
                    flag=false;
                }
            }
            if(flag)
                break;
        }
        if(flag && helper!='.'){
            cout<<helper<<endl;
            continue;
        }
        if(m[0][0] == m[1][1] && m[1][1] == m[2][2] && m[0][0] != '.'){
            cout<<m[0][0]<<endl;
            continue;
        }

        if(m[0][2] == m[1][1] && m[1][1] == m[2][0] && m[0][2] != '.'){
            cout<<m[0][2]<<endl;
            continue;
        }

        cout<<"DRAW"<<endl;


        
    }
}