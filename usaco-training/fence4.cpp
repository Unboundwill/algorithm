/*
ID:selfcon2
LANG:C++
PROG:fence4
*/
#include <fstream>
using namespace std;
ifstream fin("fence4.in");
ofstream fout("fence4.out");
static int n,x[205],y[205],ans[205],tot;
int cross(int o,int a,int b)
{
	return (x[a]-x[o])*(y[b]-y[o])-(x[b]-x[o])*(y[a]-y[o]);	
}
int check(int a)
{
	int b=a+1;
	//和视线平行
	if(cross(0,a,b)==0)return 0;
	//被某一栅栏完全遮挡
	for(int i=1;i<=n;i++)
		if(i!=a)
		{
			if(cross(i,i+1,a)*cross(i,i+1,0)<=0&&cross(i,i+1,b)*cross(i,i+1,0)<=0)//fence i lets fence a and point o in the different sides
				if(cross(0,a,i)*cross(0,a,i+1)<=0&&cross(0,b,i)*cross(0,b,i+1)<=0)//angle io(i+1) contains angle aob
					return 0;
		}
	//被部分遮挡
	if(cross(0,a,b)<0)swap(a,b);
	int a0=a,b0=b;
	for(int i=1;i<=n;i++)
	{
		if(cross(0,a,i)>0&&cross(b,0,i)>0&&cross(a,b,i)>0)//if point i is in triangle oab
		{
			if(cross(0,i,i+1)>0&&cross(0,b0,i)<0)b0=i;//if i+1 is in the left of oi and i is in the right of b0  
			if(cross(0,i,i+1)<0&&cross(0,a0,i)>0)a0=i;//if i+1 is in the right of oi and i is in the left of a0
		}
		if(cross(0,a,i+1)>0&&cross(b,0,i+1)>0&&cross(a,b,i+1)>0)//if point i+1 is in triangle oab
		{
			if(cross(0,i+1,i)>0&&cross(0,b0,i+1)<0)b0=i+1;//if i is in the left of o(i+1) and i+1 is in the right of b0  
			if(cross(0,i+1,i)<0&&cross(0,a0,i+1)>0)a0=i+1;//if i is in the right of o(i+1) and i+1 is in the left of a0
		}
	}
	if(cross(0,a0,b0)>0)return 1;else return 0;
}
int main()
{
	//init
	fin>>n;
	fin>>x[0]>>y[0];
	for(int i=1;i<=n;i++)fin>>x[i]>>y[i];
	x[n+1]=x[1];y[n+1]=y[1];
	//judge if the fence is possible
	for(int i=1;i<n;i++)
		for(int j=i+1;j<=n;j++)
		{
			if((cross(i,i+1,j)*cross(i,i+1,j+1)<0)&&(cross(j,j+1,i)*cross(j,j+1,i+1)<0))
			{
				fout<<"NOFENCE"<<endl;
				return 0;
			}
		}
	//judge if the fence is hiden by others
	for(int i=1;i<=n;i++)
		if(check(i))
		{
			ans[tot]=i;
			tot++;
		}
	//judge if the last fence and the second last fence is in right order
	if(ans[tot-1]==n&&ans[tot-2]==n-1)swap(ans[tot-1],ans[tot-2]);
	//print
	fout<<tot<<endl;
	for(int i=0;i<tot;i++)
		if(ans[i]==n)fout<<x[1]<<" "<<y[1]<<" "<<x[ans[i]]<<" "<<y[ans[i]]<<endl;
			else fout<<x[ans[i]]<<" "<<y[ans[i]]<<" "<<x[ans[i]+1]<<" "<<y[ans[i]+1]<<endl;
	return 0;
}


