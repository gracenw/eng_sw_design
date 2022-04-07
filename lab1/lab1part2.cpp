#include <iostream>
#include <cmath>

using namespace std;

float rootFloat(int,float,float,float);
double rootDouble(int,double,double,double);

int main() {
        float result_f_pos=rootFloat(1,1,3000.001,3);
	float result_f_neg=rootFloat(0,1,3000.001,3);
	double result_d_pos=rootDouble(1,1,3000.001,3);
	double result_d_neg=rootDouble(0,1,3000.001,3);
	
	float error_f_pos=100*(-.001-result_f_pos)/(-.001);
	float error_f_neg=100*(-3000-result_f_neg)/(-3000);
	double error_d_pos=100*(-.001-result_d_pos)/(-.001);
	double error_d_neg=100*(-3000-result_d_neg)/(-3000);

	cout<<"Using the float data type the roots are: "<<"\n x1= "<<result_f_pos<<"\t\% error= "<<error_f_pos<<"\n x2= "<<result_f_neg<<"\t\t\% error= "<<error_f_neg<<endl;
	cout<<"Using the double data type the roots are: "<<"\n x1= "<<result_d_pos<<"\t\t\% error= "<<error_d_pos<<"\n x2= "<<result_d_neg<<"\t\t\% error= "<<error_d_neg<<endl;
}

float rootFloat(int sign,float a, float b,float c) {
	float x=0;
	if(sign==0) {
		x=(-b-sqrt((b*b)-(4*a*c)))/(2*a);
	}
	else {
		x=(-b+sqrt((b*b)-(4*a*c)))/(2*a);
	}
	return x;
}

double rootDouble(int sign,double a,double b,double c) {
	double x=0;
        if(sign==0) {
                x=(-b-sqrt((b*b)-(4*a*c)))/(2*a);
        }
        else {
                x=(-b+sqrt((b*b)-(4*a*c)))/(2*a);
        }
        return x;
}
