/*
ID:selfcon2
LANG:C++
PROB:beads
*/
#include <fstream>
#include <cstring>
using namespace std;
ifstream fin("beads.in");
ofstream fout("beads.out");
int main()
{
    int i,n,maxn;
    static char a[1000],color;
    static int l[1000],r[1000];
    fin>>n;
    for(i=0;i<n;i++){fin>>a[i];a[n+i]=a[i];}
    for(i=n;i<2*n;i++)
    {
        while((l[i-n]<n)&&(a[i-l[i-n]]=='w'))l[i-n]++;
        color=a[i-l[i-n]];
        while((l[i-n]<n)&&((a[i-l[i-n]]==color)||(a[i-l[i-n]]=='w')))l[i-n]++;
    }
    for(i=0;i<n;i++)
    {
        while((r[i]<n)&&(a[i+r[i]]=='w'))r[i]++;
        color=a[i+r[i]];
        while((r[i]<n)&&((a[i+r[i]]==color)||(a[i+r[i]]=='w')))r[i]++;
    }
    r[n]=r[0];maxn=0;
    for(i=0;i<n;i++)if(l[i]+r[i+1]>n){maxn=n;break;}else if(l[i]+r[i+1]>maxn)maxn=l[i]+r[i+1];
    fout<<maxn<<endl;
    return 0;
}
