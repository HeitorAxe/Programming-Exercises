#include <bits/stdc++.h>

using namespace std;

int main() {
    long long int n,m,t = 0, faltam, dias =0;
    double media;
    double sum = 0;

    queue<double> fila;

    cin >> n >> m;

    faltam = m-n;

    for (int i =0; i < 30; i++){
        double aux = 0;


        cin>>aux;

        fila.push(aux);

        sum+=aux;

    }
    while(true){

        media = ceil(sum / 30);
        
        n+=media;

        dias++;

        if(m <=n ){
            break;
        }

        sum = sum - fila.front() + media;
        fila.pop();

        fila.push(media);

    }
    cout  << dias << "\n" ;

    return 0;
}