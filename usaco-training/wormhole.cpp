/*
ID:selfcon2
LANG:C++
PROB:wormhole
*/

#include <fstream>
#include <cstring>

using namespace std;
ifstream fin("wormhole.in");
ofstream fout("wormhole.out");
int x[100],y[100];
int pairs[100];
int N;
int ans;
bool v[100],v1[100],v2[100];
bool check(){
	for(int i=0;i<N;i++){
		memset(v1,false,sizeof(v1));
		memset(v2,false,sizeof(v2));
		int p=i;
		bool f=false;
		while(1){
			int pnext=N;
			if(v1[p]){
				f=true;	
				break;
			}
			if(p==N)break;
			v1[p]=true;	
			p=pairs[p];
			v2[p]=true;
			for(int j=0;j<N;j++){
				if(j==p)continue;
				if(y[j]!=y[p])continue;
				if(x[j]>x[p]&&x[j]<x[pnext])pnext=j;
			}
			p=pnext;
		}
		if(f)return true;
	}
	return false;
}
void get_pair(int p){
	if(p==N){
		if(check()){
			ans++;
			//for(int i=0;i<N;i++)fout<<pairs[i];
			//fout<<endl;
		}
		return;
	}
	if(v[p])get_pair(p+1);
	else{
		v[p]=true;
		for(int i=p+1;i<N;i++){
			if(v[i])continue;
			v[i]=true;
			pairs[p]=i;
			pairs[i]=p;
			get_pair(p+1);
			v[i]=false;
		}
		v[p]=false;
	}
}
int main(){

	fin>>N;
	for(int i=0;i<N;i++)
		fin>>x[i]>>y[i];
	x[N]=1000000001;
	ans=0;
	memset(v,false,sizeof(v));
	get_pair(0);
	fout<<ans<<endl;
	fin.close();
	fout.close();
	return 0;
}

