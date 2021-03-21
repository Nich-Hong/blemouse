# blemouse
The first attempt with a SparkFun Pro Micro was a failure. The serial port got messed up and the device is no longer recognized on my laptop.

Now that I have an Arduino Leonardo, I have set up all the wiring on a breadboard for prototyping. I made sure of some small key details with making the mouse about how
smooth everything works. I will attempt to use an Arduino Nano IoT as the peripheral device that sends out information. 

I have been thinking about this but why would I even need the Leonardo if I could use the Nano IoT as the peripheral and using some python driver to read its data that is sent. 

update: 
BLE keyboard works when using python driver on RaspberryPi Zero. 
Mouse works by using perpheral Arduino IoT to receive the command and then move the cursor.
There is a serious delay on the cursor though. 
