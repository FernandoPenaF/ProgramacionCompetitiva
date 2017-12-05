#include <iostream>
#include <math.h>
#include <iomanip>
#include <string>
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

string getHKEq(PT a, PT resp){
	string sign, eq = "";
	cout << resp.x;
	if(resp.x == 0){
		eq += "x^2 + ";
	} else {
		sign = resp.x > 0 ? "- " : "+ ";
		eq += "(x " + sign + to_string(fabs(resp.x)) + ")^2 + ";
	}
	if(resp.y == 0){
		eq += "y^2 = ";
	} else {
		sign = resp.y > 0 ? "- " : "+ ";
		eq += "(y " + sign + to_string(fabs(resp.y)) + ")^2 = ";
	}
	eq += to_string(sqrt(dist2(a, resp)));
	return eq;
}

int main(int argc, char const *argv[]){
	double x1, y1, x2, y2, x3, y3;
	PT a, b, c, r;
	int n = 1;
	while(n == 1){
		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
		PT a = PT(x1, y1);
		PT b = PT(x1, y1);
		PT c = PT(x1, y1);
		PT resp = ComputeCircleCenter(a, b, c);
		cout << a.x << endl;
        cout << getHKEq(a, resp) << endl;
        n++;
	}
	return 0;
}