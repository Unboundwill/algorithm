/*
ID:selfcon2
LANG:C++
PROG:gift1
*/
#include <fstream>
#include <string>
using namespace std;
ifstream fin("gift1.in");
ofstream fout("gift1.out");
static int sum[100],i,j,l,giver,receiver,n,give,given;
static string name[100],s;
int find(string s1){for(l=0;l<n;l++)if(name[l]==s1)return l;}
int main()
{
    fin>>n;
    for(i=0;i<n;i++)fin>>name[i];
    for(j=0;j<n;j++)
    {
        fin>>s;
        giver=find(s);
        fin>>give>>given;
        if(given==0)continue;
        for(i=0;i<given;i++)
        {
            fin>>s;
            receiver=find(s);
            sum[receiver]+=give/given;
            sum[giver]-=give/given;
        }
    }
    for(i=0;i<n;i++){fout<<name[i]<<" "<<sum[i]<<endl;}
    return 0;
}
