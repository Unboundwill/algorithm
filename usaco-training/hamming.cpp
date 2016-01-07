/*
ID:selfcon2
LANG:C++
PROG:hamming
*/
#include <fstream>
using namespace std;
ifstream fin("hamming.in");
ofstream fout("hamming.out");
int n,b,d,tot,ans[1000];
int check(int x)
{
	int i,t,flag,okay=1;
	for(i=0;i<tot;i++)
	{
		t=x^ans[i];flag=0;
		while(t){flag+=t-((t>>1)<<1);t=t>>1;}
		if(flag<d){okay=0;break;}
	}
	return okay;	
}
int main()
{
	int i;
	fin>>n>>b>>d;
	ans[0]=0;tot=1;n--;
	while(n)
	{
		int tem=ans[tot-1]+1;
		while(!check(tem))tem++;
		ans[tot]=tem;tot++;n--;		
	}
	for(i=0;i<tot;i++){if(i%10)fout<<" ";fout<<ans[i];if((i+1)%10==0)fout<<endl;}
	if((tot)%10!=0)fout<<endl;
	return 0;
}
