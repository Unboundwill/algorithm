/*
ID:selfcon2
LANG:C++
PROG:prime3
*/
#include <fstream>
#include <string>
#include <cstring>
#include <cstdlib>
using namespace std;
ifstream fin("prime3.in");
ofstream fout("prime3.out");
static int s,tot;
static int 
	a1,a2,a3,a4,a5,
	b1,b2,b3,b4,b5,
	c1,c2,c3,c4,c5,
	d1,d2,d3,d4,d5,
	e1,e2,e3,e4,e5;
static bool prime[100000];
struct node{string str;}ans[1000];
int cmp(const void * x,const void * y)
{
	return (*(node *)x).str.compare((*(node *)y).str);
}
int main()
{
	fin>>s>>a1;
	memset(prime,true,sizeof(prime));
	prime[1]=false;
	for(int i=2;i<=100000;i++)
		if(prime[i])
			for(int j=2;i*j<=100000;j++)
				prime[i*j]=false;
	for(int i=1;i<=10000;i++)prime[i]=false;
	//-------------------------------------------------------------
	for(b2=0;b2<=9;b2++)
	{
		if(b2+a1>=s)break;
		for(c3=0;c3<=9;c3++)
		{
			if(a1+b2+c3>=s)break;
			for(d4=0;d4<=9;d4++)
			{
				if(a1+b2+c3+d4>=s)break;
				e5=s-a1-b2-c3-d4;
				if(e5<=9)
				if(prime[a1*10000+b2*1000+c3*100+d4*10+e5])//左上 到 右下
					for(e1=1;e1<=9;e1+=2)
					{
						if(e1+e5+3>s||a1+e1+3>s||e1+c3+1>s)break;
						for(d2=0;d2<=9;d2++)
						{
							if(e1+d2+c3>=s)break;
							for(b4=0;b4<=9;b4++)
							{
								if(e1+d2+c3+b4>=s)break;
								a5=s-(e1+d2+c3+b4);
								if(a5<=9)
								if(prime[e1*10000+d2*1000+c3*100+b4*10+a5])//左下 到 右上
									for(c1=1;c1<=9;c1++)
									{
										if(a1+c1+e1+2>s||c1+c3>=s)break;
										for(c2=0;c2<=9;c2++)
										{
											if(c1+c2+c3>=s)break;
											for(c4=0;c4<=9;c4++)
											{
												if(c1+c2+c3+c4>=s)break;
												c5=s-(c1+c2+c3+c4);
												if(c5<=9)
												if(prime[c1*10000+c2*1000+c3*100+c4*10+c5])//第三行
													for(b1=1;b1<=9;b1++)
													{
														if(a1+b1+c1+e1>=s)break;
														d1=s-(a1+b1+c1+e1);	
														if(d1<=9)
														if(prime[a1*10000+b1*1000+c1*100+d1*10+e1])//第一列
															for(b5=1;b5<=9;b5+=2)
															{
																if(a5+b5+c5+e5>s)break;
																d5=s-(a5+b5+c5+e5);
																if(b1+b2+b4+b5>s)break;
																b3=s-(b1+b2+b4+b5);
																if(d5<=9&&b3<=9)
																if(prime[a5*10000+b5*1000+c5*100+d5*10+e5])//第五列
																	if(prime[b1*10000+b2*1000+b3*100+b4*10+b5])//第二行
																	{
																		if(d1+d2+d4+d5<=s)
																		{
																			d3=s-(d1+d2+d4+d5);
																			if(d3<=9)
																			if(prime[d1*10000+d2*1000+d3*100+d4*10+d5])//第四行
																				for(a2=1;a2<=9;a2++)
																				{
																					if(a1+a2+a5>s)break;
																					if(a2+b2+c2+d2>=s)break;
																					e2=s-(a2+b2+c2+d2);
																					if(e2<=9)
																					if(prime[a2*10000+b2*1000+c2*100+d2*10+e2])//第二列
																						for(a3=1;a3<=9;a3++)
																						{
																							if(a3+b3+c3+d3>=s)break;
																							e3=s-(a3+b3+c3+d3);
																							if(e3<=9)
																							if(prime[a3*10000+b3*1000+c3*100+d3*10+e3])//第三列
																							{	
																								if(a1+a2+a3+a5>s)break;
																								a4=s-(a1+a2+a3+a5);
																								if(a4<=9)
																								if(prime[a1*10000+a2*1000+a3*100+a4*10+a5])//第一行
																									if(a4+b4+c4+d4<s)
																									{
																										e4=s-(a4+b4+c4+d4);
																										if(e4<=9)
																										if(prime[a4*10000+b4*1000+c4*100+d4*10+e4])//第四列
																											if(e1+e2+e3+e4+e5==s)
																												if(prime[e1*10000+e2*1000+e3*100+e4*10+e5])//第五行
																												{
																													string t;
																													t.push_back((char)(a1+'0'));t.push_back((char)(a2+'0'));t.push_back((char)(a3+'0'));t.push_back((char)(a4+'0'));t.push_back((char)(a5+'0'));
																													t.push_back((char)(b1+'0'));t.push_back((char)(b2+'0'));t.push_back((char)(b3+'0'));t.push_back((char)(b4+'0'));t.push_back((char)(b5+'0'));
																													t.push_back((char)(c1+'0'));t.push_back((char)(c2+'0'));t.push_back((char)(c3+'0'));t.push_back((char)(c4+'0'));t.push_back((char)(c5+'0'));
																													t.push_back((char)(d1+'0'));t.push_back((char)(d2+'0'));t.push_back((char)(d3+'0'));t.push_back((char)(d4+'0'));t.push_back((char)(d5+'0'));
																													t.push_back((char)(e1+'0'));t.push_back((char)(e2+'0'));t.push_back((char)(e3+'0'));t.push_back((char)(e4+'0'));t.push_back((char)(e5+'0'));
																													ans[tot].str=t;
																													tot++;																												
																												}	
																									}		
																							}
																						}	
																				}	
																		}
																	}
															}	
													}	
											}	
										}
									}	
							}
						}
					}	
			}
		}
	}	
	qsort(ans,tot,sizeof(ans[0]),cmp);
	for(int i=0;i<tot;i++)
	{
		if(i)fout<<endl;
		for(int j=0;j<25;j++)
		{
			fout<<ans[i].str[j];
			if((j+1)%5==0)fout<<endl;
		}	
	}	
	return 0;
}
