// EXTERNAL INCLUDES
#include <math.h>
// INTERNAL INCLUDES
#include "float3.h"
#include "float4.h"

// ************************************************************************************************
float4_t float4_create(const f32 x, const f32 y, const f32 z, const f32 w)
{
	float4_t result;
	result.x = x;
	result.y = y;
	result.z = z;
	result.w = w;
	return result;
}
// ************************************************************************************************
float4_t float4_add(const float4_t a, const float4_t b)
{
	float4_t result;
	result.x = a.x + b.x;
	result.y = a.y + b.y;
	result.z = a.z + b.z;
	result.w = a.w + b.w;
	return result;
}
// ************************************************************************************************
float4_t float4_sub(const float4_t a, const float4_t b)
{
	float4_t result;
	result.x = a.x - b.x;
	result.y = a.y - b.y;
	result.z = a.z - b.z;
	result.w = a.w - b.w;
	return result;
}
// ************************************************************************************************
float4_t float4_mul(const float4_t a, const float4_t b)
{
	float4_t result;
	result.x = a.x * b.x;
	result.y = a.y * b.y;
	result.z = a.z * b.z;
	result.w = a.w * b.w;
	return result;
}
// ************************************************************************************************
float4_t float4_div(const float4_t a, const float4_t b)
{
	float4_t result;
	result.x = a.x / b.x;
	result.y = a.y / b.y;
	result.z = a.z / b.z;
	result.w = a.w / b.w;
	return result;
}
// ************************************************************************************************
float4_t float4_mul_scalar(const float4_t a, const f32 scalar)
{
	float4_t result;
	result.x = a.x * scalar;
	result.y = a.y * scalar;
	result.z = a.z * scalar;
	result.w = a.w * scalar;
	return result;
}
// ************************************************************************************************
float4_t float4_div_scalar(const float4_t a, const f32 scalar)
{
	float4_t result;
	result.x = a.x / scalar;
	result.y = a.y / scalar;
	result.z = a.z / scalar;
	result.w = a.w / scalar;
	return result;
}
// ************************************************************************************************
float4_t float4_mul_float4(const float4_t a, const float4_t b)
{
	float4_t result;
	result.w = a.w * b.w - a.x * b.x - a.y * b.y - a.z * b.z;
	result.x = a.w * b.x + a.x * b.w + a.y * b.z - a.z * b.y;
	result.y = a.w * b.y - a.x * b.z + a.y * b.w + a.z * b.x;
	result.z = a.w * b.z + a.x * b.y - a.y * b.x + a.z * b.w;
	return result;
}
// ************************************************************************************************
float4_t float4_conjugate(const float4_t q)
{
	float4_t result;
	result.w = q.w;
	result.x = -q.x;
	result.y = -q.y;
	result.z = -q.z;
	return result;
}
// ************************************************************************************************
float3_t float4_rotate_float3(const float3_t v, const float4_t q)
{
	float3_t u = float3_create(q.x, q.y, q.z);

	float s = q.w;

	float3_t cross1 = float3_cross(u, v);
	float3_t cross2 = float3_cross(u, cross1);

	return float3_create(
		v.x + 2.0f * (s * cross1.x + cross2.x),
		v.y + 2.0f * (s * cross1.y + cross2.y),
		v.z + 2.0f * (s * cross1.z + cross2.z)
	);
}
// ************************************************************************************************
f32 float4_magnitude(const float4_t q)
{
	return sqrtf(
		q.x * q.x +
		q.y * q.y +
		q.z * q.z +
		q.w * q.w
	);
}
// ************************************************************************************************
void float4_to_angle_axis(
	const float4_t q,
	f32* angle,
	float3_t* axis
)
{
	if (NULL == angle || NULL == axis)
	{
		return;
	}

	f32 sqr_length = q.x * q.x + q.y * q.y + q.z * q.z;
	if (sqr_length > 0.0f)
	{
		*angle = 2.0f * acosf(q.w);
		f32 inv_length = 1.0f / sqrtf(sqr_length);
		axis->x = q.x * inv_length;
		axis->y = q.y * inv_length;
		axis->z = q.z * inv_length;
	}
	else
	{
		*angle = 0.0f;
		axis->x = 0.0f;
		axis->y = 0.0f;
		axis->z = 1.0f;
	}
}
// ************************************************************************************************
float4_t float4_from_angle_axis(
	const f32 angle,
	const float3_t axis
)
{
	float4_t result;
	f32 half_angle = angle * 0.5f;
	f32 sin_half_angle = sinf(half_angle);
	result.x = axis.x * sin_half_angle;
	result.y = axis.y * sin_half_angle;
	result.z = axis.z * sin_half_angle;
	result.w = cosf(half_angle);
	return result;
}
// ************************************************************************************************
float4_t float4_negate(
	const float4_t q
)
{
	float4_t result;
	result.x = -q.x;
	result.y = -q.y;
	result.z = -q.z;
	result.w = -q.w;
	return result;
}
// ************************************************************************************************
float3_t float4_get_float3(
	const float4_t q
)
{
	float3_t result;
	result.x = q.x;
	result.y = q.y;
	result.z = q.z;
	return result;
}
// ************************************************************************************************
void float4_normalize(
	float4_t* q
)
{
	f32 mag = float4_magnitude(*q);
	if (mag > 0.0f)
	{
		f32 inv_mag = 1.0f / mag;
		q->x *= inv_mag;
		q->y *= inv_mag;
		q->z *= inv_mag;
		q->w *= inv_mag;
	}
}
// ************************************************************************************************
float4_t float4_lerp(
	float4_t* a,
	float4_t* b,
	f32 t
)
{
	float4_t result;

	if (!a || !b)
	{
		result.x = 0.0f;
		result.y = 0.0f;
		result.z = 0.0f;
		result.w = 0.0f;
		return result;
	}

	result.x = a->x + (b->x - a->x) * t;
	result.y = a->y + (b->y - a->y) * t;
	result.z = a->z + (b->z - a->z) * t;
	result.w = a->w + (b->w - a->w) * t;

	return result;
}
// ************************************************************************************************
float4_t float4_zero = { 0.0f, 0.0f, 0.0f, 0.0f };
float4_t float4_unitx = { 1.0f, 0.0f, 0.0f, 0.0f };
float4_t float4_unity = { 0.0f, 1.0f, 0.0f, 0.0f };
float4_t float4_unitz = { 0.0f, 0.0f, 1.0f, 0.0f };
float4_t float4_unitw = { 0.0f, 0.0f, 0.0f, 1.0f };
float4_t float4_unitscale = { 1.0f, 1.0f, 1.0f, 1.0f };
// ************************************************************************************************
