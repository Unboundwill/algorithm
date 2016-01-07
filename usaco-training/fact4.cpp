/*
ID:selfcon2
LANG:C++
PROG:fact4
*/
#include <fstream>
using namespace std;
ifstream fin("fact4.in");
ofstream fout("fact4.out");
static int n,i,n2,n5,t,ans;
int main()
{
	fin>>n;
	ans=1;n2=0;n5=0;
	for(i=1;i<=n;i++)
	{
		t=i;
		while(t%2==0){n2++;t/=2;}
		while(t%5==0){n5++;t/=5;}
		ans*=t;ans%=10;
	}
	for(i=1;i<=n2-n5;i++){ans*=2;ans%=10;}
	for(i=1;i<=n5-n2;i++){ans*=5;ans%=10;}
	fout<<ans<<endl;
	return 0;
}
