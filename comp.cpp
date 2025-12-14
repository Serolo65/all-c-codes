#include <iostream>
using namespace std;

int main(){
int a,b,c;
int results;
cin>>a;
cin>>b;
cin>>c;

if(a>b){
    results=a;}
if(a>c){
    results=a;}
if(b>a){
    results=b;}
if(b>a){
    results=b;}
if(c>a){
    results=c;}
if(c>b){
    results=c;}

cout<<results;


return 0;}
