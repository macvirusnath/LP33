#include<iostream>
using namespace std;
int fibo(int n){
    int a=1;
    int b=1;
    int c=2;
    if(n==1) return a;
    else if(n==2) return b;
    else if(n==3) return c;
     // 1 1 2 3 5 8 13 21 
    for(int i=3;i<n;i++){
        a=b;
        b=c;
        c=a+b;
    }
    return c;
}
int main(){
  int n;
  cout<<"enter the no to find fibo"<<endl;
  cin>>n;
  cout<<"the nth term is "<<fibo(n);
return 0;
}