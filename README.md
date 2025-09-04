# SkidsteerCameraStick

## Problems to Solve
- No visibility over tall walls while operating our three skidsteers (CAT 242, 262, 299). Backfilling walls accounts for 50% of my work, requiring a spotter behind the wall to guide dumping locations and amounts.
- Relying on spotters is inefficient and frustrating due to inconsistent hand signals.
- Existing backup cameras on the skidsteers are inadequate (the 242 lacks one entirely). They wash out in bright sunlight, cloudy conditions, or shadows.
- Backup camera displays are too small for effective use.

## Solution
Mount an electric linear actuator on the skidsteer arm to pivot an 8ft (potentially length-adjustable) pole equipped with a camera facing forward and over the wall. Mount a 2nd camera on the backdoor. Mount a single display 7-10 inches, that acts as a backup camera most of the time, and when the pole is extended, automatically switch camera views.

- **Retracted Position**: The actuator is fully retracted, the camera on the backdoor is shown on the display
- **Extended Position**: The actuator extends, tilting the pole forward to view over walls. The display automatically changes channels.

Display options:
- For an Insta360 camera, use a smartphone as the display via wireless connection, with a USB-C charging cable running along the pole.
- Alternatively, use two cameras (forward- and rear-facing) with a dedicated monitor in the cab to show both feeds (wired or wireless TBD).

Power the system from the skidsteer's 12V battery in the engine compartment. Use an Arduino (Nano or ESP32) mounted inside the cab for a clean, dry, and air-conditioned environment. Include a control panel in the cab with 2 buttons (or a single switch—TBD) for simple operation: one to extend the actuator for ~4 seconds (or to a preset position), and another to fully retract. Maybe even add a momentary rocker switch for fine manual controll.

For flexibility, consider adding a potentiometer to adjust extension distance or a limit switch for precise stopping.

The goal is a simple, automated setup: Load dirt, approach the wall, press a button to extend (within 6 seconds), raise the bucket, view over the wall via the display, dump, then retract and repeat.

## Requirements
- **Stability**: The 8ft pole must remain steady when fully retracted or extended to avoid blurry camera feeds. Consider a Y-shaped support structure for resting positions, with limit switches for precise stopping.
- **Power Management**: Include a master switch (in the cab control panel) to cut all power when not in use, preventing battery drain overnight. Alternatively, tie a relay to the ignition for automatic power-on with the key (manual switch preferred to avoid relay idle draw).
- **Power Source**: Draw from the skidsteer's 12V battery with a 10-15A fuse at the battery for protection.
- **Camera Charging**: Run a USB-C charging cable along the 8ft pole for the Insta360.
- **Durability**: All electronics must be waterproof and heat-resistant; mount inside the cab for protection.
- **Speed**: Full extension within 6 seconds. The 18-inch Progressive Automations Actuator (3 in/s, 100lb force) achieves this.
- **Controls**: Buttons for one-press extension to a specified length and full retraction (no holding required). Use timing or limit switches for automation. A rocker switch might even be cool for manual fine tuned control, would not require any coding at all. Voice commands might even be cool.
- **Backup Functionality**: In retracted position, serve as a backup camera. The Rohent R4 dual rv backup camera acutally has a blue wire for switching the display channels perfect for this.
- **Display Alternatives**: If not using Insta360 with a phone, employ dual cameras (forward/backward) and a monitor (wired vs. wireless TBD).

## Parts Required
- **Linear Actuator**: [Progressive Automations 18 inch Linear Actuator 12VDC 100LB 3 inches per second](https://www.progressiveautomations.com/products/linear-actuator-ip66?variant=18277292638275) Provides the tilting mechanism for the camera pole.
- **Microcontroller**: Arduino Uno Rev4 WiFi (or ESP32 alternative for wireless features). Controls the actuator via timing or feedback for one-press operation.
- **Motor Driver**: [Cytron 13A DC Motor Driver MD10C](https://www.amazon.com/dp/B07CW3JZDH?ref=ppx_yo2ov_dt_b_fed_asin_title) (bidirectional H-bridge). Interfaces the microcontroller with the actuator for direction and speed control.
- **Motor Driver 2 if we dont care about speed**: [SunFounder Lab 4 Relay Module 5V](https://www.amazon.com/dp/B00E0NSORY?ref=ppx_yo2ov_dt_b_fed_asin_title&th=1)
- **Buttons/Switches**: 2 momentary push buttons (SPST) for extend/retract controls. Plus a master toggle switch (SPST, 10A+ at 12V) to kill all power when not in use. Maybe a rocker switch for fine controll
- **Camera**: [Rohent R4 dual rv backup camera](https://www.amazon.com/dp/B0C1ZJ63G5?ref=ppx_yo2ov_dt_b_fed_asin_title&th=1) Channel 1 is backup camera on back door, channel 2 is on the pole, and activated using blue wire that would normally be connected to the backup camera fuse on a vehicle for automatic channel change.
- **Pole**: 8ft aluminum tube (1-inch diameter, 0.049-inch wall thickness). Lightweight and sturdy for mounting the camera.
- **Power Components**:
  - 12V to 5V DC-DC buck converter (e.g., MP1584 module, 3A output) for USB-C camera charging.
  - Inline fuses: 10-15A for main circuit (at battery), 5A for charging line.
- **Wiring and Connectors**: 18 AWG stranded wire (red/black for power, ~15ft for runs to actuator/camera). Dupont/jumper wires for controls. USB-C cable (short, for camera connection).
- **Mounting and Support**: Hinge/pivot for actuator base, Y-shaped support bracket for pole stability. Weatherproof enclosure for cab-mounted electronics.
- **Optional**: Potentiometer (e.g., 10kΩ) for adjustable extension. Limit switches (if adding precise stopping beyond built-in actuator limits). Dedicated monitor (if using dual cameras instead of phone).
