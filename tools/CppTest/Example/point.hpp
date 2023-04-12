#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>

class Point {
 public:
  Point() = default;
  Point(std::istream &is);
  Point(double x, double y);

  double dist(const Point &other);

  void sum(const Point &other);

  friend std::istream &operator>>(std::istream &is, Point &p);
  friend std::ostream &operator<<(std::ostream &os, Point &p);

  friend bool operator==(const Point& one, const Point& two){
    return (abs(one.x- two.x) < __DBL_EPSILON__) && (abs(one.y - two.y) < __DBL_EPSILON__);
  }

 private:
  double x = 0.0;
  double y = 0.0;
};

#endif // POINT_HPP
