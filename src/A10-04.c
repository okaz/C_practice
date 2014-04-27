#include <stdio.h>
#include <stdlib.h>

void yesterday(int*,int*,int*);
void tomorrow(int*,int*,int*);

int date_error(int,int,int);

int main(){
	int date[3];
	int date1[3];
	char *dstr[3]={"年","月","日"};
	int i;

	/* 日付の入力 */
	for(i=0;i<3;i++){
		printf("%s: ",dstr[i]); scanf("%d",&date[i]);
		date1[i]=date[i];
	}

	/* エラー処理: 存在しない日付が出たら異常終了する */
	if(date_error(date[0],date[1],date[2])==-1){
		printf("その日付は存在しません。\n"); exit(1);
	}

	printf("==========================\n");

	printf("今日は%d年%d月%d日です。\n",date[0],date[1],date[2]);
	printf("--------------------------\n",date[0],date[1],date[2]);

	tomorrow(&date[0],&date[1],&date[2]);

	printf("次の日は%d年%d月%d日です。\n",date[0],date[1],date[2]);


	yesterday(&date1[0],&date1[1],&date1[2]);

	printf("前の日は%d年%d月%d日です。\n",date1[0],date1[1],date1[2]);

	return 0;
}


void tomorrow(int *y,int *m,int *d){
	(*d)++;
	if(*m==2){
		if(*y%4==0&&*d>29){
			(*m)++;
			*d=1;
		}else if(*d>28){
			(*m)++;
			*d=1;
		}
	}else if(*m==4||*m==6||*m==9||*m==11){
		if(*d>30){
			(*m)++;
			*d=1;
		}
	} else {
		if(*d>31){
			(*m)++;
			*d=1;
		}
		if(*m==13){
			(*y)++;
			*m=1;
		}
	}

}


void yesterday(int *y,int *m,int *d){
	(*d)--;
	if(*d==0){
		(*m)--;
		if(*m==0){
			*m=12;
			(*y)--;
		}
		if(*m==1||*m==3||*m==5||*m==7||*m==8||*m==10||*m==12){
			*d=31;
		} else if(*m==4||*m==6||*m==9||*m==11){
			*d=30;
		} else if((*m==2)&&(*y%4!=0)){
			*d=28;
		} else {
			*d=29;
		}
	}
}

int date_error(int y,int m,int d){

	if(m<1||m>12||d<1){
		return -1;
	}

	if(m==2&&d>28){
		if(y%4==0&&d==29){
			return 0;
		}else{
			return -1;
		}
	} else if(d>30){
		if(d==31&&(m==1||m==3||m==5||m==7||m==8||m==10||m==12)){
			return 0;
		}else{
			return -1;
		}
	} else {
		return 0;
	}
}
