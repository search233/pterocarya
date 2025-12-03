//gcd (cpp)

#include<iostream>
using namespace std;


int gcd(int a, int b);
void sort(int *a, int *b);

int main()
{
	int a, b; 
	cin >> a >> b;
	
	sort(&a, &b);
	
	cout << gcd(a, b);
	return 0;
}

void sort(int *a, int *b){
	if(a<b)	
	*a += *b, *b = *a-*b, *a -= *b;
}

int gcd(int a, int b){
	
	return  (a%b==0) ? b : gcd(b, a%b);
}
