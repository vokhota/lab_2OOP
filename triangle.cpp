#include "Triangle.h"

Triangle::Triangle(Point a, Point b, Point c) {
    A = a; B = b; C = c;
}

double Triangle::sideLength(const Point &p1, const Point &p2) const {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

double Triangle::areaHeron() const {
    double a = sideLength(A, B);
    double b = sideLength(B, C);
    double c = sideLength(C, A);
    double p = (a + b + c) / 2.0;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

double Triangle::areaVector() const {
    return fabs((A.x*(B.y - C.y) + B.x*(C.y - A.y) + C.x*(A.y - B.y)) / 2.0);
}

bool Triangle::isDegenerate() const {
    return areaVector() < 1e-9;
}

string Triangle::pointPosition(const Point &P) const {
    double S = areaVector();

    if ((fabs(P.x - A.x) < 1e-9 && fabs(P.y - A.y) < 1e-9) ||
        (fabs(P.x - B.x) < 1e-9 && fabs(P.y - B.y) < 1e-9) ||
        (fabs(P.x - C.x) < 1e-9 && fabs(P.y - C.y) < 1e-9)) {
        return "Tochka na vershyni trykutnyka";
    }

    if (isDegenerate()) {
        return "Tochka poza trykutnykom (trykutnyk vyrodzhenyi)";
    }

    double S1 = fabs((P.x*(B.y - C.y) + B.x*(C.y - P.y) + C.x*(P.y - B.y)) / 2.0);
    double S2 = fabs((A.x*(P.y - C.y) + P.x*(C.y - A.y) + C.x*(A.y - P.y)) / 2.0);
    double S3 = fabs((A.x*(B.y - P.y) + B.x*(P.y - A.y) + P.x*(A.y - B.y)) / 2.0);

    double sum = S1 + S2 + S3;

    if (fabs(S - sum) < 1e-9) {
        if (S1 < 1e-9 || S2 < 1e-9 || S3 < 1e-9)
            return "Tochka na mezhi trykutnyka";
        else
            return "Tochka vseredyni trykutnyka";
    } else {
        return "Tochka poza trykutnykom";
    }
}
