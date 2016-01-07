/*
ID:selfcon2
LANG:C++
PROG:cryptcow
*/
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;
ifstream fin("cryptcow.in");
ofstream fout("cryptcow.out");
static bool hash[131075];
static string str;
static string aim="Begin the Escape execution at the Break of Dawn";
unsigned int Hash(string s)
{
	unsigned long h=0,g;
    for (int i=0; i<s.length(); i++)
    {
        h=(h<<4)+s[i];
        g=h &0xf0000000l;
        if (g)h^=g>>24;
        h&=~g;
    }
    return h%131075;
}
bool cut(string s)
{
	/*
	if((s.length()-aim.length())%3!=0)return true;
	for(int i=0;i<s.length();i++)
		if(s[i]!='C'&&s[i]!='O'&&s[i]!='W')
		{	if(s[i]!=aim[i])return true;}
		else break;
	for(int i=s.length()-1;i>=0;i--)
		if(s[i]!='C'&&s[i]!='O'&&s[i]!='W')
		{	if(s[i]!=aim[aim.length()-s.length()+i])return true;}
		else break;
	int pre=0;
	while(s[pre]!='C'&&s[pre]!='O'&&s[pre]!='W'&&pre<s.length())pre++;
	int i;
	do
	{
		i=pre+1;
		if(s[i]=='C'||s[i]=='O'||s[i]=='W')
			if(i-pre>1&&aim.find(s.substr(pre+1,i-pre-1))==string::npos)return true;
		pre=i;
	}while(i<s.length());
	return false;
	*/
    if ((s.length()-aim.length())%3!=0)return true;
    int i=0,j;
    while (i<s.length())
    {
        j=i+1;
        if (s[i]!='C' && s[i]!='O' && s[i]!='W')
        {
            while (j<s.length())
            {
                if (s[j]=='C' || s[j]=='O' ||s[j]=='W')break;
                j++;
            }
            if (aim.find(s.substr(i,j-i))==string::npos)return true;
        }
        i=j;
    }
    return false;
}
void dfs(string s,int step)
{
	if(s==aim)
	{
		fout<<"1 "<<step<<endl;
		exit(0);
	}
	int t=Hash(s);
	if(hash[t])return;
	else hash[t]=true;
	if(cut(s))return;
	for(int o=0;o<s.length();o++)
		if(s[o]=='O')
			for(int c=0;c<o;c++)
				if(s[c]=='C')
					for(int w=s.length()-1;w>o;w--)
						if(s[w]=='W')
						{
							/*
							string s2;
							for(int p=0;p<j;p++)s2.push_back(s[p]);
							for(int p=i+1;p<k;p++)s2.push_back(s[p]);
							for(int p=j+1;p<i;p++)s2.push_back(s[p]);
							for(int p=k+1;p<s.length();p++)s2.push_back(s[p]);
							int t=Hash(s2);
							if(!hash[t]){hash[t]=true;dfs(s2,step+1);}
							*/
							int p,ich=0;char  buffer[100];
							for (p=0; p<c; p++)buffer[ich++]=s[p];
							for (p=o+1;p<w; p++)buffer[ich++]=s[p];
							for (p=c+1; p<o; p++)buffer[ich++]=s[p];
							for (p=w+1;p<s.length(); p++)buffer[ich++]=s[p];
							buffer[ich++]=0;
							dfs(string(buffer),step+1);
						}
}
int main()
{
	getline(fin,str);
	dfs(str,0);
	fout<<"0 0"<<endl;
	return 0;	
}
