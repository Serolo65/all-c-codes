#include <iostream>
using namespace std;

int main(){
//search for value
/**string name[4]={"serolo","joseph","mogofe","junior"},sv="joseph",st="NOT FOUND";

for(int i=0;i<4;i++){
    if(sv==name[i]){
        cout<<"FOUND";
    }
    else{cout<<st;}

}**/
//sort numbers in order
/**int A[5]={2,5,9,4,3},temp;

for(int i=0;i<5;i++){
    for(int k=i+1;k<5;k++){
        if(A[i]>A[k]){
            temp=A[i];
            A[i]=A[k];
            A[k]=temp;
        }
    }
}
for(int i=0;i<5;i++){

        cout<<A[i]<<",";

}**/
//insert values into an array
int x[4];

for(int i=0;i<4;i++){
    cout<<"Enter value "<<i+1<<"\n";
    cin>>x[i];
    cout<<endl;
}
for(int i=0;i<4;i++)
    cout<<x[i]<<",";

return 0;}
