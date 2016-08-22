/*
 * Second Arduino project:
 * Make the LED light flash
 * 
 * We need to declare our pins.
 */

int ledPin = 9;

void setup() {
  /* 
   * Put your setup code here to run once.
   * We need to set our pin to an output.
   */
  pinMode(ledPin,OUTPUT);
}

void loop() {
  /* 
   *  Put your main code here, to run repeatedly.
   *  We want the LED to blink on and off.
   *  We can use delays as well as alternating high and low outputs.
   *  
   *  Start by turning the pin on:
   */
  digitalWrite(ledPin,HIGH);
  
  // Wait before doing the next item
  delay(1000); // 1000 milliseconds is equal to 1 second
  
  // Turn the LED off
  digitalWrite(ledPin,LOW);
  
  // Add another wait
  delay(1000);
  
   /* 
   *  Our LED will now blink on and off every second.
   *  Because we are in a loop function it will go back
   *  to the top of the loop after the delay.
   *  This will start the process over again.
   */
}
