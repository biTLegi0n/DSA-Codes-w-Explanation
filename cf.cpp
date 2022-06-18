#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;

string fun(string str, int newhr, int newmin){
    string hour="", minute="";
    bool flag = false;
    for(int i = 0; i<str.size(); i++){
        if(str[i]==':'){ 
            flag = true;
            continue;
        }
        if(!flag) hour.push_back(str[i]);
        else minute.push_back(str[i]);
    }
    int hr = stoi(hour) + newhr;
    int min = stoi(minute) + newmin;
    
    if(min>=60){
        hr++;
        min %= 60;
    }

    hr %= 24;

    string ghanta = to_string(hr);
    string ghanti = to_string(min);
    if(ghanta.size()==1) ghanta.insert(ghanta.begin(),'0');
    if(ghanti.size()==1) ghanti.insert(ghanti.begin(),'0');
    return ghanta+':'+ghanti;
}

bool ispalin(string str){
    int n = str.size();
    for (int i = 0; i<n/ 2; i++) {
        if (str[i] != str[n-i-1]) {
            return false;
        }
    }
    return true;
}

int main()
{

    int t;
    cin>>t;
    while(t--){
        string str;
        int x;
        cin>>str>>x;
        int hr = stoi(str.substr(0,2));
        int min = stoi(str.substr(3,2));
        
        int newhr = x/60, newmin = x-(newhr*60);

        map <string,int> mp;
        int count = 0;
        while(true){
            if(ispalin(str)) count++;
            mp[str]++;
            string temp = fun(str,newhr,newmin);
            str = temp;
            if(mp.find(str)!=mp.end()) break;
        }
        cout<<count<<"\n";
    }
}