/*
ID:selfcon2
LANG:C++
PROG:spin
*/
#include <fstream>
#include <cstring>
using namespace std;
ifstream fin("spin.in");
ofstream fout("spin.out");
static int v[5];
static bool a[5][360],b[5][360];
int main()
{
	for(int i=0;i<5;i++)
	{
		fin>>v[i];
		int t;fin>>t;
		for(int j=0;j<t;j++)
		{
			int t2,l;
			fin>>t2>>l;
			for(int k=t2;k<t2+l;k++)a[i][k%360]=true;
		}
	}
	for(int i=0;i<360;i++)
	{
		for(int j=0;j<5;j++)
			for(int k=0;k<360;k++)
				b[j][(k+v[j]*i)%360]=a[j][k];
		/*for(int j=0;j<5;j++)
		{
			for(int k=0;k<360;k++)fout<<b[j][k];
			fout<<endl;
		}*/
		for(int j=0;j<360;j++)
		{
			int flag=1;
			for(int k=0;k<5;k++)
				if(!b[k][(j+360-1)%360]&&!b[k][j])
				{
					flag=0;break;
				}
			if(flag){fout<<i<<endl;return 0;}
			flag=1;
			for(int k=0;k<5;k++)
				if(!b[k][j]&&!b[k][(j+1)%360])
				{
					flag=0;break;
				}
			if(flag){fout<<i<<endl;return 0;}
		}
	}
	fout<<"none\n";
	return 0;
}
