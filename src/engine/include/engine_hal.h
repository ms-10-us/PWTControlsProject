#ifndef ENGINE_HAL_H
#define ENGINE_HAL_H

#include "common.h"

typedef struct
{
    bool (*init)(void *context);
    bool (*read_inputs)(void *context, engine_measurements_t *measurements);
    bool (*apply_outputs)(void *context, const engine_approved_outputs_t *outputs);
    uint64_t (*get_time_us)(void *context);
    void *context;
} engine_hal_t;

bool engine_hal_is_valid(const engine_hal_t *hal);

#endif
