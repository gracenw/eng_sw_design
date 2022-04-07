#include <iostream>
using namespace std;

void seriesDouble(int);
void seriesFloat(int);

double e= 2.71828182845904523536028747135266249775724709369995;

int main() {
  int n=0;
  int m=0;

  cout<<"\nInput the number of terms in the power series using FLOATS: ";
  cin>>n;
  seriesFloat(n);

  cout<<"\nInput the number of terms in the power series using DOUBLES: ";
  cin>>m;
  seriesDouble(m);
}

void seriesDouble(int n) {
  double sum=2;
  int k=1;

  for(int i=0;i<n;i++) {
    if(i==0) {
      double error=100*(e-1)/e;
      cout<<"--------"<<endl;
      cout<<"#terms = "<<1<<endl;
      cout<<"approx = "<<1<<endl;
      cout<<"\%error = "<<error<<endl;
    }
    else if(i==1) {
      double error=100*(e-2)/e;
      cout<<"--------"<<endl;
      cout<<"#terms = "<<2<<endl;
      cout<<"approx = "<<2<<endl;
      cout<<"\%error = "<<error<<endl;
    }
    else {
      sum=sum+(1.0/i)*(1.0/k);
      k=k*i;

      double error=100*(e-sum)/e;
      cout<<"--------"<<endl;
      cout<<"#terms = "<<i+1<<endl;
      cout<<"approx = "<<sum<<endl;
      cout<<"\%error = "<<error<<endl;
    }
  }
}

void seriesFloat(int n) {
  float sum=2;
  int k=1;

  for(int i=0;i<n;i++) {
    if(i==0) {
      float error=100*(e-1)/e;
      cout<<"--------"<<endl;
      cout<<"#terms = "<<1<<endl;
      cout<<"approx = "<<1<<endl;
      cout<<"\%error = "<<error<<endl;
    }
    else if(i==1) {
      float error=100*(e-2)/e;
      cout<<"--------"<<endl;
      cout<<"#terms = "<<2<<endl;
      cout<<"approx = "<<2<<endl;
      cout<<"\%error = "<<error<<endl;
    }
    else {
      sum=sum+(1.0/i)*(1.0/k);
      k=k*i;

      float error=100*(e-sum)/e;
      cout<<"--------"<<endl;
      cout<<"#terms = "<<i+1<<endl;
      cout<<"approx = "<<sum<<endl;
      cout<<"\%error = "<<error<<endl;
    }
  }
}
