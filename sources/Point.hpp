//
// Created by avida on 5/15/2023.
//
#include <string>
#ifndef COWBOY_VS_NINJA_A_POINT_H
#define COWBOY_VS_NINJA_A_POINT_H
using namespace std;
namespace ariel {

    class Point {
    double x;
    double y;
    public:
        Point(double _x_, double _y_);
        double getX()const;
        double getY()const;
        void setX(double _x_);
        void setY(double _y_);
        Point();
        double distance(const Point& other) const;
         string print()const;
        Point moveTowards(const Point& other, double dist) const;
        static Point moveTowards(const Point &point1, const Point &point2, double dist);

    };

} // ariel

#endif //COWBOY_VS_NINJA_A_POINT_H
