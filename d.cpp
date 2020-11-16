#include<bits/stdc++.h>
//#include<atcoder/all>
using namespace std;
using ll = long long;

int main()
{
	ll n,w;
	cin >> n >> w;
	vector<ll> imos(300000);

	for(int i = 0;i<n;i++){
		ll s,t,p;
		cin >> s >> t >> p;

		imos[s] += p;
		imos[t] -= p;
	}
	for(int i = 0;i<imos.size()-1;i++){
		imos[i+1]+=imos[i];
	}
	for(int i =0;i<imos.size();i++){
		if(imos[i]>w){
			cout<<"No"<<endl;
			return 0;
		}
	}
	cout<<"Yes"<<endl;
}
