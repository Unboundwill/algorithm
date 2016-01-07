/*
ID:selfcon2
LANG:C++
PROG:hidden
*/
#include <cstdio>
#include <cctype>
#include <cstring>
using namespace std;
FILE *fin,*fout;
static int n;
static char a[200005];
int main()
{
	fin=fopen("hidden.in","rb");
	fout=fopen("hidden.out","wb");
	fscanf(fin,"%d",&n);
	char ch;
	int k=0;
	fscanf(fin,"%c",&ch);
	for(int m=1;m<=n;m++)
	{
		fscanf(fin,"%c",&a[m]);
		while(!isalpha(a[m]))fscanf(fin,"%c",&a[m]);
		a[m+n]=a[m];
	}	
	int i=2,ans=1;
	while(i<=n)
	{
		int j=0;
		while(j<n&&a[i+j]==a[ans+j])j++;
		if(j==n)break;
		if(a[ans+j]>a[i+j]){ans=i;j=0;}
		i+=j+1;
	}
	fprintf(fout,"%d\n",ans-1);
	return 0;
}
