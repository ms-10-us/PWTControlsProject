#include "../include/engine_config.h"

#include <stddef.h>

void engine_config_default(engine_config_t *config)
{
    if (config == NULL)
    {
        return;
    }

    config->cylinder_count = 4u;
    config->displacement_liters = 2.0f;
    config->trigger.total_teeth = 0u;
    config->trigger.missing_teeth = 0u;
    config->trigger.trigger_offset_deg = 0u;
    config->control_period_us = 10000u;
}

bool engine_config_validate(const engine_config_t *config)
{
    if (config == NULL || config->cylinder_count == 0u ||
        config->cylinder_count > 16u ||
        config->displacement_liters <= 0.0f ||
        config->displacement_liters >= 20.0f ||
        config->control_period_us == 0u)
    {
        return false;
    }

    if (config->trigger.total_teeth == 0u)
    {
        return config->trigger.missing_teeth == 0u;
    }

    return config->trigger.total_teeth >= 4u &&
           config->trigger.missing_teeth < config->trigger.total_teeth &&
           config->trigger.trigger_offset_deg >= 0.0f &&
           config->trigger.trigger_offset_deg < 360.0f;
}
