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

// Add an LED
int ledPin = 10;

// Initialize LED brightness
int brightness = 0;

void setup() {
  // Use Serial to communicate from the Arduino.
  Serial.begin(9600);

  // Specify trigger and echo pins.
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
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

  // NEW SECTION

  // Limit the distance to between 0 and 200 cm.
  distance = constrain(distance, 0, 200);

  /*
      Convert the distance into brightness values.

      The map function takes one set of values and converts it to another
      new_value = map(input, oldMin, oldMax, newMin, newMax);

      Map distances from 0 to 200 cm to brightness from 255 to 0.
      This makes the LED brightest when you are close and dims it
      when the distance is greater.
  */
  brightness = map(distance, 0, 200, 255, 0);

  // Write the brightness value to the LED.
  analogWrite(ledPin, brightness);

  // Print the brightness to the Serial port.
  Serial.println(brightness);
}
