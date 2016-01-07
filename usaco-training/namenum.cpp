/*
ID:selfcon2
LANG:C++
PROB:namenum
*/
#include <fstream>
#include <string>
using namespace std;
int main()
{
    const char a[26]={'2','2','2','3','3','3','4','4','4','5','5','5','6','6','6','7','0','7','7','8','8','8','9','9','9','0'};
    string s,name;
    int i,l,exist,flag;
    ifstream fin("namenum.in");
    ofstream fout("namenum.out");
    fin>>s;l=s.length();exist=0;
    ifstream findict("dict.txt");
    while(findict>>name)
    {
        flag=0;
        if(name.length()==l)
        {
            flag=1;
            for(i=0;i<l;i++)if(a[name[i]-'A']!=s[i]){flag=0;break;}
            if(flag){exist=1;fout<<name<<endl;}
        }
    }
    if(!exist)fout<<"NONE"<<endl;
    return 0;
}
