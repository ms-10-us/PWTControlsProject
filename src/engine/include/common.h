#ifndef ENGINE_COMMON_H
#define ENGINE_COMMON_H

#include <stdbool.h>
#include <stdint.h>

typedef enum
{
    ENGINE_MODE_OFF = 0,
    ENGINE_MODE_CRANKING,
    ENGINE_MODE_RUNNING,
    ENGINE_MODE_LIMP,
    ENGINE_MODE_FAULT
} engine_mode_t;

typedef enum
{
    ENGINE_FAULT_NONE = 0,
    ENGINE_FAULT_HAL_INIT,
    ENGINE_FAULT_SENSOR_READ,
    ENGINE_FAULT_SENSOR_INVALID,
    ENGINE_FAULT_CALIBRATION_INVALID
} engine_fault_t;

enum
{
    SENSOR_VALID_RPM = 1u << 0,
    SENSOR_VALID_MAP = 1u << 1,
    SENSOR_VALID_IAT = 1u << 2,
    SENSOR_VALID_COOLANT = 1u << 3,
    SENSOR_VALID_PEDAL = 1u << 4,
    SENSOR_VALID_THROTTLE = 1u << 5,
    SENSOR_VALID_ALL = (1u << 6) - 1u
};

typedef struct
{
    float rpm;
    float map_kpa;
    float iat_c;
    float coolant_c;
    float pedal_pct;
    float throttle_pct;
    uint32_t validity_flags;
    uint64_t timestamp_us;
} engine_measurements_t;

typedef struct
{
    engine_mode_t mode;
    float rpm;
    float load_estimate;
    float crank_angle_deg;
    uint32_t fault_flags;
    uint64_t timestamp_us;
} engine_state_t;

typedef struct
{
    float fuel_mass_mg;
    float injection_angle_deg;
    float spark_angle_deg;
    uint32_t coil_dwell_us;
    float throttle_pct;
    bool injector_enable;
    bool ignition_enable;
    bool throttle_enable;
} engine_actuator_commands_t;

typedef struct
{
    engine_actuator_commands_t commands;
    bool outputs_permitted;
} engine_approved_outputs_t;

#endif
