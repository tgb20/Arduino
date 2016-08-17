//To Setup a Project for Arduino we need to declare pins
//These tell the program what to control on the arduino
//We are going to control an LED on Pin 9
//The pins on Arduinos are reprensented as Int or Integers
int pin = 9;



void setup() {
  //The setup function only runs once
  //This is where we "setup our project"
  //We need to tell the arduino that we are going to send data OUT of our pin
  pinMode(pin,OUTPUT);
  //We have completed the basic setup for our project
  //But if you run it now nothing will happen
}

void loop() {
  //The loop function is where you say what you want to happen
  //It runs as long as the arduino is on, constantly looping

  //Lets turn on our LED
  digitalWrite(pin,HIGH);
  //You now know the basics to controlling LEDS with an Arduino
}
