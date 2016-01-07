/*
ID:selfcon2
LANG:C++
PROG:buylow
*/
#include <fstream>
#include <cstring>
using namespace std;
struct bign{int len;short a[200];};
ifstream fin("buylow.in");
ofstream fout("buylow.out");
static int n,v[5005],f[5005],ans;
bign num[5005],sum;
static int vis[5005];
bign add(bign x,bign y)
{
	bign tem;
	memset(tem.a,0,sizeof(tem.a));
	tem.len=max(x.len,y.len);
	for(int i=1;i<=tem.len;i++)
	{
		tem.a[i]=tem.a[i-1]/10+x.a[i]+y.a[i];
		tem.a[i-1]%=10;
	}
	while(tem.a[tem.len]/10!=0)
	{
		tem.len++;tem.a[tem.len]+=tem.a[tem.len-1]/10;
		tem.a[tem.len-1]%=10;
	}
	return tem;
}
int main()
{
	//init
	fin>>n;
	for(int i=1;i<=n;i++){fin>>v[i];f[i]=1;num[i].len=1;num[i].a[1]=1;}
	//work
	for(int i=1;i<=n;i++)
	{
		for(int j=i-1;j>=1;j--)
			if(v[j]>v[i])
			{
				if(f[j]+1>f[i])
				{
					f[i]=f[j]+1;
					vis[0]=1;
					vis[1]=v[j];
					num[i]=num[j];
				}
				else if(f[j]+1==f[i])
				{
					int flag=1;
					for(int k=1;k<=vis[0];k++)if(vis[k]==v[j]){flag=0;break;}
					if(flag){num[i]=add(num[i],num[j]);vis[0]++;vis[vis[0]]=v[j];}
				}
			}
		//fout<<f[i]<<" ";
		//for(int j=num[i].len;j>=1;j--)fout<<num[i].a[j];fout<<endl;
	}
	//for(int i=1;i<=n;i++)fout<<f[i]<<" "<<num[i]<<endl;
	ans=0;
	for(int i=n;i>=1;i--)
	{
		if(f[i]>ans)
		{
			ans=f[i];sum=num[i];
			vis[0]=1;vis[1]=v[i];
		}
		else if(f[i]==ans)
		{
			int flag=1;
			for(int k=1;k<=vis[0];k++)if(vis[k]==v[i]){flag=0;break;}
			if(flag)
			{
				sum=add(sum,num[i]);
				vis[0]++;vis[vis[0]]=v[i];
			}
		}
	}
	fout<<ans<<" ";
	for(int i=sum.len;i>=1;i--)fout<<sum.a[i];
	fout<<endl;
	return 0;
}



