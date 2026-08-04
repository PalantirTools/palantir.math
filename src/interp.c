// EXTERNAL INCLUDES
#include <stdlib.h>
// INTERNAL INCLUDES
#include "logging.h"
#include "interp.h"
#include "palantirmath.h"

// ************************************************************************************************
typedef struct interpolator_t
{
	f32 current;

	f32 start;
	f32 target;

	f32 t;
	f32 f;

	curve_t curve;
} _internal_interpolator_t;
// ************************************************************************************************
bool interpolator_create(curve_t curve, f32 initial_value, f32 time_factor, interpolator_t* interp)
{
	if (!interp) return false;

	_internal_interpolator_t* internal_interp = (_internal_interpolator_t*)malloc(
		sizeof(_internal_interpolator_t)
	);

	if (!internal_interp)
		return false;

	internal_interp->current = initial_value;
	internal_interp->target = initial_value;
	internal_interp->start = initial_value;
	internal_interp->t = 0.0f;
	internal_interp->f = time_factor;
	internal_interp->curve = curve;

	*interp = (interpolator_t)internal_interp;

	return true;
}
// ************************************************************************************************
void interpolator_destroy(interpolator_t* interp)
{
	if (!interp || !*interp) return;
	_internal_interpolator_t* internal_interp = (_internal_interpolator_t*)*interp;
	free(internal_interp);
	*interp = NULL;
}
// ************************************************************************************************
f32 interpolator_solve(interpolator_t interp)
{
	_internal_interpolator_t* internal_interp = (_internal_interpolator_t*)interp;

	if (!internal_interp) return NAN;

	PA_LOG_DBUG("interpolator_solve: current=%f, target=%f, t=%f, f=%f, curve=%d",
		internal_interp->current,
		internal_interp->target,
		internal_interp->t,
		internal_interp->f,
		internal_interp->curve
	);

	switch (internal_interp->curve)
	{
		case SDK_CURVE_STEP: return lerp(internal_interp->start, internal_interp->target, step(internal_interp->t));
		case SDK_CURVE_LINEAR: return lerp(internal_interp->start, internal_interp->target, internal_interp->t);
		case SDK_CURVE_SMOOTHSTEP: return lerp(internal_interp->start, internal_interp->target, in_out_sigmoid(internal_interp->t));
		case SDK_CURVE_SMOOTHERSTEP: return lerp(internal_interp->start, internal_interp->target, in_out_sigmoid_smoother(internal_interp->t));
		case SDK_CURVE_EXPONENTIAL: return lerp(internal_interp->start, internal_interp->target, in_expo(internal_interp->t));
		case SDK_CURVE_OUT_BOUNCE: return lerp(internal_interp->start, internal_interp->target, out_bounce(internal_interp->t));
		case SDK_CURVE_IN_BOUNCE: return lerp(internal_interp->start, internal_interp->target, in_bounce(internal_interp->t));
		case SDK_CURVE_INOUT_BOUNCE: return lerp(internal_interp->start, internal_interp->target, inout_bounce(internal_interp->t));
		default: return NAN;
	}
}
// ************************************************************************************************
void interpolator_update(interpolator_t interp, f32 delta_time)
{
	_internal_interpolator_t* internal_interp = (_internal_interpolator_t*)interp;

	if (!internal_interp) return;

	internal_interp->t += (delta_time * internal_interp->f);
	internal_interp->t = clamp(internal_interp->t, 0.0f, 1.0f);

	internal_interp->current = interpolator_solve(
		(interpolator_t)internal_interp
	);
}
// ************************************************************************************************
extern void interpolator_target_set(interpolator_t interp, f32 target)
{
	_internal_interpolator_t* internal_interp = (_internal_interpolator_t*)interp;

	if (!internal_interp) return;

	internal_interp->start = internal_interp->current;
	internal_interp->target = target;
	internal_interp->t = 0.0f;
}
// ************************************************************************************************