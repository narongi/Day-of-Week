#include <stdio.h>
int totaldays (int d, int m, int y){
	int s=d;
	for(int i=0;i<m;i++){
		if(y%4==0 && y%100!=0){
			s+=365;
		}
		else{
			s+=366;
		}
	}
	int month[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	if (y%4==0 && y%100!=0){
		month[1]=29;
	}
	for(int i=0;i<m;i++){
		s+=month[i];
	}
	printf("%d/%d/%d\n",d,m,y);
	return s;
}
void dayofweek (int s){
	int dayofweek=(s%7);
	switch (dayofweek){
		case 0:	{printf("monday\n");break;}
		case 1: {printf("tuesday\n");break;}
		case 2: {printf("wednesday\n");break;}
		case 3: {printf("thurdays\n");break;}
		case 4: {printf("friday\n");break;}
		case 5: {printf("saturday\n");break;}
		case 6:{printf("sunday\n");break;}
	}
}
int main (){
	int d=24,m=12,y=0,menu=0,no=0;
	do{
		printf("1-change date\n");
		printf("2-print day of week\n");
		printf("other-exit\n");
		scanf("%d",&menu);
		fflush(stdin);
		switch (menu){
			case 1:{
				int yes=1,a=d,b=m,c=y;
				printf("day=");
				scanf("%d",&d);
				if(d<=0||d>31){yes=0;}
				if(yes==1){
					printf("month=");
					scanf("%d",&m);
					if(m<=0||m>12){yes=0;}
					}
				if(yes==1){
					printf("year=");
					scanf("%d",&y);
				}
				if(yes==0){
					printf("invalid input\n");
				d=a,m=b,y=c;
				}
				menu=0;	
				break;
			}
			case 2:{
				int e=totaldays(d,m,y);
				dayofweek(e);
				menu=0;
				break;
			}
			default:{
				no=1;
				break;
			}
		}
	}	while(no==0);
}
