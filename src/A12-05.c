#include <stdio.h>

typedef struct xyz
{
	int x;
	long y;
	double z;
} XYZ;

void set_xyz(struct xyz*, int, long, double);

int main()
{
	XYZ st;
	XYZ *p=&st;
	int x; long y; double z;

	printf("x = "); scanf("%d",&x);
	printf("y = "); scanf("%d",&y);
	printf("z = "); scanf("%lf",&z);

	set_xyz(p,x,y,z);

	printf("==== 入力した値を表示します ====\n");

	printf("int x = %d\n",p->x);
	printf("long y = %d\n",p->y);
	printf("double z = %lf\n",p->z);

	return 0;
}

void set_xyz(struct xyz *p, int x, long y, double z)
{
	p->x = x;
	p->y = y;
	p->z = z;
}
