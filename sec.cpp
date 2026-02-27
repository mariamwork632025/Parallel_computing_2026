#include<iostream>
#include<omp.h>

using namespace std;
int main()
{
cout<<"Masert thread id : "<< omp_get_thread_num()<<endl;
cout<<"Max number of threads: "<<omp_get_max_threads()<<endl;
cout<<"current threads before setting a number of threads :"<< omp_get_num_threads()<<endl;
//omp_set_num_threads(5);

cout<<"current threads after setting a number of threads :"<< omp_get_num_threads()<<endl;
#pragma omp parallel num_threads(6)
{
int id=omp_get_thread_num();
cout<<"Thread id : "<<id<<endl;
cout<<"current threads after setting a number of threads and run parallel pragma :"<< omp_get_num_threads()<<endl;
}

return 0;
}
