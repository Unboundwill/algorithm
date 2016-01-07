/*
ID:selfcon2
LANG:C++
PROG:fence3
*/
#include <fstream>
#include <cmath>
#include <ctime>
using namespace std;
ifstream fin("fence3.in");
ofstream fout("fence3.out");
struct node{int x1,x2,y1,y2;}fence[2000];
double ansx,ansy,ans;
int n;
bool check(double x,double y)
{
	double tx1,tx2,ty1,ty2,dis=0;
	for(int i=0;i<n;i++)
	{
		tx1=fence[i].x1;ty1=fence[i].y1;
		tx2=fence[i].x2;ty2=fence[i].y2;
		if(tx1==tx2)
		{
			if(ty1>ty2)swap(ty1,ty2);
			if(y<ty1)dis=dis+sqrt((x-tx1)*(x-tx1)+(y-ty1)*(y-ty1));
			else if(y>ty2)dis=dis+sqrt((x-tx2)*(x-tx2)+(y-ty2)*(y-ty2));
			else dis=dis+abs(x-tx1);
		}
		else 
		{	
			if(tx1>tx2)swap(tx1,tx2);
			if(x<tx1)dis=dis+sqrt((x-tx1)*(x-tx1)+(y-ty1)*(y-ty1));
			else if(x>tx2)dis=dis+sqrt((x-tx2)*(x-tx2)+(y-ty2)*(y-ty2));
			else dis=dis+abs(y-ty1);
		}
	}
	if(dis<ans){ansx=x;ansy=y;ans=dis;return true;}
	else return false;
}
int main()
{
	srand(time(0));
	fin>>n;
	for(int i=0;i<n;i++)fin>>fence[i].x1>>fence[i].y1>>fence[i].x2>>fence[i].y2;
	ans =1000000000;int now1=rand()%1001,now2=rand()%1001;
	for (int i =10; i > 0; i --)//直径
		for (int j = 1; j <= 100; j ++)
        {
			int bak1 = now1,bak2 = now2, t = rand() % 4;
			if (t == 0) now1 += i;
			if (t == 1) now1 -= i;
			if (t == 2) now2 += i;
			if (t == 3) now2 -= i;
			if (! check(double(now1)/10, double(now2)/10))
            now1 = bak1, now2 = bak2;
        }
	//B版模拟退火
	fout.setf(ios::fixed);
	fout.precision(1);
	fout<<ansx<<" "<<ansy<<" "<<floor(ans*10+0.5)/10<<endl;
	return 0;
}
