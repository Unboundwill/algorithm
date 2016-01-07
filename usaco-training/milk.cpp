/*
ID:selfcon2
LANG:C++
PROB:milk
*/
#include <fstream>
#include <cstdlib>
using namespace std;
struct node{int p,a;};
int cmp(const void * x,const void * y){return (*(node *)x).p-(*(node *)y).p;}
int main()
{
    ifstream fin("milk.in");
    ofstream fout("milk.out");
    int n,m,i,tot;
    node f[5000];
    fin>>n>>m;
    for(i=0;i<n;i++)fin>>f[i].p>>f[i].a;
    qsort(f,m,sizeof(f[0]),cmp);
    tot=0;i=0;
    while(n>0)
    {
        if(n>f[i].a){tot+=f[i].p*f[i].a;n-=f[i].a;}
        else{tot+=f[i].p*n;n=0;}
        i++;
    }
    fout<<tot<<endl;
    return 0;
}
