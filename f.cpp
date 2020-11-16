#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using ll = long long;

map<int,int> mp[200000];
int uf[200000];

void init(int n){
	for(int i = 0;i<n;i++)uf[i]=i;
}

int find(int x){
	if(x==uf[x])return x;
	return uf[x] = find(uf[x]);
}

//xにyをマージ
void marge(int x,int y){
	x = find(x);
	y = find(y);
	uf[y] = x;
}

int main()
{
	int n,q;
	cin >> n >> q;
	init(n);
	for(int i = 0;i<n;i++){
		int x;cin >> x;
		x--;
		mp[i][x]++;
	}
	for(int i  =0 ;i<q;i++){
		int is;cin >> is;
		if(is==1){
			int a,b;
			cin >> a >> b;
			a--;b--;
			a = find(a);
			b = find(b);
			if(a==b)continue;
			if(mp[a].size()<mp[b].size()){
				swap(a,b);
			}
			for(auto &j:mp[b]){
				mp[a][j.first] += j.second;
			}
			marge(a,b);
		}else{
			int a,b;
			cin >> a >> b;
			a--;b--;
			cout<<mp[find(a)][b]<<endl;
		}
	}
	
}
