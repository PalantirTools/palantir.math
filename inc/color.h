#ifndef COLOR_H
#define COLOR_H

// EXTERNAL INCLUDES
// INTERNAL INCLUDES
#include "basetypes.h"

typedef struct color_rgba
{
	byte r; /*< Red component of the color, 0-255 */
	byte g; /*< Green component of the color, 0-255 */
	byte b; /*< Blue component of the color, 0-255 */
	byte a; /*< Alpha component of the color, 0-255 (optional, can be used for transparency) */
} color_rgba_t;

/**
 * @brief Initialize a rgba color struct with specified values.
 * @param[in] r The red component.
 * @param[in] g The green component.
 * @param[in] b The blue component.
 * @param[in] a The alpha component.
 * @return the color in rgba format.
 */
inline static color_rgba_t color_rgba_init(
	byte r,
	byte g,
	byte b,
	byte a
)
{
	color_rgba_t color;
	color.r = r;
	color.g = g; 
	color.b = b;
	color.a = a;
	return color;
}

/**
 * @brief Initialize a rgba color struct with specified values.
 * @param[in] hex_color The color in hexadecimal format (0xRRGGBBAA).
 * @return the color in rgba format.
 */
inline static color_rgba_t color_rgba_from32(
	u32 hex_color
)
{
	hex_color = swap32(
		hex_color
	);

	color_rgba_t color;
	color.r = (hex_color >> 24) & 0xFF; // Extract red component
	color.g = (hex_color >> 16) & 0xFF; // Extract green component
	color.b = (hex_color >> 8) & 0xFF;  // Extract blue component
	color.a = hex_color & 0xFF;         // Extract alpha component
	return color;
}

/**
* @brief Convert a color in rgba format to an integer representation.
* @param[in] color_rgba The color in rgba format.
* @return The color in hexadecimal format (0xRRGGBBAA).
*/
inline static u32 color_rgba_to32(
	const color_rgba_t color_rgba
)
{
	u32 hex_color = 0;
	hex_color |= (u32)color_rgba.r << 24; // Set red component
	hex_color |= (u32)color_rgba.g << 16; // Set green component
	hex_color |= (u32)color_rgba.b << 8;  // Set blue component
	hex_color |= (u32)color_rgba.a;       // Set alpha component

	return swap32(hex_color);
}

#endif // COLOR_H