/*
ID:selfcon2
LANG:C++
PROG:ratios
*/
#include <fstream>
using namespace std;
ifstream fin("ratios.in");
ofstream fout("ratios.out");
int main()
{
	static int A,B,C,i,j,k,l,a[4],b[4],c[4],suma,sumb,sumc,tot;
	fin>>A>>B>>C;
	for(i=0;i<3;i++)fin>>a[i]>>b[i]>>c[i];
	for(i=1;i<=297;i++)
		for(j=0;j<=i;j++)
			for(k=0;j+k<=i;k++)
			{
				l=i-j-k;
				suma=a[0]*j+a[1]*k+a[2]*l;
				sumb=b[0]*j+b[1]*k+b[2]*l;
				sumc=c[0]*j+c[1]*k+c[2]*l;
				tot=suma/A;
				if(suma==A*tot&&sumb==B*tot&&sumc==C*tot){fout<<j<<" "<<k<<" "<<l<<" "<<tot<<endl;return 0;}
			}
	fout<<"NONE\n";
	return 0;
}

