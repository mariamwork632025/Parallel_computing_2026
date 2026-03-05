#include<iostream>
#include<omp.h>

using namespace std;

static long num_steps=10000;
double step;

int main()
{
double pi=0.0;
double sum=0.0;
int nthreads;
step=1.0/(double)num_steps;
#pragma omp parallel num_threads(2)
{
int i,id;
double x;
id=omp_get_thread_num();
nthreads=omp_get_num_threads();
//cyclic distribution
for(i=id;i<num_steps;i+=nthreads)
{
x=(i+0.5)*step;
sum+=4.0/(1.0+(x*x));
}

pi+=sum*step;

}
cout<<pi<<endl;
return 0;
}
