/*
ID:selfcon2
LANG:C++
PROB:calfflac
*/
#include <cstdio>
#include <cstring>
#include <cctype>
using namespace std;
static int f[30000],p[30000];
char ch,a[30000],b[30000];
int main()
{
    FILE *fin,*fout;
    fin=fopen("calfflac.in","rb");fout=fopen("calfflac.out","wb");
    //-------------------------------------------
    int i=0,k,flag;
    while((ch=fgetc(fin))!=EOF){a[i]=ch;i++;}
    int la=i;
    //-------------------------------------------
    int j=0;
    for(i=0;i<la;i++)if(isalpha(a[i])){b[j]=toupper(a[i]);p[j]=i;j++;}
    int lb=j;
    //-------------------------------------------
    int maxn=0,maxp=0;
    for(i=0;i<lb;i++)
    {
        if(i==0)f[i]=1;
        else if((i-1-f[i-1]>=0)&&(b[i]==b[i-1-f[i-1]]))f[i]=f[i-1]+2;
        else 
            for(j=i-f[i-1];j<=i;j++)
            {
                flag=1;
                for(k=j;k<=i;k++)if(b[k]!=b[i+j-k]){flag=0;break;}
                if(flag){f[i]=i-j+1;break;}
            }
        if(f[i]>maxn){maxn=f[i];maxp=i;}
    }
    fprintf(fout,"%d\n",maxn);
    for(i=p[maxp-maxn+1];i<=p[maxp];i++)fprintf(fout,"%c",a[i]);
    fprintf(fout,"\n");
    //-------------------------------------------
    fclose(fin);fclose(fout);
    return 0;
}
