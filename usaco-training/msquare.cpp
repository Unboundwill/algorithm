/*
ID:selfcon2
LANG:C++
PROG:msquare
*/
#include  <fstream>
#include <string>
#include <cstring>
#include <queue>
using namespace std;
ifstream fin("msquare.in");
ofstream fout("msquare.out");
struct node{int situation;string way;};
queue<node>q;
node tem;
static int hash[41000],fac[10];
int cantor(int m)
{
	int sum=0,i,j,vis[10],a[10],x=m;
	memset(vis,0,sizeof(vis));
	for(i=7;i>=0;i--){a[i]=x%10;x/=10;}
	for(i=0;i<7;i++)
	{
		for(j=1;j<a[i];j++){sum+=(1-vis[j])*fac[7-i];}
		vis[a[i]]=1;		
	}
	return sum;
}
int main()
{
	static int i,t,aim,aims,a[10],flag=0;
	string ans;
	t=1;
	for(i=1;i<=8;i++){t*=i;fac[i]=t;}
	aims=0;
	for(i=0;i<8;i++){fin>>t;aims*=10;aims+=t;}
	aim=cantor(aims);
	tem.situation=12345678;tem.way="";hash[0]=1;
	q.push(tem);
	while(!q.empty())
	{
		tem=q.front();
		for(i=7;i>=0;i--){a[i]=tem.situation%10;tem.situation/=10;}
		//for(i=0;i<8;i++)fout<<a[i];fout<<endl;
		//--------------------------------------------------------------------------
		tem=q.front();t=0;
		for(i=7;i>=0;i--){t*=10;t+=a[i];}
		tem.situation=t;t=cantor(tem.situation);
		if(!hash[t])
		{
			hash[t]=1;
			tem.way.push_back('A');
			q.push(tem);
			if(tem.situation==aims){ans=tem.way;flag=1;break;}
		}
		//----------------------------------------------------------------------------
		tem=q.front();t=0;
		t*=10;t+=a[3];t*=10;t+=a[0];t*=10;t+=a[1];t*=10;t+=a[2];
		t*=10;t+=a[5];t*=10;t+=a[6];t*=10;t+=a[7];t*=10;t+=a[4];		
		tem.situation=t;t=cantor(tem.situation);
		if(!hash[t])
		{
			hash[t]=1;
			tem.way.push_back('B');
			q.push(tem);
			if(tem.situation==aims){ans=tem.way;flag=1;break;}
		}
		//-----------------------------------------------------------------------------
		tem=q.front();t=0;
		t*=10;t+=a[0];t*=10;t+=a[6];t*=10;t+=a[1];t*=10;t+=a[3];
		t*=10;t+=a[4];t*=10;t+=a[2];t*=10;t+=a[5];t*=10;t+=a[7];
		tem.situation=t;t=cantor(tem.situation);
		if(!hash[t])
		{
			hash[t]=1;
			tem.way.push_back('C');
			q.push(tem);
			if(tem.situation==aims){ans=tem.way;flag=1;break;}
		}
		q.pop();
	}
	fout<<ans.length()<<endl;
	if(ans.length()==0)fout<<endl;
	for(i=0;i<ans.length();i++)
	{
		fout<<ans[i];
		if((i+1)%60==0||i+1==ans.length())fout<<endl;
	}
	return 0;
}
