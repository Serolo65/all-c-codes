#include <iostream>
#include <iomanip>
using namespace std;

void b(int[],int);

int main(){
    const int arrS=2;
    int A[arrS]={0,1};

    b(A,arrS);
return 0;}

void b(int c[],int d)
{
    for(int i=0;i<d;i++)
    {
        cout<<c[i]<<",";
    }
}
