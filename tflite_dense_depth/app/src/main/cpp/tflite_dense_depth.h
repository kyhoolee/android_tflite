/* ------------------------------------------------ *
 * The MIT License (MIT)
 * Copyright (c) 2020 terryky1220@gmail.com
 * ------------------------------------------------ */
#ifndef TFLITE_DENSE_DEPTH_H_
#define TFLITE_DENSE_DEPTH_H_

#ifdef __cplusplus
extern "C" {
#endif

/* 
 * https://github.com/PINTO0309/PINTO_model_zoo/tree/master/064_Dense_Depth/nyu/01_float32
 */
#define DENSEDEPTH_MODEL_PATH         "model/dense_depth_nyu_480x640_float32.tflite"
#define DENSEDEPTH_QUANT_MODEL_PATH   "model/dense_depth_nyu_480x640_float32.tflite"

typedef struct _dense_depth_result_t
{
    float *depthmap;
    int   depthmap_dims[3];
} dense_depth_result_t;

int init_tflite_dense_depth (const char *model_buf, size_t model_size);

void  *get_dense_depth_input_buf (int *w, int *h);
int invoke_dense_depth (dense_depth_result_t *dense_depth_result);

#ifdef __cplusplus
}
#endif

#endif /* TFLITE_DENSE_DEPTH_H_ */
