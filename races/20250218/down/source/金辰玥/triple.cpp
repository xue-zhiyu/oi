#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,n;
constexpr int mod=998244353;
signed main(){
	cin>>t;
	while(t--){
		cin>>n;
		int p=sqrt(n),ans=0;
		for(int i = 1;i<=p;i++){
			ans+=6ll*(i-1)*(n/i-i);
			ans+=3ll*(n/i-i);
			ans+=3ll*(i-1);
			ans++;
			ans%=mod;
		}
		cout<<(ans+mod)%mod<<"\n";
	}
	return 0;
}
