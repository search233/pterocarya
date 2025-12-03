//P1042

#include<iostream>
#include<vector>
#include<cstdlib>

using namespace std;


int main()
{
	vector<int> Wcnt1, Wcnt2, Lcnt1, Lcnt2;
	char ch;
	int i=0, j=0;
	
	Wcnt1.push_back(0);
	Lcnt1.push_back(0);
	Wcnt2.push_back(0);
	Lcnt2.push_back(0);
	
	while((ch=getchar())!='E'){
		
		if(ch=='W'){
			Wcnt1[i]++;
			Wcnt2[j]++;
		}else if(ch=='L'){
			Lcnt1[i]++;
			Lcnt2[j]++;
		}
		
		if((Wcnt1[i]>=11 || Lcnt1[i]>=11) && abs(Wcnt1[i]-Lcnt1[i])>=2){
			Wcnt1.push_back(0);
			Lcnt1.push_back(0);
			i++;
		}
		if((Wcnt2[j]>=21 || Lcnt2[j]>=21) && abs(Wcnt2[j]-Lcnt2[j])>=2){
			Wcnt2.push_back(0);
			Lcnt2.push_back(0);
			j++;
		}
	}
	
	for(int k=0 ; k<=i ; k++){
		cout << Wcnt1[k] << ':' << Lcnt1[k] << '\n';
	}
	cout << '\n';
	for(int k=0 ; k<=j ; k++){
		cout << Wcnt2[k] << ':' << Lcnt2[k] << '\n';
	}
	
	return 0;
}
