#pragma once
#include <stdint.h>

#ifdef _WIN32
  #ifdef RADESKTOP_NATIVECORE_EXPORTS
    #define RD_API __declspec(dllexport)
  #else
    #define RD_API __declspec(dllimport)
  #endif
#else
  #define RD_API
#endif

#ifdef __cplusplus
extern "C" {
#endif

RD_API int rd_ping(void);

#ifdef __cplusplus
}
#endif
