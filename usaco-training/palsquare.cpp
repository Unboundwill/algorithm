/*
ID:selfcon1
LANG:C++
PROG:palsquare
*/
#include <fstream>
#include <string>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;
int main()
{
    ifstream fin("palsquare.in");
    ofstream fout("palsquare.out");
    const char a[20]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J'};
    int i,j,l,l2,tem,b,flag,square[100],num[100];
    fin>>b;
    for(i=1;i<=300;i++)
    {
        tem=i*i;l=0;memset(square,0,sizeof(square));
        while(tem>0)
        {
            square[l]=tem%b;
            tem/=b;
            l++;
        }
        flag=1;
        for(j=0;j<=l/2;j++)if(square[j]!=square[l-j-1]){flag=0;break;}
        if(flag)
        {
            tem=i;l2=0;memset(num,0,sizeof(num));
            while(tem>0)
            {
                num[l2]=tem%b;
                tem/=b;
                l2++;
            }
            for(j=l2-1;j>=0;j--)fout<<a[num[j]];
            fout<<" ";
            for(j=l-1;j>=0;j--)fout<<a[square[j]];
            fout<<endl;
        }
    }
    return 0;
}
