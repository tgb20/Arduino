//Array of LEDS

// Add an array of LEDS
int ledPins[] = {2, 3, 4, 5, 6};

//We need to save the amount of LEDS we are using
int ledCount = 5;


void setup() {
  //Setup our array to be outputs
  //The for loops cycles through all the pins and sets them to outputs
  for (int currentPin = 0; currentPin < ledCount; currentPin++) {
    pinMode(ledPins[currentPin], OUTPUT);
    digitalWrite(ledPins[currentPin], LOW);
  }  
}

void loop() {
  /*
   * We want to turn the LEDS on and off in a wave pattern    
   * We can use for loops!
   * This for loops cycles up all the pins
   * Turning them on and then off
  */
  for (int currentPin = 0; currentPin < ledCount; currentPin++) {
    // turn the pin on:
    digitalWrite(ledPins[currentPin], HIGH);
    delay(100);
    // turn the pin off:
    digitalWrite(ledPins[currentPin], LOW);
  }
  //This loops in reverse
  for (int thisPin = ledCount - 1; thisPin >= 0; thisPin--) {
    // turn the pin on:
    digitalWrite(ledPins[thisPin], HIGH);
    delay(100);
    // turn the pin off:
    digitalWrite(ledPins[thisPin], LOW);
  }
  //Because we are in the loop function these will go back and forth forever
}
