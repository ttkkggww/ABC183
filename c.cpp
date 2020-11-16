#include<bits/stdc++.h>
//#include<atcoder/all>
using namespace std;
using ll = long long;

ll T[8][8];

int main()
{
	ll n,k;
	cin >> n >> k;
	
	for(ll i = 0;i<n;i++){
		for(ll j = 0;j<n;j++)cin >> T[i][j];
	}
	ll cnt = 0;
	vector<ll> perm(n-1);
	for(ll i = 0;i<n-1;i++)perm[i]=i+1;
	do{
		ll now = 0;
		now += T[0][perm[0]];
		for(ll i = 0;i<perm.size()-1;i++){
			now += T[perm[i]][perm[i+1]];
		}
		now += T[perm.back()][0];
		if(now==k)cnt++;
		
	}while(next_permutation(perm.begin(),perm.end()));
	cout<<cnt<<endl;
}
