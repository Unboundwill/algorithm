/*
ID:selfcon2
LANG:C++
PROB:friday
*/
#include <fstream>
using namespace std;
ifstream fin("friday.in");
ofstream fout("friday.out");
int main()
{
    int n,tem,i,j;
    const int day[12]={31,31,0,31,30,31,30,31,31,30,31,30};
    static int sum[7];
    fin>>n;tem=4;
    for(i=1900;i<1900+n;i++)
    {
        for(j=0;j<=11;j++)
            if(j!=2){tem=(tem+day[j])%7;sum[tem]++;}
            else if((i%400==0)||((i%4==0)&&(i%100!=0))){tem=(tem+29)%7;sum[tem]++;}
            else {tem=(tem+28)%7;sum[tem]++;}
    }
    for(i=0;i<7;i++){if(i)fout<<" ";fout<<sum[i];}fout<<endl;
    return 0;
}
