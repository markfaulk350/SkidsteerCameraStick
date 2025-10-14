# SkidsteerCameraStick

# Todo
* Double check the relay wiring
* Create a chart with net classes on Github and trace widths for each component. Make it clean and easy to reference, then import into kicad net classes
* Double check that the screw terminals are facing the right way
* Order Ferrules to crimp wires for screw terminals
* Switch to 2oz copper PCB for thinner 12v traces
* Still need a master switch for the whole thing at the battery


## Links
* [KiCad Notes | Google Docs](https://docs.google.com/document/d/1usLAj8TeU9ySPlYqQSOAUMu8hb1_OTA7hICEiQGOk0k/edit?usp=sharing)
* [Youtube | Favorite Arduino Tutorials](https://youtube.com/playlist?list=PLyKjpU5lY5xfGhrxrlotU2c3Mt58I1N_h&si=k3vkIwTQYjMZBtbj)
* [Udemy KiCad Course](https://www.udemy.com/course/kicad-like-a-pro-3e/learn/lecture/28807802#overview)
* [All About Circuits | Learning Projects](https://www.allaboutcircuits.com/textbook/experiments/)
* [www.electronics-tutorials](https://www.electronics-tutorials.ws/)

## Problems to Solve
- No visibility over tall walls while operating our three skidsteers (CAT 242, 262, 299). Backfilling walls accounts for 50% of my work, requiring a spotter behind the wall to guide dumping locations and amounts.
- Relying on spotters is inefficient and frustrating due to inconsistent hand signals.
- Existing backup cameras on the skidsteers are inadequate (the 242 lacks one entirely). They wash out in bright sunlight, cloudy conditions, or shadows.
- Backup camera displays are too small for effective use.

## Solution
Mount an electric linear actuator on the skidsteer arm to pivot an 8ft (potentially length-adjustable) pole equipped with a camera facing forward and over the wall. Mount a 2nd camera on the backdoor. Mount a single display 7-10 inches, that acts as a backup camera most of the time, and when the pole is extended, automatically switch camera views.

- **Retracted Position**: The actuator is fully retracted until it hits its internal limit switch, the camera on the backdoor is shown on the display (channel 2)
- **Middle Position**: The actuator stops where it is. The display shows the camera on the pole (channel 1). This allows for manual controll by the operator, they might want the pole to angle forward or back just a little, this allows them to stop it in place.
- **Extended Position**: The actuator extends until it hits its internal limit switch, tilting the pole forward to view over walls. The display shows (channel 1).

Power the system from the skidsteer's 12V battery in the engine compartment. Use an Arduino (Nano usb C ESP32) mounted inside the cab behind the seat for a clean, dry, and air-conditioned environment. A 3 way non momentary rocker switch controls the linear actuator and display channel. The rocker switch allows for automatic and manual control.

My company has 4 skidsteer (CAT 242, 262, 2x 299). I want to install this backup camera and wiring harness in each one. The linear actuator assembly is basically going to be an optional accessory. If I need it, I will strap it to the right arm and connect the power and camera cable. If I dont need the acutator that day, I can leave it at home, and the system will act as a normal backup camera that is always on. I want to be able to mount the linear actuator assembly to any of our 4 skidsteer.

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
- **Buck Converter**: [MP1584EN DC-DC Buck Converter Adjustable for 12V --> 7V for nano](https://www.amazon.com/dp/B01MQGMOKI?ref=ppx_yo2ov_dt_b_fed_asin_title&th=1)
- **Motor Driver**: [Cytron 13A DC Motor Driver MD10C](https://www.amazon.com/dp/B07CW3JZDH?ref=ppx_yo2ov_dt_b_fed_asin_title) (bidirectional H-bridge). Interfaces the microcontroller with the actuator for direction and speed control.
- **Relay 3.3V --> 12V**: [Teyleten Robot DC 1 Channel Optocoupler 3V/3.3V Relay](https://www.amazon.com/dp/B07XGZSYJV?ref=ppx_yo2ov_dt_b_fed_asin_title) This will be used to change the display channel. When 12VDC+ is applied to the blue wire on the backup camera wiring harness, channel 2 is shown
- **Buttons/Switches**: [SPDT ON-Off-ON 3 Pin 3 Position Latching Switch Toggle Rocker](https://www.amazon.com/dp/B07D7463T7?ref=ppx_yo2ov_dt_b_fed_asin_title&th=1) with 10k pull down resistors
- **Camera**: [Rohent R4 dual rv backup camera](https://www.amazon.com/dp/B0C1ZJ63G5?ref=ppx_yo2ov_dt_b_fed_asin_title&th=1) Channel 1 is on the pole w the linear actuator, channel 2 is the backup camera mounted on the back door. Channel 2 is activated by connecting the blue wire on the wiring harness to 12V+. 
- **Pole**: 8ft aluminum square tube (1-inch square, 0.062-inch wall thickness). Lightweight and sturdy for mounting the camera.
- **Power Components**:
  - Inline fuses: 10-15A for main circuit (at battery), 5A for buck converter?
  - Pull down resistors for 3 way switch
- **Wiring and Connectors**: What size wires needed to run to linear actuator and battery?
- **2mm nylon washers for pole rotation**: [uxcell 25Pcs M10 Nylon Flat Washers Plain Washer 10mm ID 30mm OD 2mm Thick Plastic Washers](https://www.amazon.com/uxcell-Washers-Washer-Plastic-Plumbing/dp/B0F1866XB9/ref=sr_1_6?crid=D7TA55NTUPB2&dib=eyJ2IjoiMSJ9.E4peaiHlvUqwkIQZe9oUDEIo6XNfoY2zX8ClIUL0EfRXNAc_fh-UBrXHTdobxFx8UyVgR3lDDLA3dZtv_kb5ZjWZWzbdlaPN_908DT4MgaUmr2X3j3GhfYomMX7eaetQ2Jlxb_NNiatXfpnNMPe49pYDOyJicS4Qss-Guun5xJtrUfiuKw5YD0HfPddwYoUc-F6o1ROO7-dRV_v5FEyRifyp5NFtsLKaoY17kapM7ekJxR6y33gd-KpW9IoEf2olT4bvmETzXNJK1H66cqPVeKuwUmIhydYWVnw4XvZ21F4.JhILD7gJJwecVn5rQwg1O3_5s3Tx7dsRrHov-GOek5E&dib_tag=se&keywords=flat%2Bfender%2Bwasher%2Bnylon%2Bm10&qid=1757287075&s=hi&sprefix=flat%2Bfender%2Bwasher%2Bnylon%2Bm10%2Ctools%2C183&sr=1-6&th=1)

## PCB Parts Required
- **Terminal Block 1x2 15A 5mm**: [Wurth Elektronik 1x2 Terminal Block | Mouser](https://www.mouser.com/ProductDetail/Wurth-Elektronik/691502710002?qs=sGAEpiMZZMvPvGwLNS671%2FDg%252BJKjyQe9HQWNyrv5eM87b8L0XSU4yA%3D%3D)
- **Terminal Block 1x3 15A 5mm  for 3 way switch wires**: [Wurth Elektronik 1x3 Terminal Block 691502710003 | Mouser](https://mou.sr/3W2Yn7l)
- **Schottky Diode**: [1N5820G Onsemi | Mouser](https://www.mouser.com/ProductDetail/onsemi/1N5820G?qs=y2kkmE52mdMaZomtu%252BD%252BfQ%3D%3D)
- **Glass Fuse Holder**: [Schurter 3-132-874 Fuse Holder | Mouser](https://mou.sr/4q52jSB)
- **15A Glass Fuse**: [Little Fuse 15A Glass Fuse 0217015.MXP | Mouser](https://www.mouser.com/ProductDetail/Littelfuse/0217015.MXP?qs=OiFqjYYehYgwRsNUxmXanQ%3D%3D)
- **1A PTC Fuse**: [Yageo BK60-050-DI 1Amp PTC Fuse | Mouser](https://www.mouser.com/ProductDetail/YAGEO/BK60-050-DI?qs=PzGy0jfpSMs7oE%252BTaoZ9Mw%3D%3D)
- **Arduino Nano 15 Pin Female Header**: [SparkFun PRT-16279 | Mouser](https://www.mouser.com/ProductDetail/SparkFun/PRT-16279?qs=vmHwEFxEFR8I6W1vfufYPg%3D%3D)
- **10K Pull Down Resistor**: [Yageo MFR-25JR-52-10K 1/4 W 5% | Mouser](https://www.mouser.com/ProductDetail/YAGEO/MFR-25JR-52-10K?qs=xZ%2FP%252Ba9zWqbHBnqxPK2f8Q%3D%3D) or [Amazon](https://www.amazon.com/E-Projects-10EP51410K0-10k-Resistors-Pack/dp/B00CVZ4DKU?th=1)
- **Wire Ferrule Crimping Kit**: []()
- **Stand-offs + Screw kit for PCB's**: []()
- ** **: []()








## Block Diagram
- We are getting power from the 12v - 15v CAT Skidsteer battery, or from the ignition key. Assume battery for now. We need an inline fuse 15A?. We also need to determine the wire guage, and if we are using some kind of connector or just soldering directly to the PCB.
- We also need a master switch to turn off power to everything when not in use, or use the ignition key
- We need to run 12v power to
  - Backup camera system
  - Voltage regualtor 12v -> 7v for arduino nano
  - Motor Controller
  - 3v -> 12v Relay for channel changing
- The Arduino nano needs to connect to
  - **Motor Controller (Cytron MD10C)**:
    - DIR (digital output for direction): Use **D8** HIGH/LOW toggle
    - PWM (PWM output for speed): Use **D9** PWM-capable for easing/ramping
    - GND: Connect to any Nano GND pin
  
  - **Relay**:
    - VCC: Connect to Nano 3V3 pin
    - IN (digital output to trigger): Use **D7** HIGH/LOW to activate (active LOW common)
    - GND: Connect to Nano GND
  
  - **Switch (SPDT 3-way)**:
    - Common (center): To Nano 3V3 pin
    - Position 1 (extend/up): To **D6** with 10k pull-down.
    - Position 2 (retract/down): To **D5** with 10k pull-down.
