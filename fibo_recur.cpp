#include<iostream>
using namespace std;
int fibo(int n){
    if(n==1) return 1;
    else if (n==0) return 0;
    else{
        return fibo(n-1)+fibo(n-2);
    }
}
int main(){
  int n;
  cout<<"enter the no to find fibo"<<endl;
  cin>>n;
  cout<<"the nth term is "<<fibo(n);
return 0;
}