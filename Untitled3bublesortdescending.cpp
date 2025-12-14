#include <iostream>
#include<iomanip>
using namespace std;

int main(){

const int num=5;
int p[num]={5, 9, 3, 7, 2} ,temp;

for(int i=0;i<5;i++){
    for(int k=i+1;k<4;k++){
        if(p[i]<p[k]){
            temp=p[i];
            p[i]=p[k];
            p[k]=temp;

        }
    }
}
for(int i=0;i<5;i++){
    cout<<p[i];
}


}
