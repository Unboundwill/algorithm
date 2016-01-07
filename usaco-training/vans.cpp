/*
ID:selfcon2
LANG:C++
PROG:vans
*/
#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;
const int MAX=100000000;
int n;
int dp[1001][9][60];
void add(int k,int v1,int v2)
{
	int jin=0;
	for (int i=1; i<=59; i++)
	{
		dp[k][v1][i]+=dp[k-1][v2][i]+jin;
		jin=0;
		if (dp[k][v1][i]>MAX)
		{
			jin=dp[k][v1][i]/MAX;
			dp[k][v1][i]%=MAX;
		}
	}
}
int main()
{
	freopen("vans.in","r",stdin);freopen("vans.out","w",stdout);
	cin>>n;n--;
	
	memset(dp,0,sizeof(dp));
	dp[1][3][1]=1; dp[1][7][1]=1;
	for (int i=2; i<=n; i++)
	{
		add(i,1,3); add(i,1,8);
		add(i,3,1); add(i,3,4); add(i,3,6); add(i,3,7);
		add(i,4,3);
		add(i,6,3); add(i,6,8);
		add(i,7,1); add(i,7,6);
		add(i,7,7);
		add(i,8,3); add(i,8,8);
	}
	add(n+1,2,3); add(n+1,2,8);
	add(n+1,2,3); add(n+1,2,8);
	
	int i=59;
	while (i>1&&dp[n+1][2][i]==0) i--;
	cout<<dp[n+1][2][i];
	for (int j=i-1; j>=1; j--) printf("%08ld",dp[n+1][2][j]);
	cout<<endl;
	return 0;
}
