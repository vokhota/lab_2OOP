#include "Triangle.h"

int main() {
    Point A, B, C;
    cout << "Vvedit koordynaty trykutnyka (x y):\n";
    cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y;

    Triangle t(A, B, C);

    cout << "Plosha za Heronom: " << t.areaHeron() << endl;
    cout << "Plosha za vektornym dobutkom: " << t.areaVector() << endl;

    if (t.isDegenerate()) {
        cout << "Trykutnyk vyrodzhenyi (plosha = 0)." << endl;
    }

    Point P;
    cout << "Vvedit koordynaty tochky (x y): ";
    cin >> P.x >> P.y;

    cout << t.pointPosition(P) << endl;

    return 0;
}
