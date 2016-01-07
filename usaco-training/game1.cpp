/*
ID:selfcon2
LANG:C++
PROG:game1
*/
#include <fstream>
#include <cstring>
using namespace std;
struct node{int x,y;};
ifstream fin("game1.in");
ofstream fout("game1.out");
static int a[205],n,vis[205][205];
static node f[205][205];
node dp(int l,int r,int who)
{
	if(vis[l][r])return f[l][r];
	else if(r==l)
	{
		if(who==1)f[l][r].x=a[l];
		else f[l][r].y=a[r];
		vis[l][r]=1;
		return f[l][r];
	}
	else 
	{
		if(who==1)
		{
			node t1=dp(l+1,r,2),t2=dp(l,r-1,2);
			if(a[l]+t1.x-t1.y>a[r]+t2.x-t2.y){f[l][r]=t1;f[l][r].x+=a[l];}
			else {f[l][r]=t2;f[l][r].x+=a[r];}
			vis[l][r]=1;return f[l][r];
		}
		else
		{
			node t1=dp(l+1,r,1),t2=dp(l,r-1,1);
			if(a[l]+t1.y-t1.x>a[r]+t2.y-t2.x){f[l][r]=t1;f[l][r].y+=a[l];}
			else {f[l][r]=t2;f[l][r].y+=a[r];}
			vis[l][r]=1;return f[l][r];
		}	
	}
}
int main()
{
	fin>>n;
	for(int i=0;i<n;i++)fin>>a[i];
	dp(0,n-1,1);
	fout<<f[0][n-1].x<<" "<<f[0][n-1].y<<endl;
	return 0;
}




