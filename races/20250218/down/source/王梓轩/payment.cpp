#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,m;
bool c(int x){
	while(x>10){
		if(x%10!=0)return false;
		x/=10;
	}
	return true;
}
int suan(int x,int y,int z){
	for(int i=x/z-1;i>=1;i--){
		int sb=0;
		for(int j=1;j<=y;j++){
			sb+=(x-sb)/i;
			if(sb>x-i*(z+1)){sb+=(y-j)*z;break;}
		}
		if(sb>=x){return i;}
	}
}
signed main(){
	cin>>n>>k>>m;
	if(c(k)&&c(m)&&k>99&&m>99){
		int x=k;
		while(k%10==0&&k>=100){
			k/=10;
			m*=10;
		}
		int w;
		for(int i=n/m-1;i>=1;i--){
			int sb=0;
			for(int j=1;j<=k;j++){
				sb+=(n-sb)/i;
				if(sb>n-i*(m+1)){sb+=(k-j)*m;break;}
			}
			if(sb>=n){w=i;break;}
		}
		while(k!=x){
			k*=10,m/=10,w*=10;
			for(int i=w+4;i>=w-5;i--){
				int sb=0;
				for(int j=1;j<=k;j++){
					sb+=(n-sb)/i;
					if(sb>n-i*(m+1)){sb+=(k-j)*m;break;}
				}
				if(sb>=n){w=i;break;}
			}
		}
		cout<<w<<endl;
	}
	else cout<<suan(n,k,m);
	return 0;
}
