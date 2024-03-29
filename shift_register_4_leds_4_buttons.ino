/*
SparkFun Inventor's Kit
Example sketch 13
Adjusted by: Germán Carrillo [gcarrillo@linuxmail.org]

SHIFT REGISTER

  Use a shift register to turn three pins into eight (or more!)
  outputs

  An integrated circuit ("IC"), or "chip", is a self-contained
  circuit built into a small plastic package. (If you look closely
  at your Arduino board you'll see a number of ICs.) There are
  thousands of different types of ICs available that you can use
  to perform many useful functions.

  The 74HC595 shift register in your kit is an IC that has eight
  digital outputs. To use these outputs, we'll use a new interface
  called SPI (Serial Peripheral Interface). It's like the TX and 
  RX you're used to, but has an additional "clock" line that 
  controls the speed of the data transfer. Many parts use SPI
  for communications, so the Arduino offers simple commands called
  shiftIn() and shiftOut() to access these parts.

  This IC lets you use three digital pins on your Arduino to
  control eight digital outputs on the chip. And if you need 
  even more outputs, you can daisy-chain multiple shift registers
  together, allowing an almost unlimited number of outputs from 
  the same three Arduino pins! See the shift register datasheet
  for details:
  
  http://www.sparkfun.com/datasheets/IC/SN74HC595.pdf

Hardware connections:

  Shift register:
  
    Plug in the chip so it bridges the center "canyon"
    on the breadboard.
    
    The shift register has 16 pins. They are numbered
    counterclockwise starting at the pin 1 mark (notch
    in the end of the chip). See the datasheet above
    for a diagram.

    74HC595 pin		LED pin		Arduino pin
    
    1  (QB)		LED 2 +
    2  (QC)		LED 3 +
    3  (QD)		LED 4 +
    4  (QE)		LED 5 +
    5  (QF)		LED 6 +
    6  (QG)		LED 7 +
    7  (QH)		LED 8 +
    8  (GND)				GND
    
    9  (QH*)
    10 (SRCLR*)				5V
    11 (SRCLK)				Digital 3
    12 (RCLK)				Digital 4
    13 (OE*)				GND
    14 (SER)				Digital 2
    15 (QA)		LED 1 +
    16 (VCC)				5V
  
  LEDs:
  
    After making the above connections to the positive (longer)
    legs of the LEDs, connect the negative side (short lead) of
    each LED to a 330 Ohm resistor, and connect the other side
    of each resistor to GND.
  
This sketch was written by SparkFun Electronics,
with lots of help from the Arduino community.
This code is completely free for any use.
Visit http://learn.sparkfun.com/products/2 for SIK information.
Visit http://www.arduino.cc to learn about the Arduino.

Version 2.0 6/2012 MDG
*/


// Pin definitions:
// The 74HC595 uses a type of serial connection called SPI
// (Serial Peripheral Interface) that requires three pins:

const int datapin = 12;
const int clockpin = 7;
const int latchpin = 8;
const int inputpin = 2;

// We'll also declare a global variable for the data we're
// sending to the shift register:
byte data = 0;


void setup()
{
  // Set the three SPI pins to be outputs:
  pinMode(datapin, OUTPUT);
  pinMode(clockpin, OUTPUT);  
  pinMode(latchpin, OUTPUT);

  pinMode(inputpin, INPUT);
  Serial.begin(9600);
  Serial.println("Set up!...");

  //allHigh(); // Use this for first tests
  setAllLEDs(HIGH); // Just to let users know the control starts receiving...
  delay(500);
  initializeLEDsAndButtons();
}


void loop()
{
  if (digitalRead(inputpin) == HIGH){
    //Serial.println("HIGH");
    lightLED(getLEDfromButton(getPressedButton()));
    delay(500);
  }
}


void shiftWrite(int desiredPin, boolean desiredState)

// This function lets you make the shift register outputs
// HIGH or LOW in exactly the same way that you use digitalWrite().

// Like digitalWrite(), this function takes two parameters:

//    "desiredPin" is the shift register output pin
//    you want to affect (0-7)

//    "desiredState" is whether you want that output
//    to be HIGH or LOW

// Inside the Arduino, numbers are stored as arrays of "bits",
// each of which is a single 1 or 0 value. Because a "byte" type
// is also eight bits, we'll use a byte (which we named "data"
// at the top of this sketch) to send data to the shift register.
// If a bit in the byte is "1", the output will be HIGH. If the bit
// is "0", the output will be LOW.

// To turn the individual bits in "data" on and off, we'll use
// a new Arduino commands called bitWrite(), which can make
// individual bits in a number 1 or 0.
{
  // First we'll alter the global variable "data", changing the
  // desired bit to 1 or 0:

  bitWrite(data, desiredPin, desiredState);
  
  // Now we'll actually send that data to the shift register.
  // The shiftOut() function does all the hard work of
  // manipulating the data and clock pins to move the data
  // into the shift register:

  //Serial.println(data);
  shiftOut(datapin, clockpin, MSBFIRST, data);
  //Serial.println(data);

  // Once the data is in the shift register, we still need to
  // make it appear at the outputs. We'll toggle the state of
  // the latchPin, which will signal the shift register to "latch"
  // the data to the outputs. (Latch activates on the high-to
  // -low transition).

  digitalWrite(latchpin, HIGH);
  digitalWrite(latchpin, LOW);
}


void allHigh(){
  for(int index = 0; index <= 7; index++)
  {
    shiftWrite(index, HIGH);
  }
}

void setAllLEDs(boolean state){
  for (int index = 0; index < 4; index++)
    shiftWrite(index, state);
}

void setAllButtons(boolean state){
  for (int index = 4; index < 8; index++)
    shiftWrite(index, state);
}

void initializeLEDsAndButtons(){
  setAllLEDs(LOW);
  setAllButtons(HIGH);
}

int getLEDfromButton(int buttonIndex){
  int ledIndex = -1;
  if (buttonIndex != -1) {
    ledIndex = buttonIndex - 4;
  } 
  return ledIndex;
}

int getPressedButton(){
  int buttonIndex = -1;
  setAllButtons(LOW);
  
  for(int j=4; j<8; j++){
    shiftWrite(j, HIGH);
    delayMicroseconds(500);

    if(digitalRead(inputpin) == HIGH){
        buttonIndex = j;
        break;
    }

    shiftWrite(j, LOW);  // Prepare for the next iteration
  }

  setAllButtons(HIGH);
  return buttonIndex;
}

void lightLED(int index){
  if (index != -1){
    setAllLEDs(LOW); // First, turn all LEDs off
    shiftWrite(index, HIGH);
    Serial.print("LED on: ");
    Serial.println(index);
  }
  else {
    Serial.print("LED index is -1, don't do anything...");
  }
}
