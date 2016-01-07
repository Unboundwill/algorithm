/*
ID:selfcon2
LANG:C++
PROB:skidesign
*/
#include <fstream>
using namespace std;
int main(){
	ifstream fin("skidesign.in");
	ofstream fout("skidesign.out");
	int N;
	int h[10000];
	fin>>N;
	for(int i=0;i<N;i++)fin>>h[i];
	int ans=1000000000;	
	for(int i=0;i<=100-17;i++){
		int t=0;
		for(int j=0;j<N;j++){
			if(h[j]<i)t+=(i-h[j])*(i-h[j]);
			if(h[j]>i+17)t+=(h[j]-i-17)*(h[j]-i-17);
		}
		if(t<ans)ans=t;
	}
	fout<<ans<<endl;
	fin.close();
	fout.close();
	return 0;
}
