/*
   Use an Ultrasonic distance sensor, part 2

   The HC-SR04 Ultrasonic sensor has a trigger pin and an echo pin.
   Sending a signal to the trigger pin causes an ultrasonic
   sound to be broadcast. We can detect how long it takes for the echo
   to be heard and calculate the distance using the speed of sound.

   This lesson adds a dimmable LED controlled by the distance sensor.
*/
int echoPin = 7; // Listen for an echo on this pin
int triggerPin = 8; // Generate an ultrasonic sound with this pin

long duration, distance;

// NEW CODE HERE TO CONTROL LED

// Add an array of LEDS
int ledPins[] = {2, 3, 4, 5, 6};

//Say how many LEDs there are
int ledCount = 5;

// Initialize LED brightness
int brightness = 0;

void setup() {
  // Use Serial to communicate from the Arduino.
  Serial.begin(9600);

  // Specify trigger and echo pins.
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);

  //Setup our array to be outputs
  //The for loops cycles through all the pins and sets them to outputs
  for (int currentPin = 0; currentPin < ledCount; currentPin++) {
    pinMode(ledPins[currentPin], OUTPUT);
    digitalWrite(ledPins[currentPin], LOW);
  }  
  
}

void loop() {
  // Send a reset signal to the trigger pin.
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);

  // Generate an ultrasonic sound for 10 microseconds.
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);

  // pulseIn measures the length of time (in microseconds) that
  // it takes for the echo to be heard.
  duration = pulseIn(echoPin, HIGH);

  /*
      Calculate the distance (in cm) based on the speed of sound.
      In air, sound travels 340 m/s = 34,000 cm/s = 0.034 cm/microsecond

      Elapsed time is for a round trip, so divide by 2:
      0.034 cm/microsecond / 2 = 0.017 cm/microsecond
  */
  distance = duration * 0.017;

  // Print the distance to the serial port
  Serial.println(distance);

  // Wait 50 milliseconds to not overload the monitor
  delay(50);

  /*
      Run this sketch and select the "Serial Monitor" from the Tools menu.
      You should now be getting information from the Arduino!
  */
  // Limit the distance to between 0 and 50 cm.
  distance = constrain(distance, 0, 50);

  //Map the distance to our LED array
  int ledToLight = map(distance,0,50,0,ledCount);
  //Turn the LED on if its in range
  digitalWrite(ledPins[ledToLight],HIGH);
  //After a second turn the LED back off
  delay(1000);
  digitalWrite(ledPins[ledToLight],LOW);
  
  
}
