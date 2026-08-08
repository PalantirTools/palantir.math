#ifndef FLOAT4x4_H
#define FLOAT4x4_H

// EXTERNAL INCLUDES
// INTERNAL INCLUDES
#include "basetypes.h"
#include "float2.h"
#include "float4.h"

/**
* @brief Float4x4 structure
* @details This structure is used to represent a 4D matrix.
*/
typedef struct float4x4_t
{
	union
	{
		float m[4][4];			/**< The matrix as a 2D array */
		float4_t rows[4];		/**< The rows of the matrix */
		struct
		{
			float4_t right;		/**< The right vector	(DX11 => -X)*/
			float4_t forward;	/**< The forward vector	(DX11 => +Y)*/
			float4_t up;		/**< The up vector		(DX11 => +Z)*/
			float4_t location;	/**< The location vector */
		};
	};
} float4x4_t;

/**
* @brief Create a new float4x4_t with the given values
* @param[in] m00 The value at row 0, column 0
* @param[in] m01 The value at row 0, column 1
* @param[in] m02 The value at row 0, column 2
* @param[in] m03 The value at row 0, column 3
* @param[in] m10 The value at row 1, column 0
* @param[in] m11 The value at row 1, column 1
* @param[in] m12 The value at row 1, column 2
* @param[in] m13 The value at row 1, column 3
* @param[in] m20 The value at row 2, column 0
* @param[in] m21 The value at row 2, column 1
* @param[in] m22 The value at row 2, column 2
* @param[in] m23 The value at row 2, column 3
* @param[in] m30 The value at row 3, column 0
* @param[in] m31 The value at row 3, column 1
* @param[in] m32 The value at row 3, column 2
* @param[in] m33 The value at row 3, column 3
* @return The new float4x4_t
*/
extern float4x4_t float4x4_create(
	float m00, float m01, float m02, float m03,
	float m10, float m11, float m12, float m13,
	float m20, float m21, float m22, float m23,
	float m30, float m31, float m32, float m33
);

/**
* @brief Create a new float4x4_t with the given rows
* @param[in] row0 The first row
* @param[in] row1 The second row
* @param[in] row2 The third row
* @param[in] row3 The fourth row
* @return The new float4x4_t
*/
extern float4x4_t float4x4_create_rows(
	float4_t row0,
	float4_t row1,
	float4_t row2,
	float4_t row3
);

/**
* @brief Extract the translation vector from the given matrix
* @param[in] matrix The matrix to extract the translation vector from
* @return The translation vector
*/
extern float4_t float4x4_get_translation(
	const float4x4_t* matrix
);

/**
* @brief Rotate the given matrix around an axis by an angle
* @param[in] matrix The matrix to rotate
* @param[in] axis The axis to rotate around
* @param[in] angle The angle to rotate by
*/
extern void float4x4_rotate(
	float4x4_t* matrix,
	const float3_t axis,
	float angle
);

/**
* @brief Multiply two matrices
* @param[in] a The first matrix
* @param[in] b The second matrix
* @return The result of the multiplication
*/
extern float4x4_t float4x4_mul(
	const float4x4_t* a,
	const float4x4_t* b
);

/**
* @brief Multiply matrix with float3
* @param[in] a The matrix
* @param[in] b The float3 vector
* @return The result of the multiplication
*/
extern float3_t float4x4_mul_float3(
	const float4x4_t* a,
	const float3_t vec
);

/**
* @brief Normalize the given matrix
* @param[in] matrix The matrix to normalize
*/
extern void float4x4_normalize(
	float4x4_t* matrix
);

/**
* @brief Get rotation matrix from quaternion
* @param[in] q The quaternion
* @return The rotation matrix
*/
extern float4x4_t float4x4_from_quaternion(
	const float4_t q
);

/**
* @brief Get a quaternion from the given matrix
* @param[in] matrix The matrix to get the quaternion from
* @return The quaternion
*/
extern float4_t float4x4_to_quaternion(
	const float4x4_t* matrix
);

/**/
extern float4x4_t float4x4_projection(
	float2_t dim, float2_t clip, f32 fov
);
/**
* @brief Transpose a matrix
* @param[in] matrix The matrix to be transposed
* @return The transposed matrix
*/
extern float4x4_t float4x4_transpose(
	const float4x4_t* matrix
);

extern float4x4_t float4x4_zero;
extern float4x4_t float4x4_unit;

#endif // FLOAT4x4_H