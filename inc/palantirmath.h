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
extern f32 clamp(f32 value, f32 min, f32 max);

/**
 * @brief Performs the step function on a value t.
 * @param[in] value The time value.
 * @return Eiterh 0.0 if t >= 0.5, 1.0 otherwise
 */
extern f32 step(const f32 t);

/**
 * @brief Linearly interpolates between two values.
 * @param[in] a The first value.
 * @param[in] b The second value.
 * @param[in] t The interpolation factor.
 * @return The interpolated value.
 */
extern f32 lerp(f32 a, f32 b, f32 t);

/**
 * @brief Applies the in-out sine easing function to a value.
 * @param[in] t The value to apply the easing function to.
 * @return The eased value.
 */
extern f32 in_out_sine(const f32 t);

/**
 * @brief Applies the in-out sigmoid easing function to a value.
 * @param[in] t The value to apply the easing function to.
 * @return The eased value.
 */
extern f32 in_out_sigmoid(f32 x);

/**
 * @brief Applies the in-out sigmoid easing function to a value even smoother than the default sigmoid.
 * @param[in] t The value to apply the easing function to.
 * @return The eased value.
 */
extern f32 in_out_sigmoid_smoother(f32 x);

/**
 * @brief Applies the in-exponential easing function to a value.
 * @param[in] t The value to apply the easing function to.
 * @return The eased value.
 */
extern f32 in_expo(f32 x);

/**
* @brief Applies the out-bounce easing function to a value.
* @param[in] t The value to apply the easing function to.
* @return The eased value.
*/
extern f32 out_bounce(f32 x);

/**
 * @brief Applies the in-bounce easing function to a value.
 * @param[in] t The value to apply the easing function to.
 * @return The eased value.
 */
extern f32 in_bounce(f32 x);

/**
* @brief Applies the in-out-bounce easing function to a value.
* @param[in] t The value to apply the easing function to.
* @return The eased value.
*/
extern f32 inout_bounce(f32 x);

#endif // PALANTIRMATH_H