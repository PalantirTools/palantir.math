
// EXTERNAL INCLUDES
#include <math.h>
// INTERNAL INCLUDES
#include "palantirmath.h"

// ************************************************************************************************
inline float clamp(float value, float min, float max)
{
	return min * (value < min) +
		max * (value > max) +
		value * (value >= min && value <= max);
}
// ************************************************************************************************
inline float lerp(float a, float b, float t)
{
	return a + (b - a) * t;
}
// ************************************************************************************************
inline float in_out_sine(const float t)
{
	return -0.5f * (cos(PI * t) - 1.0f);
}
// ************************************************************************************************
inline float in_out_sigmoid(float x) {
	return 3.0f * x * x - 2.0f * x * x * x;
}
// ************************************************************************************************
inline float in_expo(float x)
{
	return x == 0.0f ? 0.0f : pow(2.0f, 10.0f * x - 10.0f);
}
// ************************************************************************************************