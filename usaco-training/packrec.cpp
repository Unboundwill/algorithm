/*
ID:selfcon2	
LANG:C++
PROG:packrec
*/
#include <fstream>
#include <cstdlib>
#include <cstring>
using namespace std;
ifstream fin("packrec.in");
ofstream fout("packrec.out");
struct node{int a,b;};
node rec[10],rec0[10],backup[10],ans[1000];
static bool hash[10];
int tot=0,mins=(1<<30);
int cmp(const void * x,const void * y)
{
	if((*(node *)x).a==(*(node *)y).a)return (*(node *)x).b-(*(node *)y).b;
	else return (*(node *)x).a-(*(node *)y).a;	
}
void calc()
{
	int i;
	int ta,tb,ts;
	//-------------------------------Situation1
	ta=0;tb=0;ts=0;
	for(i=1;i<=4;i++){ta+=rec[i].a;tb=max(tb,rec[i].b);}
	ts=ta*tb;
	if(ts<mins){tot=0;mins=ts;ans[tot].a=ta;ans[tot].b=tb;tot++;}
	else if(ts==mins){ans[tot].a=ta;ans[tot].b=tb;tot++;}
	//-------------------------------Situation2
	ta=0;tb=rec[1].b;ts=0;
	ta=max(rec[1].a,rec[2].a+rec[3].a+rec[4].a);
	tb+=max(rec[2].b,max(rec[3].b,rec[4].b));
	ts=ta*tb;
	if(ts<mins){tot=0;mins=ts;ans[tot].a=ta;ans[tot].b=tb;tot++;}
	else if(ts==mins){ans[tot].a=ta;ans[tot].b=tb;tot++;}
	//-------------------------------Situation3
	ta=0;tb=0;ts=0;
	ta=max(rec[1].a,rec[2].a+rec[3].a)+rec[4].a;
	tb=max(rec[2].b,rec[3].b)+rec[1].b;tb=max(tb,rec[4].b);
	ts=ta*tb;
	if(ts<mins){tot=0;mins=ts;ans[tot].a=ta;ans[tot].b=tb;tot++;}
	else if(ts==mins){ans[tot].a=ta;ans[tot].b=tb;tot++;}
	//-------------------------------Situation4.1
	ta=max(rec[1].a,rec[2].a)+rec[3].a+rec[4].a;tb=0;ts=0;
	tb=max(rec[3].b,rec[4].b);tb=max(tb,rec[1].b+rec[2].b);
	ts=ta*tb;
	if(ts<mins){tot=0;mins=ts;ans[tot].a=ta;ans[tot].b=tb;tot++;}
	else if(ts==mins){ans[tot].a=ta;ans[tot].b=tb;tot++;}
	//-------------------------------Situation4.3
	ta=max(rec[1].a,rec[4].a)+rec[3].a+rec[2].a;tb=0;ts=0;
	tb=max(rec[3].b,rec[2].b);tb=max(tb,rec[1].b+rec[4].b);
	ts=ta*tb;
	if(ts<mins){tot=0;mins=ts;ans[tot].a=ta;ans[tot].b=tb;tot++;}
	else if(ts==mins){ans[tot].a=ta;ans[tot].b=tb;tot++;}
	//-------------------------------Situation4.2
	ta=max(rec[1].a,rec[3].a)+rec[2].a+rec[4].a;tb=0;ts=0;
	tb=max(rec[2].b,rec[4].b);tb=max(tb,rec[1].b+rec[3].b);
	ts=ta*tb;
	if(ts<mins){tot=0;mins=ts;ans[tot].a=ta;ans[tot].b=tb;tot++;}
	else if(ts==mins){ans[tot].a=ta;ans[tot].b=tb;tot++;}
	//-------------------------------Situation5.1
	ta=0;tb=0;ts=0;
	ta=max(rec[1].a+rec[2].a,rec[3].a+rec[4].a);
	tb=max(rec[1].b,rec[2].b)+max(rec[3].b,rec[4].b);
	ts=ta*tb;
	if(ts<mins){tot=0;mins=ts;ans[tot].a=ta;ans[tot].b=tb;tot++;}
	else if(ts==mins){ans[tot].a=ta;ans[tot].b=tb;tot++;}	
	//-------------------------------Situation5.2
	ta=0;tb=0;ts=0;
	ta=max(rec[1].a,rec[3].a)+max(rec[2].a,rec[4].a);
	tb=max(rec[1].b+rec[3].b,rec[2].b+rec[4].b);
	ts=ta*tb;
	if(ts<mins){tot=0;mins=ts;ans[tot].a=ta;ans[tot].b=tb;tot++;}
	else if(ts==mins){ans[tot].a=ta;ans[tot].b=tb;tot++;}	
	//-------------------------------Situation5.3
	if(rec[3].b>=rec[4].b)
	{
	ta=0;tb=0;ts=0;
	ta=max(max(rec[1].a,rec[3].a)+rec[2].a,rec[3].a+rec[4].a);
	tb=max(rec[1].b+rec[3].b,rec[2].b+rec[4].b);
	ts=ta*tb;
	if(ts<mins){tot=0;mins=ts;ans[tot].a=ta;ans[tot].b=tb;tot++;}
	else if(ts==mins){ans[tot].a=ta;ans[tot].b=tb;tot++;}		
	}
	//--------------------------------
}
void dfs(int dep)
{
	int i,flag;
	if(dep==5)calc();
	else
	{
		flag=0;
		for(i=1;i<=4;i++)if(!hash[i]){flag=i;hash[flag]=true;rec[dep]=rec0[flag];dfs(dep+1);hash[flag]=false;}
	}
}
void work()
{
	int i,j,k,l,h,a[5];
	memset(rec0,0,sizeof(rec0));
	for(i=0;i<=1;i++)
	{
		a[1]=i;
		for(j=0;j<=1;j++)
		{
			a[2]=j;
			for(k=0;k<=1;k++)
			{
				a[3]=k;
				for(l=0;l<=1;l++)
				{
					a[4]=l;
					for(h=1;h<=4;h++){rec0[h]=backup[h];if(a[h])swap(rec0[h].a,rec0[h].b);}
					dfs(1);
				}
			}
		}
	}	
}
int main()
{
	int i;
	memset(hash,false,sizeof(hash));
	memset(rec,0,sizeof(rec));memset(backup,0,sizeof(backup));
	for(i=1;i<=4;i++){fin>>rec[i].a>>rec[i].b;backup[i]=rec[i];}
	work();
	for(i=0;i<tot;i++)if(ans[i].a>ans[i].b)swap(ans[i].a,ans[i].b);
	qsort(ans,tot,sizeof(ans[0]),cmp);
	fout<<mins<<endl;
	//for(i=0;i<tot;i++)fout<<ans[i].a<<" "<<ans[i].b<<endl;
	ans[tot].a=0;ans[tot].b=0;
	for(i=0;i<tot;i++)if((ans[i].a!=ans[i+1].a)||(ans[i].b!=ans[i+1].b))fout<<ans[i].a<<" "<<ans[i].b<<endl;
	return 0;
}



