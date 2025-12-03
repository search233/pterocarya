//7_10

#include<stdio.h>

struct name{
	double S;			//速度
	double H;			//血量 
	double E;			//能量 
	double A;			//攻击
	double rate;	//增益 
};


int judge(double Hj_H, double Rose_H);
int turn_Hj(int a, double *S, double *H, double *E, double *A, double *rate, double *RoH, double *RoE, int cond);
int turn_Rose(int b, double *S, double *H, double *E, double *A, double *rate, double *HjH, double *HjE, int cond);

int main()
{
	struct name Rose, Hj;
	scanf("%lf %lf %lf %lf", &Hj.S, &Hj.H, &Hj.E, &Hj.A);
	scanf("%lf %lf %lf %lf", &Rose.S, &Rose.H, &Rose.E, &Rose.A);
	
	Rose.rate = Hj.rate = 1.0;
	int n, flag=0, round;	scanf("%d", &n);
	// 0:难分胜负，1：Hj胜，2：Rose胜。
	
	
	for(int i=0 ; i<n ; i++){
		
		int a, b;		 
		scanf("%d %d", &a, &b);
		
		int cond_Hj=1, cond_Rose=1;
		
		if(Hj.S>=Rose.S){
			cond_Hj = turn_Hj  (a, &Hj.S, &Hj.H, &Hj.E, &Hj.A, &Hj.rate, &Rose.H, &Rose.E, cond_Hj);
			
			flag = judge(Hj.H, Rose.H);		if(flag){ round=i+1; break;}
			
			cond_Rose = turn_Rose(a, &Rose.S, &Rose.H, &Rose.E, &Rose.A, &Rose.rate, &Hj.H, &Hj.E, cond_Rose);
			
			flag = judge(Hj.H, Rose.H);		if(flag){ round=i+1; break;}
			
			
		}else{
			cond_Rose = turn_Rose(a, &Rose.S, &Rose.H, &Rose.E, &Rose.A, &Rose.rate, &Hj.H, &Hj.E, cond_Rose);
			
			flag = judge(Hj.H, Rose.H);		if(flag){ round=i+1; break;}
			
			cond_Hj = turn_Hj  (a, &Hj.S, &Hj.H, &Hj.E, &Hj.A, &Hj.rate, &Rose.H, &Rose.E, cond_Hj);
			
			flag = judge(Hj.H, Rose.H);		if(flag){ round=i+1; break;}	
		}
	}
	
	if(flag==0)	
		printf("No one fails.");
		
	else if(flag==1)	
		printf("In the %d round,Hj became Rose's father.", round);
		
	else if(flag==2)
		printf("In the %d round,Rose became Hj's father.", round);
	
	return 0;
} 

int judge(double Hj_H,double Rose_H)
{
	if(Hj_H<=0)			return 2;
	else if(Rose_H<=0)	return 1;
	else 				return 0;
} 


int turn_Hj(int a, double *S, double *H, double *E, double *A, double *rate, double *RoH, double *RoE, int cond)
{
	int ret = 1;
	
	switch(a){
		
		case 0: *E += (*H<=3) ? 2 : (*E=5, 0);
				break;
			
		case 1: if(*E>0){ *E -= 1; *S += 5;
				}else ret=0;
				break;						
							
		case 2: if(*E>0){ *E-=1; *rate+=0.3;
				}else ret=0;
				break;
							
		case 3: if(*E>0){ *E -= 1; *RoH-=*A * *rate;
				}else ret=0;
				break;
						
		case 4: if(*E>1){ *E-=2; *rate += 0.1; *RoH-=*A * *rate; *rate += 0.1;			
				}else ret=0;
				break;
		
		case 5: if(*E>2){*RoE -= (*RoE>0) ? (*E+=1, 1) : 0;*RoH -= *A * *rate;
				}else ret =0;
				break;
		
		case 6: *RoH -= *E;	*E = 0;
				break;
	}
	
	if(ret==0){
		*H -= *A;
		*rate -= 0.5;
	}
	
	if(cond==0){
		*rate += 0.5;
	}
	
	return ret;
}

int turn_Rose(int b, double *S, double *H, double *E, double *A, double *rate, double *HjH, double *HjE, int cond)
{
	int ret = 1;
	
	switch(b){
		
		case 0: *E += (*H<=3) ? 2 : (*E=5, 0);
				break;
			
		case 1: if(*E>0){ *E -= 1; *S += 5;
				}else ret=0;
				break;						
							
		case 2: if(*E>0){ *E-=1; *rate+=0.3;
				}else ret=0;
				break;
							
		case 3: if(*E>0){ *E -= 1; *HjH-=*A * *rate;
				}else ret=0;
				break;
						
		case 4: if(*E>1){ *E-=2; *rate += 0.1; *HjH-=*A * *rate; *rate += 0.1;			
				}else ret=0;
				break;
		
		case 5: if(*E>2){*HjE -= (*HjE>0) ? (*E+=1, 1) : 0;*HjH -= *A * *rate;
				}else ret =0;
				break;
		
		case 6: *HjH -= *E;	*E = 0;
				break;
	}
	
	
	if(ret==0){
		*H -= *A;
		*rate -= 0.5;
	}
	
	if(cond==0){
		*rate += 0.5;
	}
	
	return ret;
}
