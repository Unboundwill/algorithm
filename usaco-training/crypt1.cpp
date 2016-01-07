/*
ID:selfcon2
LANG:C++
PROB:crypt1
*/
#include <fstream>
using namespace std; 
int main()
{
    ifstream fin("crypt1.in");
    ofstream fout("crypt1.out");
    int n,i,j,k,l,m,ans=0;
    static int a[100],b[100];
    fin>>n;
    for(i=0;i<n;i++){fin>>a[i];b[a[i]]=1;}
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            for(k=0;k<n;k++)
            {
                int tem=a[i]*100+a[j]*10+a[k];
                for(l=0;l<n;l++)
                    for(m=0;m<n;m++)
                    {
                        int tem1=tem*a[m],tem2=tem*a[l],tem3=tem1*10+tem2;
                        if((tem1>=100)&&(tem1<=999)&&(tem2>=100)&&(tem2<=999)&&(tem3>=1000)&&(tem3<=9999)&&b[tem1%10]&&b[tem1/10-tem1/100*10]&&b[tem1/100]&&b[tem2%10]&&b[tem2/10-tem2/100*10]&&b[tem2/100]&&b[tem3%10]&&b[tem3/10-tem3/100*10]&&b[tem3/100-tem3/1000*10]&&b[tem3/1000])ans++;
                    }
            }
    fout<<ans<<endl;
    return 0;
}
