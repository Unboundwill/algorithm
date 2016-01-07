/*
ID:selfcon2
LANG:C++
PROB:transform
*/
#include <fstream>
#include <cstring>
using namespace std; 
ifstream fin("transform.in");
ofstream fout("transform.out");
int main()
{
    int n,i,j,flag;
    static char a[100][100],b[100][100],tem1[100][100];
    fin>>n;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)fin>>a[i][j];
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)fin>>b[i][j];
    //----------------------------------
    flag=1;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)if(b[j][n-i+1]!=a[i][j]){flag=0;break;}
    if(flag){fout<<1<<endl;return 0;}
    //----------------------------------
    flag=1;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)if(b[n-i+1][n-j+1]!=a[i][j]){flag=0;break;}
    if(flag){fout<<2<<endl;return 0;}
    //----------------------------------
    flag=1;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)if(b[n-j+1][i]!=a[i][j]){flag=0;break;}
    if(flag){fout<<3<<endl;return 0;}
    //----------------------------------
    flag=1;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)if(b[i][n-j+1]!=a[i][j]){flag=0;break;}
    if(flag){fout<<4<<endl;return 0;}
    //----------------------------------
    flag=1;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)tem1[i][n-j+1]=a[i][j];
    flag=1;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)if(b[j][n-i+1]!=tem1[i][j]){flag=0;break;}
    if(flag){fout<<5<<endl;return 0;}
    flag=1;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)if(b[n-i+1][n-j+1]!=tem1[i][j]){flag=0;break;}
    if(flag){fout<<5<<endl;return 0;}
    flag=1;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)if(b[n-j+1][i]!=tem1[i][j]){flag=0;break;}
    if(flag){fout<<5<<endl;return 0;}
    //----------------------------------
    flag=1;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)if(b[i][j]!=a[i][j]){flag=0;break;}
    if(flag){fout<<6<<endl;return 0;}
    //----------------------------------
    fout<<7<<endl;
    return 0;
}

