/*
ID:selfcon2
LANG:C++
PROG:heritage
*/
#include <fstream>
#include <string>
using namespace std;
ifstream fin("heritage.in");
ofstream fout("heritage.out");
string a,b;
void create(int x,int y,int l)
{
	if(l<=0)return;
	else if(l==1){fout<<b[y];return;}
	else
	{
		int t;
		for(int i=0;i<a.length();i++)if(a[i]==b[y])t=i;
		create(x,y+1,t-x);
		create(t+1,y+t-x+1,l-(t-x)-1);
		fout<<b[y];
	}
}
int main()
{
	fin>>a>>b;
	create(0,0,a.length());
	fout<<endl;
	return 0;	
}
