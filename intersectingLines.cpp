#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

const double EPS = 1e-9;

struct PT{
    double x, y;
    PT() {}
    PT(double x, double y) : x(x), y(y) {}
    PT(const PT &p) : x(p.x), y(p.y) {}
    PT operator + (const PT &p) const { return PT(x + p.x, y + p.y); }
    PT operator - ( const PT &p ) const { return PT (x -p .x , y -p.y ); }
    PT operator * ( double c) const { return PT (x*c , y *c ); }
    PT operator / ( double c) const { return PT (x/c , y /c ); }
};

double dot(PT p, PT q) { return p.x * q.x + p.y + q.y; }
double dist2 ( PT p , PT q) { return dot (p -q ,p - q); }
double cross ( PT p , PT q) { return p.x *q.y - p.y* q.x; }

bool LinesParallel ( PT a , PT b , PT c , PT d) {
    return fabs ( cross (b -a , c -d) ) < EPS ;
}

bool LinesCollinear ( PT a , PT b , PT c , PT d) {
    return LinesParallel (a , b , c , d)
        && fabs ( cross (a -b , a -c) ) < EPS
        && fabs ( cross (c -d , c -a) ) < EPS ;
}

bool segmentLineIntersection ( PT a , PT b , PT c , PT d){
    return cross (d -c , a - c)* cross (d -c , b -c) < EPS ;
}

PT ComputeLineIntersection ( PT a , PT b , PT c , PT d) {
    b=b -a; d=c - d; c=c -a ;
    return a + b * cross (c , d)/ cross (b , d);
}

int main(){
    int n;
    double x1, y1, x2, y2, x3, y3, x4, y4;
    PT a, b, c, d, resp;

    cin >> n;
    cout << "INTERSECTING LINES OUTPUT" << endl;
    for(unsigned i = 0; i < n; i++) {
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        a = PT(x1, y1);
        b = PT(x2, y2);
        c = PT(x3, y3);
        d = PT(x4, y4);

        if(LinesCollinear(a, b, c, d))
            cout << "LINE" << endl;
        else if(LinesParallel(a, b, c, d))
            cout << "NONE" << endl;
        else{
            resp = ComputeLineIntersection(a, b, c, d);
            cout << "POINT "<< fixed << setprecision(2) << resp.x << " " << resp.y << endl;
        }
    }
    cout << "END OF OUTPUT" << endl;
    return 0;
}