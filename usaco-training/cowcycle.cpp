/*
ID:selfcon2
LANG:C++
PROG:cowcycle
*/
#include <fstream>
#include <cstring>
#include <cstdlib>
using namespace std;
ifstream fin("cowcycle.in");
ofstream fout("cowcycle.out");
double a;int b[6],c[11];
static int F,R,f1,f2,r1,r2,f[6],r[11];
int cmp(const void * x,const void * y)
{
	if(*(double *)x>*(double *)y)return 1;
	else return -1;
}
void dfs(int x)
{
	if(x<=F)
	{
		for(int i=f[x-1]+1;i<=f2-F+x;i++)
		{
			f[x]=i;
			dfs(x+1);
		}
	}
	else if(x<=F+R)
	{
		for(int i=r[x-F-1]+1;i<=r2-(R-(x-F));i++)
		{
			r[x-F]=i;
			dfs(x+1);
		}		
	}
	else if(x==F+R+1)
	{
		if(f[F]*r[R]<3*f[1]*r[1])return;
		double average=0,tot=0,fangcha,result[100];
		int l=0;
		for(int i=1;i<=F;i++)
			for(int j=1;j<=R;j++)
			{
				result[l]=((double)f[i])/r[j];l++;
				int k=l-1;
				while(k>0&&result[k]<result[k-1])
				{
                    swap(result[k],result[k-1]);k--;
                }
			}
		//qsort(result,l,sizeof(result[0]),cmp);
		
		for(int i=1;i<l;i++)
		{
			double t=(result[i]-result[i-1]);
			average+=t/(l-1);
			tot+=t*t;
		}
		fangcha=tot-average*average*(l-1);
		if(fangcha<a)
			{
				a=fangcha;
				memcpy(b+1,f+1,sizeof(int)*F);
				memcpy(c+1,r+1,sizeof(int)*R);
				//for(int i=1;i<=F;i++)b[i]=f[i];
				//for(int i=1;i<=R;i++)c[i]=r[i];	
			}
		else if(fangcha==a)
		{
			int flag=0;
			for(int i=1;i<=F;i++)
			{
				if(b[i]<f[i])return;
				if(b[i]>f[i]){flag=1;break;}
			}
			if(flag==0)for(int i=1;i<=R;i++)
			{
				if(c[i]<r[i])return;
				if(c[i]>r[i]){flag=1;break;}
			}
			if(flag==1)
			{
				for(int i=1;i<=F;i++)b[i]=f[i];
				for(int i=1;i<=R;i++)c[i]=r[i];	
			}
		}
	}
}
int main()
{
	fin>>F>>R;
	fin>>f1>>f2>>r1>>r2;
	f[0]=f1-1;r[0]=r1-1;
	a=100000000;
	dfs(1);
	for(int i=1;i<=F;i++)
	{
		if(i-1)fout<<" ";fout<<b[i];
	}
	fout<<endl;
	for(int i=1;i<=R;i++)
	{
		if(i-1)fout<<" ";fout<<c[i];
	}
	fout<<endl;
	return 0;
}



