#include <stdio.h>
#include <stdlib.h>

typedef struct point {
	int x;
	int y;
} Point;

typedef struct rect {
	Point a;
	Point b;
} Rect;

Point set_point(int,int);
Rect set_rect(Point,Point);

int rect_length(Rect);
int rect_surface(Rect);

int main()
{
	Point a = {1,7};
	Point b = {4,5};
	Rect r;

	r = set_rect(a,b);

	printf("矩形の周囲の長さは%dです。\n",rect_length(r));
	printf("矩形の面積は%dです。",rect_surface(r));

	return 0;
}

Point set_point(int x, int y)
{
	Point p;

	p.x = x;
	p.y = y;

	return p;
}

/*
	矩形をセットする関数
	条件を満たさない場合はエラーとして強制終了する
*/
Rect set_rect(Point a, Point b)
{
	Rect r;

	if(a.x > b.x || b.y > a.y) {
		printf("エラー: 長方形の条件を満たしません\n");
		exit(1);
	} else {
		r.a = a;
		r.b = b;
	}

	return r;
}

/*
	矩形の周囲の長さを求める関数
*/
int rect_length(Rect r)
{
	int vert = r.b.x - r.a.x;
	int side = r.a.y - r.b.y;

	return 2 * (vert + side);
}

/*
	矩形の面積を求める関数
*/
int rect_surface(Rect r)
{
	int vert = r.b.x - r.a.x;
	int side = r.a.y - r.b.y;

	return vert * side;
}