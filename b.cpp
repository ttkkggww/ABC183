#include<bits/stdc++.h>
//#include<atcoder/all>
using namespace std;
using ll = long long;

int main()
{
	double x1,y1,x2,y2;
	cin >> x1 >> y1 >> x2 >> y2;
	y2 = -y2;
	double r = (y1-y2)/(x1-x2);

	double ans = (r*x1-y1)/r;
	printf("%.15lf\n",ans);
}
