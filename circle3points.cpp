/*
* Circle Through Three Points - https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=126
* ID : 20449074
*/

#include <iostream>
#include <math.h>
#include <iomanip>
#include <string>
#include <sstream>
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
	ostringstream stream;
	
	if(resp.x == 0){
		eq += "x^2 + ";
	} else {
		sign = resp.x > 0 ? "- " : "+ ";
        stream << fixed << setprecision(3) << fabs(resp.x);
		eq += "(x " + sign + stream.str() + ")^2 + ";
		stream.str("");
	}
	if(resp.y == 0){
		eq += "y^2 = ";
	} else {
		sign = resp.y > 0 ? "- " : "+ ";
		stream << fixed << setprecision(3) << fabs(resp.y);
		eq += "(y " + sign + stream.str() + ")^2 = ";
		stream.str("");
	}
	stream << fixed << setprecision(3) << sqrt(dist2(a, resp));
	eq += stream.str() + "^2";
	return eq;
}

string getGenEq(PT a, PT resp){
	ostringstream stream;
	double c, d, e;
	string sign, eq = "x^2 + y^2";
	
	c = 2 * resp.x;
	d = 2 * resp.y;
	e = (resp.x * resp.x) + (resp.y * resp.y) - dist2(a, resp);
	
	//c
	if(c != 0){
		sign = c > 0 ? " - " : " + ";
		stream << fixed << setprecision(3) << fabs(c) << "x";
		eq += sign + stream.str();
		stream.str("");
	}

	//d
	if(d != 0){
		sign = d > 0 ? " - " : " + ";
	    stream << fixed << setprecision(3) << fabs(d) << "y";
		eq += sign + stream.str();
		stream.str("");
	}

	//e
	if(e != 0){
		sign = e > 0 ? " + " : " - ";
    	stream << fixed << setprecision(3) << fabs(e);
		eq += sign + stream.str();
		stream.str("");
	}
	eq += " = 0";
	return eq;
}

int main(int argc, char const *argv[]){
	int n;
	double x1, y1, x2, y2, x3, y3;

	while(scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3) != EOF){
		PT a = PT(x1, y1);
		PT b = PT(x2, y2);
		PT c = PT(x3, y3);
		PT resp = ComputeCircleCenter(a, b, c);
		cout << getHKEq(a, resp) << endl;
		cout << getGenEq(a, resp) << endl;
		cout << endl;
	}
	cin >> n;
	return 0;
}