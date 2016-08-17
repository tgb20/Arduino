//We need to redeclare our pins

int pin = 9;


void setup() {
  // put your setup code here, to run once:

  //We need to set our pin to an output
  pinMode(pin,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  //We want the LED to blink on and off
  //We can use delays as well as alternating high and low outputs
  //Start by turning the pin on
  digitalWrite(pin,HIGH);
  //We then want to it to wait before doing the next item
  delay(1000); //Every 1000 is equal to 1 second
  //Now we can turn the LED off
  digitalWrite(pin,LOW);
  //And add another wait
  delay(1000);
  //Our LED will now blink on and off every second.
  //Because we are in a loop function it will go back to the top after the delay
  //This will start the process over again
}
