/*
ID:selfcon2
LANG:C++
PROG:ttwo
*/
#include <fstream>
using namespace std;
ifstream fin("ttwo.in");
ofstream fout("ttwo.out");
static int a[12][12],hash[11][11][4][11][11][4],t,d1,d2,pf1,pf2,pc1,pc2;
int main()
{
	int i,j;
	char ch;
	for(i=1;i<=10;i++)
		for(j=1;j<=10;j++)
		{
			fin>>ch;
			if(ch=='.')a[i][j]=1;
			else if(ch=='*')a[i][j]=0;
			else if(ch=='F'){a[i][j]=1;pf1=i;pf2=j;}
			else if(ch=='C'){a[i][j]=1;pc1=i;pc2=j;}
		}	
	t=0;d1=0;d2=0;hash[pf1][pf2][d1][pc1][pc2][d2]=1;
	t=0;d1=0;d2=0;hash[pf1][pf2][d1][pc1][pc2][d2]=1;
	while(1)
	{
		t++;
		if(d1==0)
		{
			if(a[pf1-1][pf2])pf1--;
			else d1++;
		}
		else if(d1==1)
		{
			if(a[pf1][pf2+1])pf2++;
			else d1++;			
		}
		else if(d1==2)
		{
			if(a[pf1+1][pf2])pf1++;
			else d1++;			
		}
		else
		{
			if(a[pf1][pf2-1])pf2--;
			else d1=0;			
		}
		
		if(d2==0)
		{
			if(a[pc1-1][pc2])pc1--;
			else d2++;
		}
		else if(d2==1)
		{
			if(a[pc1][pc2+1])pc2++;
			else d2++;			
		}
		else if(d2==2)
		{
			if(a[pc1+1][pc2])pc1++;
			else d2++;			
		}
		else
		{
			if(a[pc1][pc2-1])pc2--;
			else d2=0;			
		}
		if(pf1==pc1&&pf2==pc2){fout<<t<<endl;return 0;}
		if(hash[pf1][pf2][d1][pc1][pc2][d2]){fout<<0<<endl;return 0;}
		hash[pf1][pf2][d1][pc1][pc2][d2]=1;
	}
	return 0;
}
