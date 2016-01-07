/*
ID:selfcon2
LANG:C++
TASK:ride
*/
#include <fstream>
#include <string>
using namespace std;
ifstream fin("ride.in");
ofstream fout("ride.out");
int main()
{
    string s;
    int i,ans=1,ans0=1;
    fin>>s;for(i=0;i<s.length();i++){ans*=s[i]-'A'+1;}ans%=47;
    fin>>s;for(i=0;i<s.length();i++){ans0*=s[i]-'A'+1;}ans0%=47;
    if(ans==ans0)fout<<"GO"<<endl;
    else fout<<"STAY"<<endl;
    return 0;
}
