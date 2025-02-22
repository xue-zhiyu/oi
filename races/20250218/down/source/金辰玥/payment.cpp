#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int check(int n,int m,int k,int x){
	int cnt=0;
	while(n/x>m){
		int lzj=n/x;
		int cbc=lzj*x;
		int wzx=(n-cbc)/lzj;wzx++;
		n-=wzx*lzj;
		k-=wzx;
		cnt+=wzx*lzj;
	}
	return cnt+k*m;
}
signed main(){
	int n,m,k;cin>>n>>k>>m;
	int l=1,r=1e12+1;
	while(l<r){
		int mid=(l+r+1)/2;
		if(check(n,m,k,mid)>=n)l=mid;
		else r=mid-1;
	}
	cout<<l<<"\n";
	return 0;
}
