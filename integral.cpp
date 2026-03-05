#include<iostream>
#include<omp.h>
#include<math.h>
using namespace std;
double testf(double x)
{return x*x+2*sin(x);}


double integral(double st,double en,int div,double (*f)(double))
{
double localRes=0;
double step=(en-st)/div;

double x=st;

localRes=f(st)+f(en);
localRes/=2;

for(int i=1;i<div;i++)
{
x+=step;
localRes+=f(x);
}
localRes+=step;
return localRes;

}


int main(int argc,char *argv[])
{
if(argc==1)
exit(1);

double start,end;
int divisions;

start=atof(argv[1]);
end=atof(argv[2]);
divisions=atoi(argv[3]);

double finalRes=0.0;

int n=omp_get_max_threads();
divisions=(divisions/n)*n;
double step=(end-start)/divisions;
#pragma omp parallel
{
int localDiv=divisions/n;
int id=omp_get_thread_num();
double localSt=start+id*localDiv*step;
double localEn=localSt+localDiv*step;

finalRes+=integral(localSt,localEn,localDiv,testf);

}
cout<<finalRes<<endl;




return 0;
}
