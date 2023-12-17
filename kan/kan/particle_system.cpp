#include "kan/particle_system.h"

namespace kan::ps {
void move(particle &p, const std::chrono::milliseconds delta_t) {
  p.position += (p.velocity * delta_t.count());
  p.velocity += (p.acceleration * delta_t.count());
}

namespace {
void move_existing_particles(system &ps,
                             const std::chrono::milliseconds delta_t) {
  for (auto &p : ps.particles) {
    move(p, delta_t);
  }
}
} // namespace

void update(system &particle_system, const time_point now) {
  const auto elapsed_time{std::chrono::duration_cast<std::chrono::milliseconds>(
      now - particle_system.last_update_time)};
  using namespace std::chrono_literals;
  if (elapsed_time == 0ms) {
    return;
  }
}
} // namespace kan::ps