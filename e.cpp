#include<bits/stdc++.h>
//#include<atcoder/all>
using namespace std;
using ll = long long;
const ll MOD = 1e9+7;

ll dp[2001][2001];


int main()
{
	int h,w;
	cin >> h >> w;
	map<ll,ll> sumx,sumy,sumxy;
	vector<string> S(h);
	for(auto &i:S)cin >> i;
	for(int i = 0;i<h;i++){
		for(int j = 0;j<w;j++){
			if(i==0&&j==0){
				dp[i][j]=1;
				sumx[i] += 1;
				sumy[j] += 1;
				sumxy[i-j]+=1;
				continue;
			}
			if(S[i][j]=='.'){
			(dp[i][j]+=sumx[i])%=MOD;
			(dp[i][j]+=sumy[j])%=MOD;
			(dp[i][j]+=sumxy[i-j])%=MOD;
			(sumx[i]+=dp[i][j])%=MOD;
			(sumy[j]+=dp[i][j])%=MOD;
			(sumxy[i-j]+=dp[i][j])%=MOD;
			}else{
				dp[i][j] = 0;
				sumx[i]=0;
				sumy[j]=0;
				sumxy[i-j]=0;
			}
			
		}
	}
	
	cout<<dp[h-1][w-1]<<endl;
}
