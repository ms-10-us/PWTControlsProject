#include "../include/engine_hal.h"

bool engine_hal_is_valid(const engine_hal_t *hal)
{
    return hal != 0 && hal->init != 0 && hal->read_inputs != 0 &&
           hal->apply_outputs != 0 && hal->get_time_us != 0;
}
