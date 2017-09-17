#ifndef MY_UNTL_H_
#define MY_UNTL_H_

#include "ev3api.h"

extern void init_f(const char *str);
extern void msg_f(const char *str, int32_t line);
extern void msg_f(int8_t n, int32_t line);
extern void msg_f(uint8_t n, int32_t line);
extern void msg_f(char n, int32_t line);

extern void msg_f(int16_t n, int32_t line);
extern void msg_f(uint16_t n, int32_t line);

extern void msg_f(int n, int32_t line);
extern void msg_f(unsigned int n, int32_t line);

extern void msg_f(int32_t n, int32_t line);
extern void msg_f(uint32_t n, int32_t line);

extern void msg_f(int64_t n, int32_t line);
extern void msg_f(uint64_t n, int32_t line);

extern void msg_f(float n, int32_t line);
extern void msg_f(double n, int32_t line);
#endif  // MY_UNTL_H_
