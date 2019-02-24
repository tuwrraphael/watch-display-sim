#ifndef NRF_DEF
#define NRF_DEF
#include "stdint.h"
typedef uint8_t ret_code_t;
typedef enum
{
    NRF_DRV_STATE_INITIALIZED,
    NRF_DRV_STATE_UNINITIALIZED
} nrf_drv_state_t;
#define ASSERT(x)
#define NRF_SUCCESS 0
#define NRF_ERROR_INVALID_PARAM 1
#define CEIL_DIV(A, B)      \
    (((A) + (B) - 1) / (B))
#endif