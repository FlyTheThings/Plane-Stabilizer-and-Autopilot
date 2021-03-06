# Plane-Stabilizer-and-Autopilot

## General desciption

This is an automatic stabilizing and auto-piloting system designed to be run in my [FPV49](http://fpv.no/vbulletin/showthread.php/2390-FPV49-Scratch-built-FPV-KFm-Airfoil#2) RC flying wing.

It is written for the Arduino Uno/Nano R3 platform (Atmel 328p) and uses quite a few different sensoric units detailled in the next paragraph.

The system is thought to have the following five major modes:

1. **Full Manual** mode  
 All channel information is passed through from the RC receiver to the servos without any modification. In this mode the system is only used to do the Elevon mixing.

2. **Attitude holding** mode  
 If the transmitter sticks are released to neutral position by the pilot, the stabilizing system is manipulating channel pass through in such a manner that the plane stays in its current attitude.  
 The behavior in this mode is comparable to what you'd expect from flying a quadcopter in Acro mode, meaning that the stick position on the transmitter controls the angular velocity (speed of rotation) of the plane.

3. **Self-leveling** mode  
 In this mode the position of the transmitter sticks controls the absolute attitude of the plane (so to speak the "tilting" of the plane).  
 If the sticks are let go to plane will return to a leveled position automatically.

4. **Heading lock** mode  
 If heading lock mode is being engaged the planes current heading is read from the compass and/or GPS.  
 The control surfaces of the plane are then used to keep the plane heading in a constant direction.  
 Relative height over the launch site is kept constant in this mode as well.

5. **Auto-piloting** mode  
 Auto-piloting will mainly be used as a safety feature.
 When in Auto-piloting mode - either user selected or triggered by failsafe - the plane will return to the GPS coordinates of the launching site (RTH), where it will then loiter in a safe height. If the radio link is not regained after a certain time period, the plane will attempt an automatic landing procedure.

## Sensors currently in use


* InvenSense **ITG3200** 3-axis gyroscope to measure _angular velocity_  
* Analog Devices **ADXL345** 3-axis accelerometer to measure the _orientation of the Earth's gravitational field_  
* Honeywell **HMC5883L** 3-axis magnetometer to measure the _orientation of the Earth's magnetic field_  
* Bosch Sensortec **BMP180** barometric pressure sensor to measure _relative height_

Soon to be followed by:
* u-blox GPS module


## Software functions currently implemented

TBA

## Fusion of IMU data

To provide an attitude estimation as precise as possible the data of several sensors needs to be filtered and fused.

I will be explaining this process in depth later on but if you are interested, have a look at OlliW's article [on his private blog](http://www.olliw.eu/2013/imu-data-fusing/) on this topic, which was a great help to me.  
While the above article does a great job at explaining the theories mathematically, I want to thank [Kris Winer on GitHub](https://github.com/kriswiner) for providing and explaining the code implementation of the open source
Madgwick & Mahony filter algorithms in such depth.


## External library dependencies

[BMP180 library by Sparkfun](https://learn.sparkfun.com/tutorials/bmp180-barometric-pressure-sensor-hookup-/installing-the-arduino-library)  
[GY-85 library by sqrtmo on GitHub](https://github.com/sqrtmo/GY-85-arduino)
