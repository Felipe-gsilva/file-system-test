#ifdef _header
#define _header
#else

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define u8 uint8_t
#define u16 uint16_t
#define u32 uint32_t
#define u64 uint64_t

#define i8 int8_t
#define i16 int16_t
#define i32 int32_t
#define i64 int64_t

#define UINT_MAX 800

typedef struct header_record {
  i8 rrn;
  i8 default_size;

} header_record;

#endif
