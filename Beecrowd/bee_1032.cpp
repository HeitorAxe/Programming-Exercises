#include<bits/stdc++.h>
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

int prime[3502];

int isPrime(int n) { 
    int i;
    if(n == 2) return 1;
    if(n%2 == 0) return 0;
    for(i = 3; i*i<=n; i+=2) {
        if(n%i == 0) return 0;
    }
    return 1;
}

void primeNumbers(){
     memset(&prime, 0, sizeof(prime));
     int j;
     int a = 0;
     for(j = 2; j < 32650; j++){
           if(isPrime(j)){
                          prime[a] = j;
                          a++;
           }
     }
}


int main(){
    int t;
    primeNumbers();

    while(true){
        cin>>t;
        if(t==0)
            break;
        
        vector<int> people;

        for(ll i = 0; i<t;i++)
            people.push_back(i+1);
        ll kill = 0;
        ll step = 0; 
        while(people.size()>=1){
            kill=(kill+prime[step]-1)%people.size();
            people.erase(people.begin()+(kill));
            step++;

        }

        cout<<people[0]<<endl;   
    }

    return 0;
    
}