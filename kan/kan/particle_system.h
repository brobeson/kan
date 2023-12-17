#ifndef KAN_PARTICLE_SYSTEM_H
#define KAN_PARTICLE_SYSTEM_H

#include <chrono>
#include <vector>

namespace kan {
struct point {
  int x, y, z;
};
struct vector {
  int i, j, k;
};

constexpr auto operator+=(point &p, const vector &v) {
  p.x += v.i;
  p.y += v.j;
  p.z += v.k;
  return p;
}

constexpr auto operator+=(vector &v, const vector &w) {
  v.i += w.i;
  v.j += w.j;
  v.k += w.k;
  return v;
}

[[nodiscard]] constexpr auto operator*(const vector &v, const int s) {
  return vector{v.i * s, v.j * s, v.k * s};
}

namespace ps {
struct particle {
  point position;
  vector velocity;
  vector acceleration;
};

void move(particle &p, const std::chrono::milliseconds delta_t);

struct emitter {
  point p;
};

using time_point = std::chrono::system_clock::time_point;
struct system {
  emitter e;
  std::vector<particle> particles;
  time_point last_update_time;
};

void update(system &particle_system, time_point now);
inline void update(system &particle_system) {
  update(particle_system, std::chrono::system_clock::now());
}
} // namespace ps
} // namespace kan

#endif