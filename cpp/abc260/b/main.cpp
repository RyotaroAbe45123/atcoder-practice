#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,x,y,z;
    cin >> n >> x >> y >> z;
    vector<int> a(n+5),b(n+5);
    for(int i=1;i<=n;i++){cin >> a[i];}
    for(int i=1;i<=n;i++){cin >> b[i];}
    vector<bool> passed(n+5,false);

    vector<int> c;
    for(int i=1;i<=n;i++){
        c.push_back(10000*(100-a[i])+i);
    }
    sort(c.begin(),c.end());
    for(int i=0;i<x;i++){
        passed[c[i]%10000]=true;
    }

    c.clear();
    for(int i=1;i<=n;i++){
        if(!passed[i]){
            c.push_back(10000*(100-b[i])+i);
        }
    }
    sort(c.begin(),c.end());
    for(int i=0;i<y;i++){
        passed[c[i]%10000]=true;
    }

    c.clear();
    for(int i=1;i<=n;i++){
        if(!passed[i]){
            c.push_back(10000*(200-(a[i]+b[i]))+i);
        }
    }
    sort(c.begin(),c.end());
    for(int i=0;i<z;i++){
        passed[c[i]%10000]=true;
    }

    for(int i=1;i<=n;i++){
        if(passed[i]){cout << i << "\n";}
    }
    return 0;
    }
