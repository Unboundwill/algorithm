/*
ID:selfcon2
LANG:C++
PROG:contact
*/
#include <fstream>
#include <string>
using namespace std;
ifstream fin("contact.in");
ofstream fout("contact.out");
struct node{int sum;string str;}hash[32768];
static int A,B,N,n,i,l,tem,pre,s[200005],flag,tot;
static char ch;
int cmp(const void * x,const void * y)
{
	if((*(node *)x).sum!=(*(node *)y).sum)return (*(node *)y).sum-(*(node *)x).sum;
	else if((*(node *)x).str.length()!=(*(node *)y).str.length()) return (*(node *)x).str.length()-(*(node *)y).str.length();
	else return (*(node *)x).str.compare((*(node *)y).str);	
}
int main()
{
	fin>>A>>B>>n;
	i=0;
	while(fin>>ch)
	{
		if(ch=='0')s[i]=0;else s[i]=1;i++;	
	}
	N=i;
	for(i=0;i<N;i++)
	{
		pre=i;tem=1;l=0;
		do
		{
			tem=tem<<1;tem+=s[pre];l++;
			if(l>=A)hash[tem].sum++;
			pre--;
		}while(pre>=0&&l<B);
	}
	for(i=2;i<=(1<<(B+1));i++)
	{
		tem=i;
		while(tem!=1)
		{
			hash[i].str.push_back((char)(tem%2+'0'));
			tem=tem>>1;			
		}
	}
	qsort(hash,1<<(B+1),sizeof(hash[0]),cmp);
	pre=0;flag=0;tot=0;i=0;
	while(1)
	{
		if(hash[i].sum!=pre)
		{
			pre=hash[i].sum;flag=0;tot++;
			if(tot>n||pre==0)break;
			else 
			{
				fout<<pre<<endl;
				fout<<hash[i].str;flag++;
				if(hash[i+1].sum!=pre)fout<<endl;
			}
		}
		else
		{
			if(flag%6!=0)fout<<" ";
			fout<<hash[i].str;flag++;
			if(flag%6==0||hash[i+1].sum!=pre)fout<<endl;
		}
		i++;	
	}
	return 0;
}

