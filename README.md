# SkidsteerCameraStick


## Problems to solve
* I can't see over tall walls while driving our 3 skidsteers (CAT 242, 262, 299). Backfilling walls is 50% of my job, I need a guy behind the wall spotting me, telling me where to dump and how much.
* Waiting for other people to tell me where to dump and how much is super annoying. Everyone has different hand signals which is frustrating.
* The backup cameras on our skidsteers are garbage (242 doesnt even have one). They are easily washed out by bright sunglight, cloudy days, or shadows.
* The backup camera display is too small.

## Solution
Mount an Electric Linear Actuator on the arm of the skidsteer. The linear actuator pushes / rotates an 8ft long stick (Probably length adjustable for different tractors) with a camera maybe insta360 or possibly 2 cheap arduino compatable wide angle cameras pointing foward and back. When the actuator is in the fully retracted position, it acts as a wide angle backup camera looking towards the rear of the tractor. When the actuator is extended it acts as a forward and down facing camera to look over walls. We need a display inside the tractor that shows both camera feeds. If we use an insta360, I can just use my phone as a display, but we will need to run a usb-C cable up the pole to charge the camera.

The whole setup will be powered by the 12v battery on the CAT Skidsteer inside the engine compartment. I will have an arduino (nano? or some kind of esp32?) inside the cabin of the tractor (so it stays clean, dry and cool in AC). I will have a controll panel inside the cabin mounted to the wall infront of me. To keep things simple, all I need are 2 buttons, or maybe even 1, maybe a switch, TBD. All I need it to do is extend out for maybe 4 seconds, then hold its position until I dump the dirt, then press another button to fully retract.

There is a chance we could add a potentiometer to the controll panel to adjust how far the linear actuator extends. Like for example the "Deluxe Rod Actuator" from Firgelli extends 3 inches per second. So we could basically alter the length of time we extend the actuator depending on our needs. Or possibly setup a limit switch once its reached its desired extension.

The goal is to have a stupid simple automatic setup. I pick up dirt, drive to the wall, press a button, the camera stick extends within 6 seconds, I lift the bucket up, look over the wall using the monitor, dump the load, then press a button to retract the camera stick and drive to get another load of dirt. 

The setups i've seen fron Firgelli wont work. I think I'm going to need a micro controller. They have momentary rocker switches that can controll the actuator, but they require the user to hold the switch until it reaches the desired position. 




# Requirements
* The 8ft camera pole needs to be steady when fully retracted or extended. If the pole is wabbling and the camera feed is blurry, its no good.
* Need a master switch to completely kill all power draw when not in use. It needs to be inside the cabin on the controll panel, or we could use a relay tied to the skidsteer's ignition (e.g., powered only when the key is on), but a manual switch is simplest and avoids any extra idle draw from the relay coil.
* All the power needs to come from the 12v battery on the CAT skidsteer. Need a Fuse (10A - 15A) at the battery to protect the whole setup.
* Need a usb-C charge cable on the 8ft pole for an insta360 camera
* All the electronics need to be waterproof, heat resistant. Mounting all the electronics inside the cabin will keep them cool & dry.
* The camera stick needs to reach the fully extended position within 6 seconds. Most Firgelli actuators are quite slow. The "Deluxe Rod Actuator" from Firgelli extends 3 inches per second and has a 100lb limit. The 18 inch version can fully extend in 6 seconds.
* I need a button, or buttons, to extend the actuator to a specified length, then fully retract. The button or buttons need to do this with a single "click", I dont want to have to hold the button down. It needs to be automatic.
* In the retracted position, I want to use it as a backup camera.
* If we dont use an insta360 connected to my phone wirelessly, we will need 2 cameras, one facing backwards, and one facing forwards on the end of the 8ft pole, and we need a moniter to view both cameras. I dont know if wired or wireless is better.
