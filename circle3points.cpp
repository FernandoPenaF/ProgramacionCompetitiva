#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

struct PT {
	double x , y;
	PT () {}
	PT ( double x , double y) : x(x) , y( y) {}
	PT ( const PT &p ) : x(p .x) , y(p .y) {}
	PT operator + ( const PT &p ) const { return PT (x+p .x , y+p.y ); }
	PT operator - ( const PT &p ) const { return PT (x -p .x , y -p.y ); }
	PT operator * ( double c) const { return PT (x*c , y *c ); }
	PT operator / ( double c) const { return PT (x/c , y /c ); }
};

double dot ( PT p , PT q) { return p.x *q.x+ p.y* q.y; }
double dist2 ( PT p , PT q) { return dot (p -q ,p - q); }
double cross ( PT p , PT q) { return p.x *q.y - p.y* q.x; }

PT RotateCCW90 ( PT p) { return PT (-p.y ,p.x ); }
PT RotateCW90 ( PT p) { return PT (p.y ,-p.x ); }
PT RotateCCW ( PT p , double t){
	return PT (p.x * cos ( t) -p. y* sin (t) , p.x * sin ( t)+p .y* cos (t)) ;
}

PT ComputeLineIntersection ( PT a , PT b , PT c , PT d) {
	b=b -a; d=c - d; c=c -a ;
	return a + b * cross (c , d)/ cross (b , d);
}
PT ComputeCircleCenter ( PT a , PT b , PT c) {
	b =( a+b) /2;
	c =( a+c) /2;
	return ComputeLineIntersection (b , b+ RotateCW90 (a - b) , c , c+
	RotateCW90 (a - c));
}

int main(int argc, char const *argv[]){
	int n;
	PT a = PT(7, -5);
	PT b = PT(-1, 1);
	PT c = PT(0, -6);
	PT resp = ComputeCircleCenter(a, b, c);
	cout << resp.x << " " << resp.y << endl;
	cout << sqrt(dist2(b, resp)) << endl;
	cout << dist2(a, resp) << endl;
	cin >> n;
	return 0;
}