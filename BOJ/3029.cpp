#include<iostream>
#include<cstdio>
using namespace std;

int main(void){
  int a1,a2,a3;
  int b1,b2,b3;
  scanf("%d:%d:%d",&a1,&a2,&a3);
  scanf("%d:%d:%d",&b1,&b2,&b3);

  int a, b;
  a = a1*60*60+a2*60+a3;
  b = b1*60*60+b2*60+b3;
  if(b<a) {
    b+=24*60*60;
  }
  a = b-a;
  a1 = a/3600;
  a2 = (a%3600)/60;
  a3 = a%60;
  if(a==0) {
    a1=24;
    a2=0;
    a3=0;
  }
  if(a1<10) cout<<0;
  cout<<a1<<':';
  if(a2<10) cout<<0;
  cout<<a2<<':';
  if(a3<10) cout<<0;
  cout<<a3<<endl;

  return 0;
}