#ifndef FLOAT3_H
#define FLOAT3_H

// EXTERNAL INCLUDES
// INTERNAL INCLUDES
#include "basetypes.h"

/**
* @brief Float3 structure
* @details This structure is used to represent a 3D vector in the game.
*/
typedef struct float3_t
{
	f32 x; /**< The x component of the vector */
	f32 y; /**< The y component of the vector */
	f32 z; /**< The z component of the vector */
} float3_t;

/**
* @brief float3_create function that creates a float3_t vector
* @param[in] x The x component of the vector
* @param[in] y The y component of the vector
* @param[in] z The z component of the vector
* @return The created vector
*/
extern float3_t float3_create(
	const f32 x,
	const f32 y,
	const f32 z
);

/**
* @brief float3_add function that adds two float3_t vectors
* @param[in] a The first vector
* @param[in] b The second vector
* @return The sum of the two vectors
*/
extern float3_t float3_add(
	const float3_t a,
	const float3_t b
);

/**
* @brief float3_sub function that subtracts two float3_t vectors
* @param[in] a The first vector
* @param[in] b The second vector
* @return The difference of the two vectors
*/
extern float3_t float3_sub(
	const float3_t a,
	const float3_t b
);

/**
* @brief float3_scale function that scales a float3_t vector by a scalar
* @param[in] a The vector
* @param[in] scalar The scalar
* @return The scaled vector
*/
extern float3_t float3_scale(
	const float3_t a,
	const f32 scalar
);

/**
* @brief float3_dot function that calculates the dot product of two float3_t vectors
* @param[in] a The first vector
* @param[in] b The second vector
* @return The dot product of the two vectors
*/
extern f32 float3_dot(
	const float3_t a,
	const float3_t b
);

/**
* @brief float3_cross function that calculates the cross product of two float3_t vectors
* @param[in] a The first vector
* @param[in] b The second vector
* @return The cross product of the two vectors
*/
extern float3_t float3_cross(
	const float3_t a,
	const float3_t b
);

/**
* @brief float3_length function that calculates the length of a float3_t vector
* @param[in] a The vector
* @return The length of the vector
*/
extern f32 float3_length(
	const float3_t a
);

/**
* @brief float3_sqr_length function that calculates the squared length of a float3_t vector
* @param[in] a The vector
* @return The squared length of the vector
*/
extern f32 float3_sqr_length(
	const float3_t a
);

/**
* @brief float3_distance function that calculates the distance between two float3_t vectors
* @param[in] a The first vector
* @param[in] b The second vector
* @return The distance between the two vectors
*/
extern f32 float3_distance(
	const float3_t a,
	const float3_t b
);

/**
* @brief float3_angle function that calculates the angle between two float3_t vectors
* @param[in] a The first vector
* @param[in] b The second vector
* @return The angle between the two vectors
*/
extern f32 float3_angle(
	const float3_t a,
	const float3_t b
);

/**
* @brief float3_normalize function that normalizes a float3_t vector
* @param[in] a The vector
* @return The normalized vector
*/
extern float3_t float3_normalize(
	const float3_t a
);

/**
* @brief float3_negate function that negates a float3_t vector
* @param[in] a The vector
* @return The negated vector
*/
extern float3_t float3_negate(
	const float3_t a
);

extern float3_t float3_zero;
extern float3_t float3_unitx;
extern float3_t float3_unity;
extern float3_t float3_unitz;
extern float3_t float3_unitscale;

#endif // FLOAT3_H
