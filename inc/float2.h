#ifndef FLOAT2_H
#define FLOAT2_H

// EXTERNAL INCLUDES
// INTERNAL INCLUDES
#include "basetypes.h"

/**
* @brief Float2 structure
* @details This structure is used to represent a 2D vector in the game.
*/
typedef struct float2_t
{
	f32 x; /**< The x component of the vector */
	f32 y; /**< The y component of the vector */
} float2_t;

/**
* @brief Adds two float2_t vectors
* @param[in] a The first vector
* @param[in] b The second vector
* @return The sum of the two vectors
*/
extern float2_t float2_add(
	const float2_t a,
	const float2_t b
);

/**
* @brief Subtracts two float2_t vectors
* @param[in] a The first vector
* @param[in] b The second vector
* @return The difference of the two vectors
*/
extern float2_t float2_sub(
	const float2_t a,
	const float2_t b
);

/**
* @brief Scales a float2_t vector
* @param[in] a The vector to scale
* @param[in] scalar The scalar to multiply the vector by
* @return The scaled vector
*/
extern float2_t float2_scale(
	const float2_t a,
	const f32 scalar
);

/**
* @brief Calculates the dot product of two float2_t vectors
* @param[in] a The first vector
* @param[in] b The second vector
* @return The dot product of the two vectors
*/
extern f32 float2_dot(
	const float2_t a,
	const float2_t b
);

/**
* @brief Calculates the cross product of two float2_t vectors
* @param[in] a The first vector
* @param[in] b The second vector
* @return The cross product of the two vectors
*/
extern f32 float2_cross(
	const float2_t a,
	const float2_t b
);

/**
* @brief Calculates the length of a float2_t vector
* @param[in] a The vector to calculate the length of
* @return The length of the vector
*/
extern f32 float2_length(
	const float2_t a
);

/**
* @brief Calculates the squared length of a float2_t vector
* @param[in] a The vector to calculate the squared length of
* @return The squared length of the vector
*/
extern f32 float2_sqr_length(
	const float2_t a
);

/**
* @brief Calculates the distance between two float2_t vectors
* @param[in] a The first vector
* @param[in] b The second vector
* @return The distance between the two vectors
*/
extern f32 float2_distance(
	const float2_t a,
	const float2_t b
);

/**
* @brief Calculates the angle between two float2_t vectors
* @param[in] a The first vector
* @param[in] b The second vector
* @return The angle between the two vectors
*/
extern f32 float2_angle(
	const float2_t a,
	const float2_t b
);

/**
* @brief Normalizes a float2_t vector
* @param[in] a The vector to normalize
* @return The normalized vector
*/
extern float2_t float2_normalize(
	const float2_t a
);

extern float2_t float2_zero;
extern float2_t float2_unitx;
extern float2_t float2_unity;
extern float2_t float2_unitscale;

#endif // FLOAT2_H
