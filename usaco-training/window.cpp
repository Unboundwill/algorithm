/*
ID:selfcon2
LANG:C++
PROG:window
*/
#include <fstream>
#include <cstring>
#include <cctype>
#include <cmath>
using namespace std;
ifstream fin("window.in");
ofstream fout("window.out");
struct node{int x1,x2,y1,y2,see,s;char name;};
node window[80];
static int n;
int cut(node t,int x)
{
	int i=x;
	while(i<n&&(t.x1>=window[i].x2||t.y1>=window[i].y2||t.x2<=window[i].x1||t.y2<=window[i].y1))
		i++;
	if(i==n)return (t.x2-t.x1)*(t.y2-t.y1);	
	int size=0;
	if(t.x1<window[i].x1)
	{
		node tem=t;
		tem.x2=window[i].x1;
		size+=cut(tem,i+1);		
		t.x1=window[i].x1;
	}
	if(t.x2>window[i].x2)
	{
		node tem=t;
		tem.x1=window[i].x2;
		size+=cut(tem,i+1);	
		t.x2=window[i].x2;
	}
	if(t.y1<window[i].y1)
	{
		node tem=t;
		tem.y2=window[i].y1;
		size+=cut(tem,i+1);	
		t.y1=window[i].y1;
	}
	if(t.y2>window[i].y2)
	{
		node tem=t;
		tem.y1=window[i].y2;
		size+=cut(tem,i+1);	
		t.y2=window[i].y2;
	}
	return size;
}
int main()
{
	char ch;
	int x1,x2,y1,y2;
	fout.setf(ios::fixed);
	fout.precision(3);
	while(fin>>ch)
	{
		if(ch=='w')
		{
			fin>>ch;
			fin>>window[n].name;fin>>ch;
			fin>>x1;fin>>ch;
			fin>>y1;fin>>ch;
			fin>>x2;fin>>ch;
			fin>>y2;
			fin>>ch;
			window[n].x1=min(x1,x2);
			window[n].x2=max(x1,x2);
			window[n].y1=min(y1,y2);
			window[n].y2=max(y1,y2);
			window[n].s=(window[n].x2-window[n].x1)*(window[n].y2-window[n].y1);
			window[n].see=window[n].s;
			n++;
		}	
		else if(ch=='t')
		{
			fin>>ch;
			fin>>ch;
			for(int i=0;i<n;i++)
				if(window[i].name==ch)
				{
					for(int j=i+1;j<n;j++)
						swap(window[j-1],window[j]);
					break;					
				}	
			fin>>ch;
		}	
		else if(ch=='b')
		{
			fin>>ch;
			fin>>ch;
			for(int i=0;i<n;i++)
				if(window[i].name==ch)
				{
					for(int j=i-1;j>=0;j--)
						swap(window[j+1],window[j]);
					break;					
				}	
			fin>>ch;
		}	
		else if(ch=='d')
		{
			fin>>ch;
			fin>>ch;
			for(int i=0;i<n;i++)
				if(window[i].name==ch)
				{
					for(int j=i+1;j<n;j++)
						swap(window[j-1],window[j]);
					n--;
					break;					
				}	
			fin>>ch;
		}	
		else if(ch=='s')
		{
			fin>>ch;
			fin>>ch;
			for(int i=0;i<n;i++)
				if(window[i].name==ch)
				{
					window[i].see=cut(window[i],i+1);
					fout<<floor((double)(window[i].see)/window[i].s*100*1000+0.5)/1000<<endl;
				}	
			fin>>ch;
		}	
	}
	//for(int i=0;i<n;i++)
	//	fout<<window[i].name<<" "<<window[i].x1<<" "<<window[i].y1<<" "<<window[i].x2<<" "<<window[i].y2<<" "<<window[i].s<<" "<<window[i].see<<endl;
	return 0;
}

