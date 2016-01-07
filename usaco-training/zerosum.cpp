/*
ID:selfcon2
LANG:C++
PROG:zerosum
*/
#include <fstream>
#include <cstdlib>
using namespace std;
ifstream fin("zerosum.in");
ofstream fout("zerosum.out");
struct node{string s;};
node ans[2000];
static int tot=0,n;
int cmp(const void * x,const void * y)
{
	return (*(node *)x).s.compare((*(node *)y).s);
}
void dfs(int x,string way,int result,int tem,char op)
{
	if(x==n)
	{
		way.push_back((char)(n+'0'));
		tem=tem*10+x;
		if(op=='+')result+=tem;
		else if(op=='-')result-=tem;
		if(result==0){ans[tot].s=way;tot++;}
	}	
	else 	
	{
		way.push_back((char)(x+'0'));tem=tem*10+x;
		string wayt=way;int resultt=result;
		//---------------------'+'/'-'
		if(op=='+')resultt+=tem;
		else if(op=='-')resultt-=tem;
		
		wayt.push_back('+');
		dfs(x+1,wayt,resultt,0,'+');
		wayt=way;
		wayt.push_back('-');
		dfs(x+1,wayt,resultt,0,'-');
		//----------------------' '
		way.push_back(' ');
		dfs(x+1,way,result,tem,op);		
	}
}
int main()
{
	int i;
	fin>>n;
	dfs(1,"",0,0,'+');
	qsort(ans,tot,sizeof(ans[0]),cmp);
	for(i=0;i<tot;i++)fout<<ans[i].s<<endl;
	return 0;	
}
