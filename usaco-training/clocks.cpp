/*
ID:selfcon2
LANG:C++
PROG:clocks
*/
#include <fstream>
#include <string>
using namespace std;
ifstream fin("clocks.in");
ofstream fout("clocks.out");
const int method[9][9]={
                        1,1,0,1,1,0,0,0,0,
                        1,1,1,0,0,0,0,0,0,
                        0,1,1,0,1,1,0,0,0,
                        1,0,0,1,0,0,1,0,0,
                        0,1,0,1,1,1,0,1,0,
                        0,0,1,0,0,1,0,0,1,
                        0,0,0,1,1,0,1,1,0,
                        0,0,0,0,0,0,1,1,1,
                        0,0,0,0,1,1,0,1,1};
static int aim;
string ans="9999999999999999999999999999999999";
void dfs(int state,int dep,string way)
{
	int i,j,a[20];
	if(dep==9)
	{
		if((state==aim)&&(way<ans)){ans=way;return;}
	}
	else
	{
		for(i=0;i<9;i++){a[i]=(state>>2*(8-i))-((state>>2*(9-i))<<2);}
		for(i=0;i<4;i++)
		{
			string s=way;int next=0;
			for(j=1;j<=i;j++)s.push_back((char)(dep+1+'0'));
			for(j=0;j<9;j++){next=next<<2;next+=(a[j]+method[dep][j]*i)%4;}
			dfs(next,dep+1,s);
		}
	}	
}
int main()
{
	int tem,i,t;
	tem=0;aim=(1<<18)-1;
	for(i=0;i<9;i++){fin>>t;tem=tem<<2;tem+=t/3-1;}
	dfs(tem,0,"");
	for(i=0;i<ans.length();i++){if(i)fout<<" ";fout<<ans[i];}
	fout<<endl;
	return 0;
}
