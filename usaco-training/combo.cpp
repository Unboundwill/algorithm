/*
ID:selfcon2
LANG:C++
PROG:combo
*/
#include <iostream>
#include <cstdio>
#include <fstream>
#include <iostream>

using namespace std;
int a,b,c,d,e,f,N;
bool test(int x,int y){
	if(x<y){
		if(x>=y-2)return true;
		if(x+N<=y+2)return true;
	}else{
		if(x<=y+2)return true;
		if(x>=y+N-2)return true;
	}
	return false;
}
bool check(int x,int y,int z){
	if(test(x,a)&&test(y,b)&&test(z,c))return true;
	if(test(x,d)&&test(y,e)&&test(z,f))return true;
	return false;
}
int main(){
	int ans=0;
	ifstream fin("combo.in");
	ofstream fout("combo.out");
	fin>>N;
	fin>>a>>b>>c>>d>>e>>f;
	for(int i=1;i<=N;i++)
		for(int j=1;j<=N;j++)
			for(int k=1;k<=N;k++)
				if(check(i,j,k))
					ans++;
	fout<<ans<<endl;
	fin.close();
	fout.close();
	return 0;
}
