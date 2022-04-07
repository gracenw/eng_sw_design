#include <iostream>
using namespace std;

double e = 2.71828182845904523536028747135266249775724709369995;

float forward_powerSeries_f();
float backward_powerSeries_f();
double forward_powerSeries_d();
double backward_powerSeries_d();

double e_d[100];
float e_f[100];

int main() {
  cout<<"--------floats\n";
  cout<<"forward approx = "<<forward_powerSeries_f()<<endl;
  cout<<"\%error = "<<(100*(e-forward_powerSeries_f())/e)<<endl;
  cout<<"backward approx = "<<backward_powerSeries_f()<<endl;
  cout<<"\%error = "<<(100*(e-backward_powerSeries_f())/e);
  cout<<"\n--------doubles\n";
  cout<<"forward approx = "<<forward_powerSeries_d()<<endl;
  cout<<"\%error = "<<(100*(e-forward_powerSeries_d())/e)<<endl;
  cout<<"backward approx = "<<backward_powerSeries_d()<<endl;
  cout<<"\%error = "<<(100*(e-backward_powerSeries_d())/e);
}

double forward_powerSeries_d() {
  int k=1;

  for(int i=0;i<100;i++) {
    if(i==0) {
      e_d[0]=1;
    }
    else if(i==1) {
      e_d[1]=1;
    }
    else {
      e_d[i]=(1.0/i)*(1.0/k);
      k=k*i;
    }
  }

  double sum=0;
  for(int a=0;a<20;a++) {
    sum=sum+e_f[a];
  }
  return sum;
}

double backward_powerSeries_d() {
  int k=1;

  for(int i=0;i<100;i++) {
    if(i==0) {
      e_d[0]=1;
    }
    else if(i==1) {
      e_d[1]=1;
    }
    else {
      e_d[i]=(1.0/i)*(1.0/k);
      k=k*i;
    }
  }

  double sum=0;
  for(int a=10;a>=0;a--) {
    sum=sum+e_f[a];
  }
  return sum;
}

float forward_powerSeries_f() {
  int k=1;

  for(int i=0;i<100;i++) {
    if(i==0) {
      e_f[0]=1;
    }
    else if(i==1) {
      e_f[1]=1;
    }
    else {
      e_f[i]=(1.0/i)*(1.0/k);
      k=k*i;
    }
  }

  float sum=0;
  for(int a=0;a<20;a++) {
    sum=sum+e_f[a];
  }
  return sum;
}

float backward_powerSeries_f() {
  int k=1;

  for(int i=0;i<100;i++) {
    if(i==0) {
      e_f[0]=1;
    }
    else if(i==1) {
      e_f[1]=1;
    }
    else {
      e_f[i]=(1.0/i)*(1.0/k);
      k=k*i;
    }
  }

  float sum=0;
  for(int a=10;a>=0;a--) {
    sum=sum+e_f[a];
  }
  return sum;
}
