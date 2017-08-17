# Lesson 1 - Arduino

### Requirements for this Lesson:
- **Arduino**
- **USB Connector**
- **Computer (Mac or PC)**


![Arduino Board](https://cdn.sparkfun.com/assets/9/1/e/4/8/515b4656ce395f8a38000000.png "Arduino")

Arduino is an open-source electronics platform based on easy-to-use hardware and software. It's intended for anyone making interactive projects.

  - Low cost scientific instruments
  - Robotics
  - Interactive prototypes
  - New musical instruments
  - Cool, fun inventions!

# Making Stuff with Arduino

  - [Smart Doorbell](https://create.arduino.cc/projecthub/KaustubhAgarwal/smart-doorbell-364e28)
  - [Arduino Lie Detector](https://create.arduino.cc/projecthub/BuildItDR/arduino-lie-detector-a0b914)
  - [Self Playing Chessboard](https://create.arduino.cc/projecthub/Maxchess/wooden-chess-board-with-piece-recognition-872ffb)
  - [Guitar Pedal](https://create.arduino.cc/projecthub/electrosmash/arduino-uno-guitar-pedal-b2ba96)
  - [Hydroponic Farm](http://www.instructables.com/id/Hyduino-Automated-Hydroponics-with-an-Arduino/)
  - [Internet Radio](http://www.instructables.com/id/Arduino-Raspberry-Pi-Internet-Radio/)


What made Arduino Popular?
  - Easy to use
  - Flexible for Advanced Users
  - Works with almost anything

# What do you want to invent?
[![IMAGE ALT TEXT HERE](http://img.youtube.com/vi/Ki7lqI6XE2s/0.jpg)](http://www.youtube.com/watch?v=Ki7lqI6XE2s)

> I put a robot arm and a toothbrush on a skateboard helmet and programmed it to brush my teeth. No more poor dental hygiene! My gums now hurt. 
Get the full tutorial: http://www.instructables.com/id/Toothbrush-machine/

# What can an Arduino Do?

Arduino can read **inputs**:
- Light on a Sensor
- a finger on a button
- a twitter message

![Ultrasonic Sensor](http://2.bp.blogspot.com/-obrSglWftE0/VfC-rfx5rxI/AAAAAAAAArs/yZ-nohsvXto/s1600/TE114-03.jpg "Ultrasonic Sensor")

And turn them into an **output**:
- activating a motor
- turning on an LED
- publishing something online

![LED](https://ktechnics.com/wp-content/uploads/2016/02/LED_blink.gif "LED")

# How does an Arduino Work?
![arduinIO]( "arduinIO")
An Arduino has many components:
- A USB Input, this is used to talk to the Arduino from a computer to load code or send Serial Data
- Input/Output Pins, these pins are used to send and recieve signals from sensors and other devices, such as the examples above.
- The Arduino also has 5v and 3.5v power outputs that are passed through from the USB cable or a dedicated power supply. You also need a ground to complete every circuit
# How does a Circuit Work?
![circuit]( "circuit")
A circuit is an electrical system that starts and ends in the same place, while accomplishing a goal. In the above example power flows from the power supply out of the positive terminal, along some wires into the load. The load can be whatever you want, an LED, a sensor, a Noise maker. Once it travels through the load it flows back into the negative side of the power supply, commonly refered to as the ground. The circuit is now complete! Every circuit has a start and end at the same place, on an Arduino it is often the 5v and Ground pins.
# How do LEDs Work?
![leds]( "leds")
LEDs or **L**ight **E**mmitting **D**iodes are lights that are super effiencent with power. Building off of our circuit, an LED has an Anode, positive end, and a Cathode, negative end. This allows you to know the orientation an LED needs to be in your circuit. The Anode is longer than the Cathode allowing you to visually tell the difference between them. Between the Anode and the Cathode there is a Semi Conductor, which is what produces the light. Inside the Semi Conductor electrons from the circuit pass through small holes which produce light, know as photons, and then leave through the Cathode. 
# How do Resistors Work?
![resistors]( "resistors")
A resistor limits the electrical current that flows through a circuit, they are often put in circuits to protect components from damage. We use them to protect our LEDs. Resistors work by taking the electrons flowing through them and turning their energy into heat instead of allowing them to flow through the circuit. The heat then disapates into the air. By converting their energy to heat less power is allowed through the circuit. It can also be described as a Resistor *resists* the power flowing through it.
# What is a breadboard?
![breadboard]( "breadboard")
Breadboards are great for prototyping as they require no soldering. They consist of a bunch of small pins with terminal strips running horizontal on each side. On the outside they have two sets of power rails for brining power anywhere. Using jumper wires and an arduino you can easily prototype inventions using breadboards. 
# How do you program an Arduino?
![arduinoIDE]( "arduinoIDE")
Arduinos are programmed with the Arduino IDE which you can find at https://www.arduino.cc/en/Main/Software They offer an web and downloadable version, I prefer the downloadable version.
To setup your Arduino you must first install the Arduino IDE, allowing all of the drivers to install.
The first time you open the Arduino IDE you will have a script that looks like this:
```java
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
```
By reading the comments made with `//`, you can get an idea of what each function does. A function is defined with `void`. A function is a container of code that you can run at certain times. Arduino has a few prebuilt functions, `setup()` which runs once right as your program starts. This is a good place to initalize anything you want to use later, `loop()` runs as fast as possible, as soon as it finishes running once it starts again. This is useful for controlling outputs or recieving inputs. You can also make your own functions like this:
```java
void helloWorld() {
    print("Hello World!");
}
```
And you can run them by putting them in one of Arduinos prebuilt functions:
```java
void setup() {
    helloWorld();
}
```
Your program would then look like this:
```java
void setup() {
    helloWorld();
}

void loop(){
}

void helloWorld() {
    print("Hello World!");
}
```
If you had an Arduino connected and ran this it would output `Hello World` in the output section of the IDE. So lets connect an Arduino!
![connectingArduino]( "connectingArduino")
To connect an Arduino you need to plug your Arduino into your computer using the cable that comes with it. Newer Arduinos have different connectors than the old ones so mine may look different to yours, but they will function the same.
![arduinoToolbar]( "arduinoToolbar")
We know need to go to the tools tab in the toolbar and go to `Tools -> Board -> Name of your Board` in my case I would select `Arduino/Genuino Uno`. You may have a different board and will need to select the correct one.
We also need to set the port in the tools tab by going to `Tools -> Port -> Port with Arduino` this will be different for everyone so you just want to find the port that says Arduino. On Mac and PC ports have different names. In my case its `COM3 (Arduino Uno)`.
Our Arduino is now connected and ready to go! If you click the Upload button at the top toolbar you should see it start to upload your script and then see `Hello World` in the bottom ouput!

Lets make a actual Arduino program now. Lets delete all the extra stuff we made in our script so it looks like:
```java
void setup(){

}

void loop(){

}
```
We are going to write a program that makes the onboard LED blink on an off. To do this we need to setup our output pin in the setup function
```java
void setup(){
    pinMode(LED_BUILTIN, OUTPUT);
}
```
What this does is allows use to use the pin associated with the Built in LED as an Output. `pinMode(arg1, arg2)` is the name of the function, this function allows you to assign the mode for indidual pins. `arg1` is the pin that we are using, in this case the built in LED or `LED_BUILTIN`, this could also be just `13` if you wanted to use pin 13. In a later tutorial we will use variables for storing pins. `arg2` is the mode we want to set the pin to, either `INPUT` or `OUTPUT`.

Now that the LED is setup we need to tell it what to do, we do this in the loop function:
```java
void loop(){
    digitalWrite(LED_BUILTIN, HIGH);
}
```
What that does is it sets the Built in LED to have a High Output, or ON. `digitalWrite(arg1, arg2)` is the function, this function allows you to digitally write the output of a pin. `arg1` is the pin that we are using, in this case the built in LED. `arg2` is the output we want to send to the pin. In a digital write you can send `HIGH`, on, or `LOW`, off. If you run your program you should see the onboard LED turn on.

Lets make the LED blink!
Add this to the bottom of your loop function:
```java
delay(1000);
digitalWrite(LED_BUILTIN, LOW);
delay(1000);
```
What this does is delays the program for one second then sets the onboard led to off and delays the program again. When you run this your LED should blink. `delay(arg1)` is a function that allows you to pause or *delay* your program. `arg1` is the number of milliseconds you want your program to wait before continuing. `1000ms = 1s`. We have two delays so that it stays on or off for a second and then because loop loops, we go back to the top and turn it back on. Your finished script should look like this:
```java
void setup(){
    pinMode(LED_BUILTIN, OUTPUT);
}

void loop(){
    digitalWrite(LED_BUILTIN, HIGH);
    delay(1000);
    digitalWrite(LED_BUILTIN, LOW);
    delay(1000);
}
```
Congrats! You have just written your first Arduino script! Blink is often refered to as the Hello World of Arduinos.

# Summary
This is the end of the introduction for Arduinos! You should now have a basic understanding of how an Arduino works and have a working sample project. In the next lesson we will go over connecting a ultrasonic sensor to the Arduino.

