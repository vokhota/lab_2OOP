#include "Triangle.h"

int main() {
    Point A, B, C;
    cout << "Vvedit koordynaty trykutnyka (x y):\n";
    cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y;

    Triangle t(A, B, C);

    double heron = t.areaHeron();
    double vector = t.areaVector();

    cout << "Plosha za Heronom: " << heron << endl;
    cout << "Plosha za vektornym dobutkom: " << vector << endl;

    if (t.isDegenerate()) {
        cout << "Trykutnyk vyrodzhenyi (plosha = 0)." << endl;
    }

    Point P;
    cout << "Vvedit koordynaty tochky (x y): ";
    cin >> P.x >> P.y;

    cout << t.pointPosition(P) << endl;

    return 0;
}
