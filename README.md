# PWTControlsProject

## Project layout

```text
src/
  main.c
  engine/
    app/
      engine_app.c
      engine_modes.c
    control/
      fuel_control.c
      ignition_control.c
      air_control.c
    estimator/
      engine_estimator.c
    safety/
      safety_monitor.c
    diagnostics/
      diagnostic_manager.c
    calibration/
      calibration.c
    platform/
      engine_hal.c
      event_scheduler.c
    include/
      engine_types.h
      engine_hal.h
```

The source files are scaffolds; application behavior has not been defined yet.
The VS Code **Build project** task builds all source files into
`build/pwt-controls`. Run it with **Run Task** → **Run project**; the run task
builds the executable first. **Build active C file** is also available for
compiling the currently open `.c` file to an object file.
