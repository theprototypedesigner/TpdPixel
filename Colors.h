#ifndef _COLORS_H
#define _COLORS_H

typedef uint32_t color32_t;
#define COLOR32(r,g,b)  ((color32_t)(((uint32_t)r<<16)|((uint16_t)g<<8)|b)) // return ((uint32_t)r << 16) | ((uint32_t)g <<  8) | b;
#define COLOR32_W(r,g,b,w)   ((color32_t)(((uint32_t)w<<24)|((uint32_t)r<<16)|((uint16_t)g<<8)|b)) // return ((uint32_t)w << 24) |(uint32_t)r << 16) | ((uint32_t)g <<  8) | b;

#define WHITE          COLOR32(255,255,255)
#define RED            COLOR32(255,0,0)
#define GREEN          COLOR32(0,255,0)
#define BLUE           COLOR32(0,0,255)
#define YELLOW         COLOR32(255,200,0)
#define ORANGE         COLOR32(255,64,0)

//HSV colors, only define hue
#define hsvRED        0
#define hsvGREEN      65536/3
#define hsvBLUE      65536*2/3

#endif
