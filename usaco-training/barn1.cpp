/*
ID:selfcon2
LANG:C++
PROG:barn1
*/
#include <fstream>
#include <cstdlib>
using namespace std;
int cmp(const void * x,const void * y){return *(int *)y-*(int *)x;}
int cmp2(const void * x,const void * y){return *(int *)x-*(int *)y;}
int main()
{
    ifstream fin("barn1.in");
    ofstream fout("barn1.out");
    int m,s,c,i,tot,las,hea,a[1000],b[1000];
    fin>>m>>s>>c;
    for(i=0;i<c;i++)fin>>b[i];
    qsort(b,c,sizeof(b[0]),cmp2);
    hea=b[0];las=b[c-1];
    for(i=0;i<c-1;i++)a[i]=b[i+1]-b[i]-1;
    qsort(a,c-1,sizeof(a[0]),cmp);
    m--;tot=las-hea+1;i=0;
    while(m>0)
    {
        tot-=a[i];
        m--;i++;
    }
    fout<<tot<<endl;
    return 0;
}
