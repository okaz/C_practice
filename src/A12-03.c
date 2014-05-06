#include <stdio.h>

struct xyz
{
	int x;
	long y;
	double z;
};

int main()
{
	struct xyz st={1,2,3.0};
	struct xyz *pt=&st;

	printf("int x = %d\n",pt->x);
	printf("long y = %d\n",pt->y);
	printf("double z = %lf\n",pt->z);

	return 0;
}
