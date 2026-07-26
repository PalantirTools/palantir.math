// EXTERNAL INCLUDES
#include <math.h>
// INTERNAL INCLUDES
#include "float4x4.h"

// ************************************************************************************************
float4x4_t float4x4_create(
	float m00, float m01, float m02, float m03,
	float m10, float m11, float m12, float m13,
	float m20, float m21, float m22, float m23,
	float m30, float m31, float m32, float m33
)
{
	float4x4_t result;
	result.m[0][0] = m00; result.m[0][1] = m01; result.m[0][2] = m02; result.m[0][3] = m03;
	result.m[1][0] = m10; result.m[1][1] = m11; result.m[1][2] = m12; result.m[1][3] = m13;
	result.m[2][0] = m20; result.m[2][1] = m21; result.m[2][2] = m22; result.m[2][3] = m23;
	result.m[3][0] = m30; result.m[3][1] = m31; result.m[3][2] = m32; result.m[3][3] = m33;
	return result;
}
// ************************************************************************************************
float4x4_t float4x4_create_rows(
	float4_t row0,
	float4_t row1,
	float4_t row2,
	float4_t row3
)
{
	float4x4_t result;
	result.rows[0] = row0;
	result.rows[1] = row1;
	result.rows[2] = row2;
	result.rows[3] = row3;
	return result;
}
// ************************************************************************************************
float4_t float4x4_get_translation(
	const float4x4_t* matrix
)
{
	return matrix->location;
}
// ************************************************************************************************
float4x4_t current_rotation = {
	1, 0, 0, 0,
	0, 1, 0, 0,
	0, 0, 1, 0,
	0, 0, 0, 1
};
// ************************************************************************************************
void float4x4_rotate(
	float4x4_t* matrix,
	const float3_t axis,
	float angle
)
{
	float4_t translation = matrix->location;

	float cos_angle = cos(angle);
	float sin_angle = sin(angle);

	float one_minus_cos_angle = 1.0f - cos_angle;

	float4x4_t rotation = float4x4_create(
		cos_angle + axis.x * axis.x * (one_minus_cos_angle),
		axis.x * axis.y * (one_minus_cos_angle) - axis.z * sin_angle,
		axis.x * axis.z * (one_minus_cos_angle) + axis.y * sin_angle,
		0.0f,
		axis.y * axis.x * (one_minus_cos_angle) + axis.z * sin_angle,
		cos_angle + axis.y * axis.y * (one_minus_cos_angle),
		axis.y * axis.z * (one_minus_cos_angle) - axis.x * sin_angle,
		0.0f,
		axis.z * axis.x * (one_minus_cos_angle) - axis.y * sin_angle,
		axis.z * axis.y * (one_minus_cos_angle) + axis.x * sin_angle,
		cos_angle + axis.z * axis.z * (one_minus_cos_angle),
		0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	);

	if (angle == 0.0f) {
		return;
	}

	*matrix = current_rotation = float4x4_mul(&current_rotation, &rotation);
	matrix->location = translation;
}
// ************************************************************************************************
float4x4_t float4x4_mul(
	const float4x4_t* a,
	const float4x4_t* b
)
{
	float4x4_t result;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			result.m[i][j] = a->m[i][0] * b->m[0][j] +
				a->m[i][1] * b->m[1][j] +
				a->m[i][2] * b->m[2][j] +
				a->m[i][3] * b->m[3][j];
		}
	}
	return result;
}
// ************************************************************************************************
float3_t float4x4_mul_float3(
	const float4x4_t* a,
	const float3_t vec
)
{
	float x = vec.x;
	float y = vec.y;
	float z = vec.z;

	float3_t result;

	result.x = a->m[0][0] * x + a->m[0][1] * y + a->m[0][2] * z + a->m[0][3] * 1.0f;
	result.y = a->m[1][0] * x + a->m[1][1] * y + a->m[1][2] * z + a->m[1][3] * 1.0f;
	result.z = a->m[2][0] * x + a->m[2][1] * y + a->m[2][2] * z + a->m[2][3] * 1.0f;

	return result;
}
// ************************************************************************************************
void float4x4_normalize(
	float4x4_t* matrix
)
{
	float4_normalize(&matrix->right);
	float4_normalize(&matrix->up);
	float4_normalize(&matrix->forward);
}
// ************************************************************************************************
float4x4_t float4x4_from_quaternion(
	const float4_t q
)
{
	float4x4_t result;
	float x = q.x;
	float y = q.y;
	float z = q.z;
	float w = q.w;
	float x2 = x + x;
	float y2 = y + y;
	float z2 = z + z;
	float xx = x * x2;
	float xy = x * y2;
	float xz = x * z2;
	float yy = y * y2;
	float yz = y * z2;
	float zz = z * z2;
	float wx = w * x2;
	float wy = w * y2;
	float wz = w * z2;

	result.m[0][0] = 1.0f - (yy + zz);
	result.m[0][1] = xy + wz;
	result.m[0][2] = xz - wy;
	result.m[0][3] = 0.0f;

	result.m[1][0] = xy - wz;
	result.m[1][1] = 1.0f - (xx + zz);
	result.m[1][2] = yz + wx;
	result.m[1][3] = 0.0f;

	result.m[2][0] = xz + wy;
	result.m[2][1] = yz - wx;
	result.m[2][2] = 1.0f - (xx + yy);
	result.m[2][3] = 0.0f;

	result.m[3][0] = 0.0f;
	result.m[3][1] = 0.0f;
	result.m[3][2] = 0.0f;
	result.m[3][3] = 1.0f;

	return result;
}
// ************************************************************************************************
float4_t float4x4_to_quaternion(
	const float4x4_t* matrix
)
{
	float4_t result;
	float trace = matrix->m[0][0] + matrix->m[1][1] + matrix->m[2][2];
	if (trace > 0.0f)
	{
		float s = 0.5f / sqrt(trace + 1.0f);
		result.w = 0.25f / s;
		result.x = (matrix->m[2][1] - matrix->m[1][2]) * s;
		result.y = (matrix->m[0][2] - matrix->m[2][0]) * s;
		result.z = (matrix->m[1][0] - matrix->m[0][1]) * s;
	}
	else
	{
		if (matrix->m[0][0] > matrix->m[1][1] && matrix->m[0][0] > matrix->m[2][2])
		{
			float s = 2.0f * sqrt(1.0f + matrix->m[0][0] - matrix->m[1][1] - matrix->m[2][2]);
			result.w = (matrix->m[2][1] - matrix->m[1][2]) / s;
			result.x = 0.25f * s;
			result.y = (matrix->m[0][1] + matrix->m[1][0]) / s;
			result.z = (matrix->m[0][2] + matrix->m[2][0]) / s;
		}
		else if (matrix->m[1][1] > matrix->m[2][2])
		{
			float s = 2.0f * sqrt(1.0f + matrix->m[1][1] - matrix->m[0][0] - matrix->m[2][2]);
			result.w = (matrix->m[0][2] - matrix->m[2][0]) / s;
			result.x = (matrix->m[0][1] + matrix->m[1][0]) / s;
			result.y = 0.25f * s;
			result.z = (matrix->m[1][2] + matrix->m[2][1]) / s;
		}
		else
		{
			float s = 2.0f * sqrt(1.0f + matrix->m[2][2] - matrix->m[0][0] - matrix->m[1][1]);
			result.w = (matrix->m[1][0] - matrix->m[0][1]) / s;
			result.x = (matrix->m[0][2] + matrix->m[2][0]) / s;
			result.y = (matrix->m[1][2] + matrix->m[2][1]) / s;
			result.z = 0.25f * s;
		}
	}
	return result;
}
// ************************************************************************************************
float4x4_t float4x4_transpose(const float4x4_t* matrix)
{
	float4x4_t result;

	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			result.m[i][j] = matrix->m[j][i];
		}
	}

	return result;
}
// ************************************************************************************************
float4x4_t float4x4_zero = {
	0.0f, 0.0f, 0.0f, 0.0f,
	0.0f, 0.0f, 0.0f, 0.0f,
	0.0f, 0.0f, 0.0f, 0.0f,
	0.0f, 0.0f, 0.0f, 0.0f
};
float4x4_t float4x4_unit = {
	1.0f, 0.0f, 0.0f, 0.0f,
	0.0f, 1.0f, 0.0f, 0.0f,
	0.0f, 0.0f, 1.0f, 0.0f,
	0.0f, 0.0f, 0.0f, 1.0f
};
// ************************************************************************************************