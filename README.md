# Shift Registers
Controlling (mixing) inputs (push buttons) and outputs (LEDs) with the [74HC595 IC](https://www.sparkfun.com/products/13699).

## Contents

 + [Background](#background)
 + [Main goal](#main-goal)
 + [Cases](#cases)
   + [One shift register (74HC595): 4 inputs and 4 outputs](#one-shift-register-74hc595-4-inputs-and-4-outputs)
   + [Two daisy-chained shift registers (74HC595): 8 inputs and 8 outputs](#two-daisy-chained-shift-registers-74hc595-8-inputs-and-8-outputs)
   + [Three daisy-chained shift registers (74HC595): 12 inputs and 11 outputs](#three-daisy-chained-shift-registers-74hc595-12-inputs-and-11-outputs)
 + [Results](#results)

------------------

## Background 

Work inspired by and adapted from Kevin Darrah's video on [How to Control a Ton of Inputs using Shift Registers!](https://www.youtube.com/watch?v=nXl4fb_LbcI). Note: In the video, Kevin shared and explained his great idea as well as [his code](https://www.kevindarrah.com/download/arduino_code/ShiftRegisterInput.ino). However, schematics/diagrams are missing, what makes the process a bit difficult to follow. In case you're wondering, this image describes the main idea:

<img src="https://github.com/gacarrillor/Electronics-Shift-Registers/assets/652785/9ae2538f-0210-444e-b8b4-14f11b8adcb0" alt="Your image title" width="400"/>

## Main goal

My goal is to optimize my [Soccer Penalty Kicks Game](https://www.instructables.com/Soccer-Penalty-Kicks-Game-with-Wiring-and-Arduino/)'s control, which is currently working with 2 analog input reads based on resistors, controlling 12 push buttons, which, as mentioned by Kevin in his video, becomes problematic at the end of the day when having a number of inputs.

While Kevin's work handles multiple buttons (like a piano), my control has only one active button, so in the code, as soon as I identify a button press, I exit the button inspection and only light one LED.

![IMG_7026](https://github.com/gacarrillor/Electronics-Shift-Registers/assets/652785/8a241059-a350-4cc9-b9f0-6ff8b9767f86)


## Cases

### One shift register (74HC595): 4 inputs and 4 outputs

<img src="https://github.com/gacarrillor/Electronics-Shift-Registers/blob/main/1_shift_register_4_outputs_4_inputs.png" alt="Schematics 1 Shift Register" width="500"/>

See the [source code](https://github.com/gacarrillor/Electronics-Shift-Registers/blob/main/shift_register_4_leds_4_buttons.ino).

<img src="https://github.com/gacarrillor/Electronics-Shift-Registers/assets/652785/c522826b-fd48-4948-9b5e-9921347384a8" alt="Your image title" width="500"/>


### Two daisy-chained shift registers (74HC595): 8 inputs and 8 outputs

<img src="https://github.com/gacarrillor/Electronics-Shift-Registers/blob/main/2_shift_registers_8_outputs_8_inputs_bb.png" alt="Schematics 2 Shift Registers" width="500"/>

See the [source code](https://github.com/gacarrillor/Electronics-Shift-Registers/blob/main/shift_register_8_leds_8_buttons.ino).

<img src="https://github.com/gacarrillor/Electronics-Shift-Registers/assets/652785/c3457c34-26d9-42be-b753-b48894bb3aa0" alt="Your image title" width="500"/>

<img src="https://github.com/gacarrillor/Electronics-Shift-Registers/assets/652785/8a252741-a067-402a-a59d-5de4b957d166" alt="Your image title" width="500"/>

<img src="https://github.com/gacarrillor/Electronics-Shift-Registers/assets/652785/aca5a24f-033f-4e0b-aecb-f34b3cbb06f0" alt="Your image title" width="500"/>


### Three daisy-chained shift registers (74HC595): 12 inputs and 11 outputs

This is what I actually needed for my game. One of the buttons triggers another action and is not connected to any LED, that's why the odd numbers :).

<img src="https://github.com/gacarrillor/Electronics-Shift-Registers/blob/main/3_shift_registers_11_outputs_12_inputs.png" alt="Schematics 3 Shift Registers" width="500"/>

See the [source code](https://github.com/gacarrillor/Electronics-Shift-Registers/blob/main/shift_register_11_leds_12_buttons.ino).

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

https://github.com/gacarrillor/Electronics-Shift-Registers/assets/652785/1fe15331-b975-4ab1-942a-39332b134802

<img src="https://github.com/gacarrillor/Electronics-Shift-Registers/assets/652785/d19776f3-6b49-4ef8-9bc6-fee696b08e89" alt="Your image title" width="500"/>

## Results

This is how the control looks ike after implementing Kevin's approach.

https://github.com/gacarrillor/Electronics-Shift-Registers/assets/652785/59fbbcac-5293-48e1-9c76-79c388ee1b08

