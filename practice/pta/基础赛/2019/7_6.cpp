//7_6

#include<stdio.h>

int main(){
	int t;	scanf("%d", &t);
	 
	for(int i=0 ; i<t ; ++i){
		int n, c, k;	scanf("%d %d %d", &n, &c, &k);
		for(int j=1 ; j<n ; ++j){
			int id;
			char ch;
			scanf("%d %c", &id, &ch);
			
			if(id<k){
				--c;
			}else if(ch=='Y'){
				c -= 2;
			}
		}
		
		if(c>0){
			printf("heihei\n");
		}else{
			printf("awsl\n");
		}
	} 
	
	return 0;
}
