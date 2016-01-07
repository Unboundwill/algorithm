/*
ID:selfcon2
LANG:C++
PROG:lgame
*/
#include <fstream>
#include <cstring>
#include <cstdlib>
using namespace std;
ifstream fin("lgame.in");
ifstream findict("lgame.dict");
ofstream fout("lgame.out");
const int point[26]={2,5,4,4,1,6,5,5,1,7,6,3,5,2,3,5,7,2,1,2,4,6,6,7,5,7};
static int tot,maxs,ansn,num[26],rule[26];
struct node{char a[10],b[10];}ans[40000];
static char str[10],dict[40000][10],score[40000];
int cmp(const void * x,const void * y)
{
	if(strcmp((*(node *)x).a,(*(node *)y).a)==0)return strcmp((*(node *)x).b,(*(node *)y).b);
	else return strcmp((*(node *)x).a,(*(node *)y).a);
}
int main()
{
	//
	fin.getline(str,10,'\n');
	for(int i=0;i<strlen(str);i++)rule[str[i]-'a']++;
	tot=0;maxs=0;
	while(findict.getline(str,10,'\n'))
	{
		if(str[0]=='.')break;
		int t=0;
		memset(num,0,sizeof(num));
		for(int i=0;i<strlen(str);i++)num[str[i]-'a']++;
		int flag=1;
		for(int i=0;i<26;i++)
		{
			if(num[i]>rule[i]){flag=0;break;}t+=point[i]*num[i];
		}
		if(flag==0)continue;
		memcpy(dict[tot],str,sizeof(char)*strlen(str));
		score[tot]=t;
		if(maxs<t){maxs=t;ansn=0;memcpy(ans[ansn].a,dict[tot],sizeof(char)*10);ansn++;}
		else if(maxs==t){maxs=t;memcpy(ans[ansn].a,dict[tot],sizeof(char)*10);ansn++;}
		tot++;
	}
	//
	for(int i=1;i<tot;i++)
		for(int j=0;j<i;j++)
		{
			if(score[i]+score[j]<maxs)continue;
			memset(num,0,sizeof(num));
			for(int k=0;k<strlen(dict[i]);k++)num[dict[i][k]-'a']++;
			for(int k=0;k<strlen(dict[j]);k++)num[dict[j][k]-'a']++;
			int flag=1;
			for(int k=0;k<26;k++)if(num[k]>rule[k]){flag=0;break;}
			if(flag==0)continue;
			if(score[i]+score[j]>maxs){ansn=0;maxs=score[i]+score[j];}
			//fout<<strcmp(dict[i],dict[j])<<endl;
			if(strcmp(dict[i],dict[j])<0)
			{
				memcpy(ans[ansn].a,dict[i],sizeof(char)*10);
				memcpy(ans[ansn].b,dict[j],sizeof(char)*10);
			}	
			else
			{
				memcpy(ans[ansn].b,dict[i],sizeof(char)*10);
				memcpy(ans[ansn].a,dict[j],sizeof(char)*10);
			}				
			ansn++;
		}
	qsort(ans,ansn,sizeof(ans[0]),cmp);
	fout<<maxs<<endl;//fout<<tot<<endl;
	for(int i=0;i<ansn;i++)
		if(isalpha(ans[i].b[0]))
			fout<<ans[i].a<<" "<<ans[i].b<<endl;
		else fout<<ans[i].a<<endl;
	return 0;
}

