#include <iostream>

int64_t WaysToGetRegularPoints(int64_t p) {
   int64_t ways = 0;
   for(int i=0; 3*i <= p;++i) {
     // Remaining points to be decided after we got i tripple-points
     int64_t remaining = p - 3*i; 
     // Zero (always possible to get zero double-points) OR a positive number of double-points
     int64_t ways_double_points = 1 + (remaining/2); 
     // Number of ways to get double-points given that we got i tripple-points (single-points are uniquely defined afterwards).
     ways += ways_double_points; 
   }
   return ways;
}

int64_t Solve(int64_t p1, int64_t p2) {
  p1/=10;
  p2/=10;
  // 1. No team catches the golden snitch.
  int64_t sol = WaysToGetRegularPoints(p1) * WaysToGetRegularPoints(p2);
  // 2. Team 1 catches the golden snitch.
  sol += WaysToGetRegularPoints(p1 - 15) * WaysToGetRegularPoints(p2);
  // 3. Team 2 catches the golden snitch.
  sol += WaysToGetRegularPoints(p1) * WaysToGetRegularPoints(p2 - 15);
  return sol;
}

int main() {
  int64_t p1, p2;
  std::cin >> p1 >> p2;
  std::cout << Solve(p1, p2) << std::endl;
  return 0;
}

