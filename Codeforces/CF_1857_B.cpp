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
        string numc;
        vector<int> num;
        cin>>numc;
        for (char c : numc) {
            num.push_back(c - '0');
        }
        bool flag = false;
        int last=-1;
        reverse(num.begin(), num.end());
        for(int i = 0; i<=num.size(); i++){
            if(flag){
                if(i>=num.size()){
                    num.push_back(1);
                    flag = false;
                    last = i-1;
                    continue;
                }
                if(num[i]==9){
                    num[i] = 0;
                    flag = true;
                    continue;
                }else{
                    num[i]++;
                    last = i-1;
                    flag = false;
                }
            }
            if(i==num.size()){
                if(num[i-1]>=5){
                    num.push_back(1);
                    num[i-1] = 0;
                    last = i-1;
                }
                continue;
            }
            if(i-1>=0 && num[i-1]>=5){
                if(num[i]==9){
                    num[i]=0;
                    flag = true;
                }
                else{
                    num[i]++;
                }
                num[i-1] = 0;
                last = i-1;
            }
        }
        reverse(num.begin(), num.end());
        for(int i = 0; i<num.size(); i++){
            
            if(last!=-1 && i>(num.size()-(last+1))){
                cout<<'0';
            }
            else{
                cout<<num[i];
            }
        }
        cout<<endl;
        
        
    }
}