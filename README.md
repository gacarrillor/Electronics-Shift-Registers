# Shift Registers
Controlling (mixing) inputs (push buttons) and outputs (LEDs) with the [74HC595 IC](https://www.sparkfun.com/products/13699).

Work inspired by and adapted from Kevin Darrah's video on [How to Control a Ton of Inputs using Shift Registers!](https://www.youtube.com/watch?v=nXl4fb_LbcI). My objective is to optimize my [Soccer Penalty Kicks Game](https://www.instructables.com/Soccer-Penalty-Kicks-Game-with-Wiring-and-Arduino/)'s control, which is currently working with 2 analog input reads based on resistors, controlling 12push buttons, which, as mentioned by Kevin in his video, becomes problematic at the end of the day when having a number of inputs.

Note: In the video, Kevin shared and explained his great idea as well as [his code](https://www.kevindarrah.com/download/arduino_code/ShiftRegisterInput.ino). However, schematics/diagrams are missing, what makes the process a bit difficult to follow. In case you're wondering, this image describes the main idea:

<img src="https://github.com/gacarrillor/Electronics-Shift-Registers/assets/652785/9ae2538f-0210-444e-b8b4-14f11b8adcb0" alt="Your image title" width="400"/>


## Cases

### One shift register (74HC595): 4 inputs and 4 outputs

<img src="https://github.com/gacarrillor/Electronics-Shift-Registers/assets/652785/c522826b-fd48-4948-9b5e-9921347384a8" alt="Your image title" width="500"/>


### Two daisy-chained shift registers (74HC595): 8 inputs and 8 outputs

<img src="https://github.com/gacarrillor/Electronics-Shift-Registers/assets/652785/c3457c34-26d9-42be-b753-b48894bb3aa0" alt="Your image title" width="500"/>

<img src="https://github.com/gacarrillor/Electronics-Shift-Registers/assets/652785/8a252741-a067-402a-a59d-5de4b957d166" alt="Your image title" width="500"/>

<img src="https://github.com/gacarrillor/Electronics-Shift-Registers/assets/652785/aca5a24f-033f-4e0b-aecb-f34b3cbb06f0" alt="Your image title" width="500"/>



### Three daisy-chained shift registers (74HC595): 12 inputs and 11 outputs

This is what I actually need for my game: One of the buttons triggers another action and is not connected to any LED, that's why the odd numbers :).

<img src="https://github.com/gacarrillor/Electronics-Shift-Registers/blob/main/3_shift_registers_11_outputs_12_inputs.png" alt="Schematics 3 Shift Registers" width="500"/>


#### Parts

|Amount|Part|
|------|----|
|11| 	Red LED|
|11| 	330Ω Resistor|
|12| 	Push button|
|12| 	Diode 1N4001|
|1| 	10kΩ Resistor|
|3| 	Ceramic capacitor 1µF|
|1| 	Electrolytic capacitor 100µF|
|3| 	74HC595 Shift Register|
|1| 	Arduino Uno (Rev3) - ICSP|


<img src="https://github.com/gacarrillor/Electronics-Shift-Registers/assets/652785/d19776f3-6b49-4ef8-9bc6-fee696b08e89" alt="Your image title" width="500"/>
