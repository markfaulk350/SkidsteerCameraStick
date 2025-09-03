# SkidsteerCameraStick

## Problems to Solve
- No visibility over tall walls while operating our three skidsteers (CAT 242, 262, 299). Backfilling walls accounts for 50% of my work, requiring a spotter behind the wall to guide dumping locations and amounts.
- Relying on spotters is inefficient and frustrating due to inconsistent hand signals.
- Existing backup cameras on the skidsteers are inadequate (the 242 lacks one entirely). They wash out in bright sunlight, cloudy conditions, or shadows.
- Backup camera displays are too small for effective use.

## Solution
Mount an electric linear actuator on the skidsteer arm to pivot an 8ft (potentially length-adjustable) pole equipped with a camera (e.g., Insta360 or dual wide-angle Arduino-compatible cameras facing forward and backward). 

- **Retracted Position**: The actuator is fully retracted, positioning the pole as a wide-angle rear-facing backup camera.
- **Extended Position**: The actuator extends, tilting the pole forward and downward to view over walls.

Display options:
- For an Insta360 camera, use a smartphone as the display via wireless connection, with a USB-C charging cable running along the pole.
- Alternatively, use two cameras (forward- and rear-facing) with a dedicated monitor in the cab to show both feeds (wired or wireless TBD).

Power the system from the skidsteer's 12V battery in the engine compartment. Use an Arduino (Nano or ESP32) mounted inside the cab for a clean, dry, and air-conditioned environment. Include a control panel in the cab with 2 buttons (or a single switch—TBD) for simple operation: one to extend the actuator for ~4 seconds (or to a preset position), and another to fully retract.

For flexibility, consider adding a potentiometer to adjust extension distance (e.g., based on the Firgelli Deluxe Rod Actuator's 3 in/s speed) or a limit switch for precise stopping.

The goal is a simple, automated setup: Load dirt, approach the wall, press a button to extend (within 6 seconds), raise the bucket, view over the wall via the display, dump, then retract and repeat.

Standard Firgelli setups (e.g., momentary rocker switches requiring constant hold) won't suffice— a microcontroller is needed for one-press automation.

## Requirements
- **Stability**: The 8ft pole must remain steady when fully retracted or extended to avoid blurry camera feeds. Consider a Y-shaped support structure for resting positions, with limit switches for precise stopping.
- **Power Management**: Include a master switch (in the cab control panel) to cut all power when not in use, preventing battery drain overnight. Alternatively, tie a relay to the ignition for automatic power-on with the key (manual switch preferred to avoid relay idle draw).
- **Power Source**: Draw from the skidsteer's 12V battery with a 10-15A fuse at the battery for protection.
- **Camera Charging**: Run a USB-C charging cable along the 8ft pole for the Insta360.
- **Durability**: All electronics must be waterproof and heat-resistant; mount inside the cab for protection.
- **Speed**: Full extension within 6 seconds. The 18-inch Firgelli Deluxe Rod Actuator (3 in/s, 100lb force) achieves this.
- **Controls**: Buttons for one-press extension to a specified length and full retraction (no holding required). Use timing or limit switches for automation.
- **Backup Functionality**: In retracted position, serve as a backup camera.
- **Display Alternatives**: If not using Insta360 with a phone, employ dual cameras (forward/backward) and a monitor (wired vs. wireless TBD).

## Parts Required
- **Linear Actuator**: Firgelli Deluxe Rod Actuator, 18-inch stroke, 100lb force, 3 in/s speed (12V DC). Provides the tilting mechanism for the camera pole.
- **Microcontroller**: Arduino Uno Rev4 WiFi (or ESP32 alternative for wireless features). Controls the actuator via timing or feedback for one-press operation.
- **Motor Driver**: Cytron MD10C (10A continuous, bidirectional H-bridge). Interfaces the microcontroller with the actuator for direction and speed control.
- **Buttons/Switches**: 2 momentary push buttons (SPST) for extend/retract controls. Plus a master toggle switch (SPST, 10A+ at 12V) to kill all power when not in use.
- **Camera**: Insta360 X3 (360-degree camera for forward/backward views). Alternatively, 2 wide-angle cameras. The backup camera doesn't necessarily need to be on the pole, it can be mounted on the back door of the skid steer.
- **Pole**: 8ft aluminum tube (1-inch diameter, 0.049-inch wall thickness). Lightweight and sturdy for mounting the camera.
- **Power Components**:
  - 12V to 5V DC-DC buck converter (e.g., MP1584 module, 3A output) for USB-C camera charging.
  - Inline fuses: 10-15A for main circuit (at battery), 5A for charging line.
- **Wiring and Connectors**: 18 AWG stranded wire (red/black for power, ~15ft for runs to actuator/camera). Dupont/jumper wires for controls. USB-C cable (short, for camera connection).
- **Mounting and Support**: Hinge/pivot for actuator base, Y-shaped support bracket for pole stability. Weatherproof enclosure for cab-mounted electronics.
- **Optional**: Potentiometer (e.g., 10kΩ) for adjustable extension. Limit switches (if adding precise stopping beyond built-in actuator limits). Dedicated monitor (if using dual cameras instead of phone).
