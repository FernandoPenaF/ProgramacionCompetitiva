#include <iostream>
#include <iomanip>
using namespace std;
typedef long double ld;

ld getM(ld x1, ld y1, ld x2, ld y2){
    if(x2 - x1 == 0)
        return 0;
    return (y2 - y1) / (x2 - x1);
}

ld getX(ld x1, ld y1, ld m1, ld x3, ld y3, ld m2){
    return (m1 * x1 - m2 * x3 + y3 - y1) / (m1 - m2);
}

ld getY(ld x, ld x1, ld y1, ld m1){
    return m1 * (x - x1) + y1;
}

bool isOnSameLine(ld x, ld y, ld m, ld x1, ld y1){
    return (y - y1) == m * (x - x1);
}

int main(){
    int n;
    ld x1, y1, x2, y2, x3, y3, x4, y4, m1, m2, x, y, xr;
    
    cin >> n; 
    cout << "INTERSECTING LINES OUTPUT" << endl;
    for (unsigned i = 0; i < n; i++) {
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        x = x2 - x1;
        xr = x4 - x3;
        if((x1 == x3 && y1 == y3) || (x2 == x3 && y2 == y3)){
            x = x3;
            y = y3;
            cout << "POINT " << fixed << setprecision(2) << x << " " << y << endl;
            continue;
        } else if((x1 == x4 && y1 == y4) || (x2 == x4 && y2 == y4)){
            x = x4;
            y = y4;
            cout << "POINT " << fixed << setprecision(2) << x << " " << y << endl;
            continue;
        }
        
        if(x == 0 && xr == 0)
            cout << "LINE" << endl;
        else if(x == 0 || xr == 0){
            if(x == 0){
                x = x1;
                y = y3;
            } else {
                x = x3;
                y = y1;
            }
            cout << "POINT " << fixed << setprecision(2) << x << " " << y << endl;
        }
        else{
            m1 = getM(x1, y1, x2, y2);
            m2 = getM(x3, y3, x4, y4);
            if(m1 == m2){
                if(isOnSameLine(x1, y1, m1, x3, y3) && isOnSameLine(x1, y1, m1, x4, y4))
                    cout << "LINE" << endl;
                else
                    cout << "NONE" << endl;
            }
            else{
                x = getX(x1, y1, m1, x4, y4, m2);
                y = getY(x, x1, y1, m1);
                cout << "POINT " << fixed << setprecision(2) << x << " " << y << endl;
            }
        }
    }
    cout << "END OF OUTPUT" << endl;
    return 0;
}