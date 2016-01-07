/*
ID:selfcon2
LANG:C++
PROB:sprime
*/
#include <fstream>
#include <cmath>
using namespace std;
int main()
{
    ifstream fin("sprime.in");
    ofstream fout("sprime.out");
    static int sprime[5000],a[10];
    int i,j,d1,flag,tem,tot=0,n,head1,head2;
    sprime[0]=2;tot++;
    for(d1=3;d1<=9;d1+=2)
    {
        int tem=d1;flag=1;
        for(i=2;i<=floor(sqrt(tem));i++)if(tem%i==0){flag=0;break;}
        if(flag){sprime[tot]=tem;tot++;}
    }
    head1=0;head2=tot;a[1]=head2;
    for(j=head1;j<head2;j++)
        for(d1=1;d1<=9;d1+=2)
    {
        int tem=sprime[j]*10+d1;flag=1;
        for(i=2;i<=floor(sqrt(tem));i++)if(tem%i==0){flag=0;break;}
        if(flag){sprime[tot]=tem;tot++;}
    }
    head1=head2;head2=tot;a[2]=head2;
        for(j=head1;j<head2;j++)
        for(d1=1;d1<=9;d1+=2)
    {
        int tem=sprime[j]*10+d1;flag=1;
        for(i=2;i<=floor(sqrt(tem));i++)if(tem%i==0){flag=0;break;}
        if(flag){sprime[tot]=tem;tot++;}
    }
    head1=head2;head2=tot;a[3]=head2;
    for(j=head1;j<head2;j++)
        for(d1=1;d1<=9;d1+=2)
    {
        int tem=sprime[j]*10+d1;flag=1;
        for(i=2;i<=floor(sqrt(tem));i++)if(tem%i==0){flag=0;break;}
        if(flag){sprime[tot]=tem;tot++;}
    }
    head1=head2;head2=tot;a[4]=head2;
    for(j=head1;j<head2;j++)
        for(d1=1;d1<=9;d1+=2)
    {
        int tem=sprime[j]*10+d1;flag=1;
        for(i=2;i<=floor(sqrt(tem));i++)if(tem%i==0){flag=0;break;}
        if(flag){sprime[tot]=tem;tot++;}
    }
    head1=head2;head2=tot;a[5]=head2;
    for(j=head1;j<head2;j++)
        for(d1=1;d1<=9;d1+=2)
    {
        int tem=sprime[j]*10+d1;flag=1;
        for(i=2;i<=floor(sqrt(tem));i++)if(tem%i==0){flag=0;break;}
        if(flag){sprime[tot]=tem;tot++;}
    }
    head1=head2;head2=tot;a[6]=head2;
    for(j=head1;j<head2;j++)
        for(d1=1;d1<=9;d1+=2)
    {
        int tem=sprime[j]*10+d1;flag=1;
        for(i=2;i<=floor(sqrt(tem));i++)if(tem%i==0){flag=0;break;}
        if(flag){sprime[tot]=tem;tot++;}
    }
    head1=head2;head2=tot;a[7]=head2;
    for(j=head1;j<head2;j++)
        for(d1=1;d1<=9;d1+=2)
    {
        int tem=sprime[j]*10+d1;flag=1;
        for(i=2;i<=floor(sqrt(tem));i++)if(tem%i==0){flag=0;break;}
        if(flag){sprime[tot]=tem;tot++;}
    }
    head1=head2;head2=tot;a[8]=head2;
    fin>>n;
    for(i=a[n-1];i<a[n];i++)fout<<sprime[i]<<endl;
    return 0;
}
