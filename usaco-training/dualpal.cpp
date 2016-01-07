/*
ID:selfcon2
LANG:C++
PROB:dualpal
*/
#include <fstream>
#include <cstring>
using namespace std;
int main()
{
    ifstream fin("dualpal.in");
    ofstream fout("dualpal.out");
    int n,s,i,j,b,tem,l,flag,pal,a[1000];
    fin>>n>>s;
    for(i=s+1;n>0;i++)
    {
        pal=0;
        for(b=2;b<=10;b++)
        {
            memset(a,0,sizeof(a));tem=i;l=0;
            while(tem>0)
            {
                a[l]=tem%b;
                l++;
                tem/=b;
            }
            flag=1;
            for(j=0;j<l/2;j++)if(a[j]!=a[l-j-1]){flag=0;break;}
            pal+=flag;
            if(pal==2){fout<<i<<endl;n--;break;}
        }
        
    }
    return 0;
}
