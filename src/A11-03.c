#include<stdio.h>

#include<string.h>

void put_string(const char*);

int main(){
	char *str="C Programming Language";

	put_string(str);

	return 0;
}

void put_string(const char str[]){
	int i=0;

	while(*(str+i)!='\0'){
		putchar(*(str+i));
		i++;
	}

}