﻿#include <stdio.h>

struct xyz{
	int x;
	long y;
	double z;
};

int main(){
	struct xyz st;

	st.x = 1;
	st.y = 2;
	st.z = 3.0;

	printf("int x = %d\n",st.x);
	printf("long y = %d\n",st.y);
	printf("double z = %lf\n",st.z);

	return 0;
}
