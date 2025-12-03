//1004

#include<iostream> 

using namespace std;

struct list{
	char name[13]={0,};
	char ID[13]={0,};
	int score;
}List[1000];

int main(){
	int n;	cin >> n;
	int max=0, min=0;
	int max_ID=0, min_ID=0;
	
	for(int i=0 ; i<n ; i++){
		
		cin >> List[i].name >> List[i].ID >> List[i].score;
		
		if(i==0){
			max = min = List[i].score;
		}else if(List[i].score<min){
			min = List[i].score;
			min_ID = i;
		}else if(List[i].score>max){
			max = List[i].score;
			max_ID = i;
		}
	}
	
	cout << List[max_ID].name << " " << List[max_ID].ID << endl;
	cout << List[min_ID].name << " " << List[min_ID].ID << endl;
	
	return 0;
}
