/*
ID:selfcon2
LANG:C++
PROG:fracdec
*/
#include <fstream>
using namespace std;
ifstream fin("fracdec.in");
ofstream fout("fracdec.out");
static int n,d,t,l,tot,i,mod,len,flag,okay,a[100000],hash[1000000];
int main()
{
	fin>>n>>d;
	a[0]=n/d;mod=n%d;tot=0;
	t=a[0];l=0;
	while(t){l++;t/=10;}if(a[0]==0)l=1;
	while(1)
	{
		
		tot++;a[tot]=mod*10/d;
		mod=mod*10%d;
		if(mod==0){flag=0;break;}
		if(hash[mod]){flag=hash[mod];break;}else hash[mod]=tot;
	}
	okay=flag;
	if(flag)
		while(a[flag]==a[tot]){flag--;tot--;}
	if(!okay)
	{
		len=l+1;
		fout<<a[0]<<".";for(i=1;i<=tot;i++){fout<<a[i];len++;if(len%76==0)fout<<endl;}
	}
	else 	
	{
		len=l+1;
		fout<<a[0]<<".";
		for(i=1;i<=flag;i++){fout<<a[i];len++;if(len%76==0)fout<<endl;}
		fout<<"(";len++;if(len%76==0)fout<<endl;
		for(i=flag+1;i<=tot;i++){fout<<a[i];len++;if(len%76==0)fout<<endl;}
		fout<<")";len++;if(len%76==0)fout<<endl;
	}
	if(len%76)fout<<endl;
	return 0;
}





