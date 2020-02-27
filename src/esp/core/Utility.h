#include <Magnum/Magnum.h>
#include <Magnum/Math/Quaternion.h>
#include <Magnum/Math/Vector3.h>
#include <cmath>
#include <cstdlib>

namespace esp {
namespace core {
Magnum::Quaternion randomRotation() {
  // generate random rotation using:
  // http://planning.cs.uiuc.edu/node198.html
  double u1 = (rand() % 1000) / 1000.0;
  double u2 = (rand() % 1000) / 1000.0;
  double u3 = (rand() % 1000) / 1000.0;

  Magnum::Vector3 qAxis(sqrt(1 - u1) * cos(2 * M_PI * u2),
                        sqrt(u1) * sin(2 * M_PI * u3),
                        sqrt(u1) * cos(2 * M_PI * u3));

  return Magnum::Quaternion(qAxis, sqrt(1 - u1) * sin(2 * M_PI * u2));
}
}  // namespace core
}  // namespace esp
