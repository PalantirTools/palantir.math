#ifndef PALANTIRMATH_H
#define PALANTIRMATH_H

// EXTERNAL INCLUDES
#include <math.h>
// INTERNAL INCLUDES
#include "basetypes.h"

#define PI						3.14159265358979323846f /**< The number PI as a real value */
#define TWO_PI					6.28318530717958647692f /**< The number 2*PI as a real value */
#define HALF_PI					1.57079632679489661923f /**< The number PI/2 as a real value */
#define QUARTER_PI				0.78539816339744830961f /**< The number PI/4 as a real value */

#define EPSILON					1.0e-6f /**< A very small value used to prevent floating point rounding errors */

#define GOLDEN_RATIO			1.61803398874989484820f /**< The golden ratio as a real value */
#define GOLDEN_RATIO_CONJUGATE	0.61803398874989484820f /**< The conjugate of the golden ratio as a real value */

#define E						2.71828182845904523536f /**< The number e as a real value */

#define DEG_TO_RAD(degrees)		degrees * PI / 180.0f /**< Macro to convert degrees to radians */
#define RAD_TO_DEG(radians)		radians * 180.0f / PI /**< Macro to convert radians to degrees */

/**
 * @brief Clamps a value between a minimum and maximum value.
 * @param[in] value The value to clamp.
 * @param[in] min The minimum value.
 * @param[in] max The maximum value.
 * @return The clamped value.
 */
float clamp(float value, float min, float max);

/**
 * @brief Linearly interpolates between two values.
 * @param[in] a The first value.
 * @param[in] b The second value.
 * @param[in] t The interpolation factor.
 * @return The interpolated value.
 */
float lerp(float a, float b, float t);

/**
 * @brief Applies the in-out sine easing function to a value.
 * @param[in] t The value to apply the easing function to.
 * @return The eased value.
 */
float in_out_sine(const float t);

/**
 * @brief Applies the in-out sigmoid easing function to a value.
 * @param[in] t The value to apply the easing function to.
 * @return The eased value.
 */
float in_out_sigmoid(float x);

/**
 * @brief Applies the in-exponential easing function to a value.
 * @param[in] t The value to apply the easing function to.
 * @return The eased value.
 */
float in_expo(float x);

#endif // PALANTIRMATH_H