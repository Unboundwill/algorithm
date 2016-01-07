/*
ID:selfcon2
LANG:C++
PROG:preface
*/
#include <fstream>
using namespace std;
ifstream fin("preface.in");
ofstream fout("preface.out");
static int ans[10];
void calc(int x)
{
	//-----------------------千位	
	ans[7]+=x/1000;
	//-----------------------百位
	x-=x/1000*1000;
	if(x/100<=3)ans[5]+=x/100;
	else if(x/100==4){ans[6]++;ans[5]+=1;}
	else if(x/100>=5&&x/100<=8){ans[6]++;ans[5]+=x/100-5;}
	else if(x/100==9){ans[7]++;ans[5]++;}
	//-----------------------十位
	x-=x/100*100;
	if(x/10<=3)ans[3]+=x/10;
	else if(x/10==4){ans[4]++;ans[3]+=1;}
	else if(x/10>=5&&x/10<=8){ans[4]++;ans[3]+=x/10-5;}
	else if(x/10==9){ans[5]++;ans[3]++;}
	//-----------------------个位
	x-=x/10*10;
	if(x<=3)ans[1]+=x;
	else if(x==4){ans[2]++;ans[1]+=1;}
	else if(x>=5&&x<=8){ans[2]++;ans[1]+=x-5;}
	else if(x==9){ans[3]++;ans[1]++;}
}
int main()
{
	int i,n;
	fin>>n;
	for(i=1;i<=n;i++)calc(i);
	if(ans[1])fout<<"I "<<ans[1]<<endl;
	if(ans[2])fout<<"V "<<ans[2]<<endl;
	if(ans[3])fout<<"X "<<ans[3]<<endl;
	if(ans[4])fout<<"L "<<ans[4]<<endl;
	if(ans[5])fout<<"C "<<ans[5]<<endl;
	if(ans[6])fout<<"D "<<ans[6]<<endl;
	if(ans[7])fout<<"M "<<ans[7]<<endl;
	return 0;	
}

