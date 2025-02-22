#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,x,mod=998244353;
signed main(){
	cin>>T;
	while(T--){
		cin>>n;
		int ans=0;
		int x=(int)sqrt(n);
		for(int i=1;i<=x;i++){
			int j=i-1;
			ans+=3*j*j;
			ans+=3*j+1;
			ans%=mod;
		}
		int r=n;
		for(int i=1;i<=n/(x+1);i++){
			int l=n/(i+1);
			ans+=3*i*i*(r-l);
			r=l;
			ans%=mod;
		}
		cout<<ans<<endl;
	}
	return 0;
}
