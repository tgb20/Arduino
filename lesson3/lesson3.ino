//We need to declare our pins again
//This time we will want three vars
//One for the echo
unsigned long echo = 0;
//One for the sensors pin;
int sensor = 10;
//And one for the returning value
unsigned long ultravalue = 0;

void setup() {
  //We are going to use some basic serial for seeing what our Arduino is doing
  //We want it to output on the same rate as the monitor
  Serial.begin(9600);
 
  //We are using an Ultrasonic sensors which requires us to send data
  pinMode(sensor,OUTPUT);

}

//We need to create a custom value to hold the distance
unsigned long ping(){
  pinMode(ultraSoundSignal, OUTPUT); // Switch signalpin to output
  digitalWrite(ultraSoundSignal, LOW); // Send low pulse 
  delayMicroseconds(2); // Wait for 2 microseconds
  digitalWrite(ultraSoundSignal, HIGH); // Send high pulse
  delayMicroseconds(5); // Wait for 5 microseconds
  digitalWrite(ultraSoundSignal, LOW); // Holdoff
  pinMode(ultraSoundSignal, INPUT); // Switch signalpin to input
  digitalWrite(ultraSoundSignal, HIGH); // Turn on pullup resistor
  echo = pulseIn(ultraSoundSignal, HIGH); //Listen for echo
  ultraSoundSignal = (echo / 58.138) * .39; //convert to CM then to inches
  return sensor;
}

void loop() {
  //We need a filler value to hold our ping when we get a message
  int x = 0;
  //Set the filler to the ping;
  x = ping();
  //The print the distance to the monitor
  Serial.println(x);
  //Wait 1/4 of a second to not overload the monitor
  delay(250);
  //You should now be getting information from the arudino!
}
