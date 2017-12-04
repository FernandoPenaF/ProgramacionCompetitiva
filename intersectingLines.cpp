#include <iostream>
#include <iomanip>
using namespace std;

float getM(float x1, float y1, float x2, float y2){
    return (y2 - y1) / (x2 - x1);
}

float getX(float x1, float y1, float m1, float x3, float y3, float m2){
    return (m1 * x1 - m2 * x3 + y3 - y1) / (m1 - m2);
}

float getY(float x, float x1, float y1, float m1){
    return m1 * (x - x1) + y1;
}

int main(){
    float x1, y1, x2, y2, x3, y3, x4, y4, m1, m2;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    
    m1 = getM(x1, y1, x2, y2);
    m2 = getM(x3, y3, x4, y4);
    cout << "m1 = " << m1 << " m2 = " << m2 << endl;
    if(m1 == m2){
        cout << "NONE" << endl;
    }
    else{
        float x = getX(x1, y1, m1, x4, y4, m2);
        float y = getY(x, x1, y1, m1);
        cout << "POINT " << fixed << setprecision(2) << x << " " << y << endl;
    }
    return 0;
}