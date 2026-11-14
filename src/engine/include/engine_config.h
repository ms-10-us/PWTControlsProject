#ifndef ENGINE_CONFIG_H
#define ENGINE_CONFIG_H

#include <stdbool.h>
#include <stdint.h>

typedef struct
{
    uint16_t total_teeth;
    uint16_t missing_teeth;
    float trigger_offset_deg;
} engine_trigger_config_t;

typedef struct
{
    uint8_t cylinder_count;
    float displacement_liters;
    engine_trigger_config_t trigger;
    uint32_t control_period_us;
} engine_config_t;

bool engine_config_validate(const engine_config_t *config);
void engine_config_default(engine_config_t *config);

#endif
