
//ERRO, a reparticção binária não vai garantir repartição de todas as possibilidades

#include<bits/stdc++.h>
#define ll long long
using namespace std;
class Solution {
public:
    int punishmentNumber(int n) {
        int sum = 0;
        for(int i=1; i<=n; i++){
            int val = i*i;
            string s = to_string(val);
            vector<string> subs;
            subs.push_back(s);
            if(get_partitions(subs, i)){
                sum+=val;
                //cout<<"val="<<val<<endl;
                //cout<<"I="<<i<<endl;
            }
        }
        return sum;
    }

    bool get_partitions(vector<string>& s, int &goal){
        ////cout<<"goal="<<goal<<endl;
        int value = 0;
        bool allSingleDigit = true;
        for(auto x:s){
            //cout<<"----"<<endl;
            //cout<<x<<endl;
            //cout<<"----"<<endl;
            value+=stoi(x);
            if(x.length()>1)
                allSingleDigit = false;
        }
        if(value==goal)
            return true;
        if(value<goal)
            return false;
        if(allSingleDigit)
            return false;

        for(int i=0; i<s.size(); i++){
            string temp = s[i];
            if(temp.size()==1)
                continue;
            //cout<<"temp: "<<temp<<endl;
            for(int j=1; j<temp.size(); j++){
                string half = temp.substr(0, j);
                string otherHalf = temp.substr(j);
                //cout<<"half: "<<half<<endl;
                //cout<<"otherHalf: "<<otherHalf<<endl;
                if(otherHalf!=""){
                    s.insert(s.begin()+i, half);
                    s[i+1] = otherHalf;
                    if(get_partitions(s, goal))
                        return true;
                    s[i] = temp;
                    s.erase(s.begin()+i+1);
                }
                else{
                    continue;
                }

            }
        }


        return false;
    }
};
