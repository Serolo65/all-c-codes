#include <iostream>
#include <iomanip>
using namespace std;

int main(){

    const int num=4;

double A[num]= {0.57,0.47,0.67,0.37};

double temp;

for(int i=0;i<4;i++){

for(int k=i+1;i<4;i++){

if(A[i]>A[k]){

temp=A[i];

A[i]=A[k];

A[k]=temp;

}}}

for(int i=0;i<4;i++){

cout<<A[i]<<",";}


}
