#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int N;
	cin>>N;
	
	vector<int> a[N];

	for(int i=0;i<N;i++){
		a[i] = vector<int>(i+1);
	}
	
	for(int i=0;i<N;i++){
		for(int j=0;j<i+1;j++){
			if(j==0||j==i)a[i][j] = 1;
			else{
				a[i][j] = a[i-1][j-1] + a[i-1][j];
			}
		}
	}
	
	for(int i=0;i<N;i++){
		for(int j=0;j<i+1;j++){
			if(j!=0)cout<<' ';
			cout<<a[i][j];
		}
		cout<<endl;
	}
	
    return 0;
}
