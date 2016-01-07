/*
ID:selfcon2
LANG:C++
PROG:nuggets
*/
#include <fstream>
#include <cstring>
using namespace std;
ifstream fin("nuggets.in");
ofstream fout("nuggets.out");
static int n,m,max1,max2,v[20],GCD;
static bool f[1000000];
int gcd(int x,int y)
{
	if(y==0)return x;
	else if(x>y)return gcd(y,x%y);
	return gcd(x,y%x);
}
int main()
{
	//init
	fin>>n;max1=0;max2=0;
	for(int i=0;i<n;i++)
	{
		fin>>v[i];
		if(v[i]==1){fout<<0<<endl;return 0;}
		if(v[i]>max1){max1=v[i];max2=max1;}
		else if(v[i]==max1)max2=max1;
		else if(v[i]<max1&&v[i]>max2)max2=v[i];
		if(i==0)GCD=v[i];
		else GCD=gcd(GCD,v[i]);
	}
	if(GCD!=1){fout<<0<<endl;return 0;}
	m=max1*max2;
	//work
	f[0]=true;
	for(int i=1;i<=m;i++)
		for(int j=0;j<n;j++)
		{
			if(i>=v[j])
				f[i]=f[i-v[j]]||f[i];
			if(f[i])break;
		}
	for(int i=m;i>=1;i--)
		if(!f[i]){fout<<i<<endl;break;}
	return 0;
}



