#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    long long ans=0;
    vector<vector<long long>> a(n,vector<long long>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            char c;
            cin>>c;
            a[i][j]=c-'0';
        }
    }
    int p[8]={1,1,1,0,0,-1,-1,-1};
    int q[8]={1,0,-1,1,-1,1,0,-1};
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<8;k++){
            long long now=0;
            long long x=i,y=j;
            for(int l=0;l<n;l++){
                now*=10;
                now+=a[x][y];
                x+=p[k];
                y+=q[k];
                x%=n;
                x+=n;
                y%=n;
                y+=n;
                x%=n;
                y%=n;
            }
            ans=max(ans,now);
            }
        }
    }
    cout<<ans<<endl;
}
