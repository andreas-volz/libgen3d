#include "../include/libgen3d/MathUtil.h"

using namespace Gen3D;

float Gen3D::wrapPi (float theta)
{
  theta += M_PI;
  theta -= floor (theta / (2.0 * M_PI)) * 2.0 * M_PI;
  theta -= M_PI;

  return theta;
}
