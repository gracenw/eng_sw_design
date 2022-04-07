#include <iostream>

int fact_short(int);
long int fact_long(int);

int main() {
	std::cout << "Factorial results using int \n";
	int i;
	int short_val;
	for(i=1;i<=25;i++) {
		short_val=fact_short(i);
		std::cout << i << "! = " << short_val << "\n";
	}
	std::cout << "Factorial results using long int \n";
	long int long_val;
	for(i=1;i<=25;i++) {
		long_val=fact_long(i);
		std::cout << i << "! = " << long_val << "\n";
	}
}

int fact_short(int val) {
	if(val==0) return 1;
	return val*fact_short(val-1);
}

long int fact_long(int val) {
	if(val==0) return 1;
	return val*fact_long(val-1);
}
