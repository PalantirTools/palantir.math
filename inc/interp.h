#ifndef INTERP_H
#define INTERP_H

// EXTERNAL INCLUDES
// INTERNAL INCLUDES
#include "basetypes.h"

typedef enum
{
	SDK_CURVE_STEP,
	SDK_CURVE_LINEAR,
	SDK_CURVE_SMOOTHSTEP,
	SDK_CURVE_SMOOTHERSTEP,
	SDK_CURVE_EXPONENTIAL,
	SDK_CURVE_OUT_BOUNCE,
	SDK_CURVE_IN_BOUNCE,
	SDK_CURVE_INOUT_BOUNCE,
	SDK_CURVE_COUNT
} curve_t;

typedef struct interpolator_t* interpolator_t;

/**
* @brief Solve the interpolator for the current value based on the target and curve.
* @param[in] curve The curve type to use for interpolation.
* @param[in] current The current value of the interpolator.
* @param[out] interp The interpolator to solve.
* @return true if the interpolator was created successfully, false otherwise.
*/
extern bool interpolator_create(curve_t curve, f32 initial_value, f32 time_factor, interpolator_t* interp);

/**
* @brief Destroy the interpolator and free its memory.
* @param[in] interp The interpolator to destroy.
*/
extern void interpolator_destroy(interpolator_t* interp);

/**
* @brief Given an interpolator this function returns the interpolated value
* @param[in] interp is the interpolator to be applied
* @return the interpolated value
*/
extern f32 interpolator_solve(interpolator_t interp);

/**
* @brief Given an interpolator this function updates the interpolator's state based on the delta time
* @param[in] interp is the interpolator to be updated
* @param[in] delta_time is the time elapsed since the last update
*/
extern void interpolator_update(interpolator_t interp, f32 delta_time);

/**
* @brief Given an interpolator this function sets the target value for the interpolation
* @param[in] interp is the interpolator to be updated
* @param[in] target is the new target value for the interpolation
*/
extern void interpolator_target_set(interpolator_t interp, f32 target);

#endif // INTERP_H
