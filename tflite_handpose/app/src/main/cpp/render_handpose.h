/* ------------------------------------------------ *
 * The MIT License (MIT)
 * Copyright (c) 2020 terryky1220@gmail.com
 * ------------------------------------------------ */
#ifndef _RENDER_HANDPOSE_H_
#define _RENDER_HANDPOSE_H_

#ifdef __cplusplus
extern "C" {
#endif

int init_cube (float aspect, int texid);
int draw_cube (float *mtxGlobal, float *color);
int draw_floor (float *mtxGlobal, float div_u, float div_v);
int draw_line (float *mtxGlobal, float *p0, float *p1, float *color);
int draw_triangle (float *mtxGlobal, float *p0, float *p1, float *p2, float *color);
int draw_bone (float *mtxGlobal, float *p0, float *p1, float radius, float *color, int is_shadow);
int draw_sphere (float *mtxGlobal, float *p0, float radius, float *color, int is_shadow);

#ifdef __cplusplus
}
#endif
#endif /* _RENDER_HANDPOSE_H_ */
 