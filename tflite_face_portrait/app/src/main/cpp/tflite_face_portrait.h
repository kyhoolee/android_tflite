/* ------------------------------------------------ *
 * The MIT License (MIT)
 * Copyright (c) 2020 terryky1220@gmail.com
 * ------------------------------------------------ */
#ifndef TFLITE_FACE_SEGMENTATION_H_
#define TFLITE_FACE_SEGMENTATION_H_

#ifdef __cplusplus
extern "C" {
#endif

/* 
 * https://github.com/PINTO0309/PINTO_model_zoo/tree/master/061_U-2-Net/20_portrait_model
 * https://github.com/NathanUA/U-2-Net
 */
#define FACE_DETECT_MODEL_PATH          "model/face_detection_front.tflite"
#define FACE_PORTRAIT_MODEL_PATH        "model/saved_model/model_float32.tflite"

#define MAX_FACE_NUM     100

enum face_key_id {
    kRightEye = 0,  //  0
    kLeftEye,       //  1
    kNose,          //  2
    kMouth,         //  3
    kRightEar,      //  4
    kLeftEar,       //  5

    kFaceKeyNum
};

typedef struct fvec2
{
    float x, y;
} fvec2;

typedef struct _face_t
{
    float score;
    fvec2 topleft;
    fvec2 btmright;
    fvec2 keys[kFaceKeyNum];

    float rotation;
    float face_cx;
    float face_cy;
    float face_w;
    float face_h;
    fvec2 face_pos[4];
} face_t;

typedef struct _face_detect_result_t
{
    int num;
    face_t faces[MAX_FACE_NUM];
} face_detect_result_t;


typedef struct _portrait_result_t
{
    float *portrait_img;
    int   portrait_img_dims[3]; 
} portrait_result_t;



int init_tflite_portrait (const char *face_detect_model_buf,   size_t face_detect_model_size, 
                          const char *face_portrait_model_buf, size_t face_portrait_model_size);

void *get_face_detect_input_buf (int *w, int *h);
int  invoke_face_detect (face_detect_result_t *facedet_result);

void  *get_portrait_input_buf (int *w, int *h);
int invoke_portrait (portrait_result_t *portrait_result);

#ifdef __cplusplus
}
#endif

#endif /* TFLITE_FACE_SEGMENTATION_H_ */
