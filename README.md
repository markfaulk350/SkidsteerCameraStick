# SkidsteerCameraStick

## Problems to Solve
- No visibility over tall walls while operating our three skidsteers (CAT 242, 262, 299). Backfilling walls accounts for 50% of my work, requiring a spotter behind the wall to guide dumping locations and amounts.
- Relying on spotters is inefficient and frustrating due to inconsistent hand signals.
- Existing backup cameras on the skidsteers are inadequate (the 242 lacks one entirely). They wash out in bright sunlight, cloudy conditions, or shadows.
- Backup camera displays are too small for effective use.

## Solution
Mount an electric linear actuator on the skidsteer arm to pivot an 8ft (potentially length-adjustable) pole equipped with a camera facing forward and over the wall. Mount a 2nd camera on the backdoor. Mount a single display 7-10 inches, that acts as a backup camera most of the time, and when the pole is extended, automatically switch camera views.

- **Retracted Position**: The actuator is fully retracted, the camera on the backdoor is shown on the display
- **Middle Position**: The actuator stops where it is. The display shows the camera on the pole. This allows for manual controll by the operator, they might want the pole to angle forward or back just a little, this allows them to stop it in place.
- **Extended Position**: The actuator extends, tilting the pole forward to view over walls. The display automatically changes channels.

Power the system from the skidsteer's 12V battery in the engine compartment. Use an Arduino (Nano usb C ESP32) mounted inside the cab behind the seat for a clean, dry, and air-conditioned environment. A 3 way non momentary rocker switch controls the linear actuator and display channel. The rocker switch allows for automatic and manual control. 

The goal is a simple, automated setup: Load dirt, approach the wall, press a button to extend (within 6 seconds), raise the bucket, view over the wall via the display, dump, then retract and repeat.

## Requirements
- **Power Management**: Include a master switch (in the cab control panel) to cut all power when not in use, preventing battery drain overnight. Alternatively, tie a relay to the ignition for automatic power-on with the key (manual switch preferred to avoid relay idle draw).
- **Power Source**: Draw from the skidsteer's 12V battery with a fuse at the battery for protection.
- **Durability**: Electronics must be dustproof, heat-resistant and not affected by vibrations and hard jolts; mount inside the cab for protection.
- **Controls**: 3 way non momentary rocker switch to controll the linear actuator and display channel
- **Backup Functionality**: In retracted position, serve as a backup camera. The Rohent R4 dual rv backup camera acutally has a blue wire for switching the display channels perfect for this.

## Parts Required
- **Linear Actuator**: [Progressive Automations 18 inch Linear Actuator 12VDC 100LB 3 inches per second](https://www.progressiveautomations.com/products/linear-actuator-ip66?variant=18277292638275) Provides the tilting mechanism for the camera pole.
- **Microcontroller**: [Arduino® Nano ESP32 with headers](https://store.arduino.cc/products/nano-esp32-with-headers?srsltid=AfmBOopsVC_qkmjf2s_Hj-NHDhS9w01Qv0nPDyFWVbaifmIE6gNorpFh)
- **Motor Driver**: [Cytron 13A DC Motor Driver MD10C](https://www.amazon.com/dp/B07CW3JZDH?ref=ppx_yo2ov_dt_b_fed_asin_title) (bidirectional H-bridge). Interfaces the microcontroller with the actuator for direction and speed control.
- **Buttons/Switches**: [SPDT ON-Off-ON 3 Pin 3 Position Latching Switch Toggle Rocker](https://www.amazon.com/dp/B07D7463T7?ref=ppx_yo2ov_dt_b_fed_asin_title&th=1) with 10k? pull down resistors
- **Camera**: [Rohent R4 dual rv backup camera](https://www.amazon.com/dp/B0C1ZJ63G5?ref=ppx_yo2ov_dt_b_fed_asin_title&th=1) Channel 1 is on the pole w the linear actuator, channel 2 is the backup camera mounted on the back door. Channel 2 is activated by connecting the blue wire on the wiring harness to 12V+. 
- **Pole**: 8ft aluminum square tube (1-inch square, 0.062-inch wall thickness). Lightweight and sturdy for mounting the camera.
- **Power Components**:
  - 12V to 5V or 3.3V??? DC-DC buck converter for the arduino nano
  - Inline fuses: 10-15A for main circuit (at battery)
  - Pull down resistors for 3 way switch
- **Wiring and Connectors**: What size wires needed to run to linear actuator and battery?
- **2mm nylon washers for pole rotation**: [uxcell 25Pcs M10 Nylon Flat Washers Plain Washer 10mm ID 30mm OD 2mm Thick Plastic Washers](https://www.amazon.com/uxcell-Washers-Washer-Plastic-Plumbing/dp/B0F1866XB9/ref=sr_1_6?crid=D7TA55NTUPB2&dib=eyJ2IjoiMSJ9.E4peaiHlvUqwkIQZe9oUDEIo6XNfoY2zX8ClIUL0EfRXNAc_fh-UBrXHTdobxFx8UyVgR3lDDLA3dZtv_kb5ZjWZWzbdlaPN_908DT4MgaUmr2X3j3GhfYomMX7eaetQ2Jlxb_NNiatXfpnNMPe49pYDOyJicS4Qss-Guun5xJtrUfiuKw5YD0HfPddwYoUc-F6o1ROO7-dRV_v5FEyRifyp5NFtsLKaoY17kapM7ekJxR6y33gd-KpW9IoEf2olT4bvmETzXNJK1H66cqPVeKuwUmIhydYWVnw4XvZ21F4.JhILD7gJJwecVn5rQwg1O3_5s3Tx7dsRrHov-GOek5E&dib_tag=se&keywords=flat%2Bfender%2Bwasher%2Bnylon%2Bm10&qid=1757287075&s=hi&sprefix=flat%2Bfender%2Bwasher%2Bnylon%2Bm10%2Ctools%2C183&sr=1-6&th=1)
