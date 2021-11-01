// novos computadores - uri 1982

#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

struct Point {
  double x;
  double y;
  bool operator<(const Point &p) const { return (x < p.x && y < p.y); }
};

double distance(const Point &p0, const Point &p1) {
  double dx = abs(p1.x - p0.x);
  double dy = abs(p1.y - p0.y);
  return sqrt(dx * dx + dy * dy);
}

Point extrem;

bool compare(const Point &p1, const Point &p2) {
  double dx1 = p1.x - extrem.x, dx2 = p2.x - extrem.x;
  double dy1 = p1.y - extrem.y, dy2 = p2.y - extrem.y;

  if (dx1 == 0)
    return dy1 == 0 || (dx2 == 0 && dy1 < dy2);

  if (dx2 == 0)
    return dy2 != 0;

  if (dy1 * dx2 == dy2 * dx1)
    return dx1 < dx2;

  if (dx1 * dx2 < 0)
    return dy1 * dx2 > dy2 * dx1;

  return dy1 * dx2 < dy2 * dx1;
}

bool left(const Point &p1, const Point &p2, const Point &p3) {
  return ((p1.x - p3.x) * (p2.y - p3.y) - (p2.x - p3.x) * (p1.y - p3.y)) > 0;
}

std::vector<Point> convex(std::vector<Point> &points) {
  extrem = points[0];
  for (int i = 1; i < (int)points.size(); i++) {
    if (points[i].x < extrem.x ||
        (points[i].x == extrem.x && points[i].y < extrem.y))
      extrem = points[i];
  }

  std::sort(points.begin(), points.end(), compare);
  std::vector<Point> wrap;
  wrap.push_back(points[0]);
  int n = 1;
  for (int i = 1; i < (int)points.size(); i++) {
    while (n > 1 && !left(wrap[n - 2], wrap[n - 1], points[i])) {
      n--;
      wrap.pop_back();
    }
    wrap.push_back(points[i]);
    n++;
  }

  return wrap;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  int num_points;

  while (std::cin >> num_points) {
    if (num_points == 0)
      break;

    std::vector<Point> points(num_points);
    for (int i = 0; i < num_points; i++) {
      std::cin >> points[i].x >> points[i].y;
    }

    std::vector<Point> polygon = convex(points);

    double dist = 0;
    for (int i = 0; i < polygon.size() - 1; i++) {
      dist += distance(polygon[i], polygon[i + 1]);
    }
    dist += distance(polygon[polygon.size() - 1], polygon[0]);

    std::cout << std::fixed << std::setprecision(2) << "Tera que comprar uma fita de tamanho " << dist << ".\n";
  }

  return 0;
}
