//THIS IS A CONTINUATION OF LESSON 3!

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
  pinMode(sensor, OUTPUT); // Switch signalpin to output
  digitalWrite(sensor, LOW); // Send low pulse 
  delayMicroseconds(2); // Wait for 2 microseconds
  digitalWrite(sensor, HIGH); // Send high pulse
  delayMicroseconds(5); // Wait for 5 microseconds
  digitalWrite(sensor, LOW); // Holdoff
  pinMode(sensor, INPUT); // Switch signalpin to input
  digitalWrite(sensor, HIGH); // Turn on pullup resistor
  echo = pulseIn(sensor, HIGH); //Listen for echo
  sensor = (echo / 58.138) * .39; //convert to CM then to inches
  return sensor;
}

void loop() {
  //We need a filler value to hold our ping when we get a message
  int x = 0;
  //Set the filler to the ping;
  x = ping();
  //The print the distance to the monitor
  Serial.println(x);

  //THE NEW SECTION

  //We need to get the value from the sensor and map it to the brightness of the LED
  //We are going to use a map function
  //This takes one set of values and converts it to another
  //It works like this y = map(input,oldMin, oldMax, newMin, newMax);
  //We are using 0 and 10 for the oldMin and Max for 0 inches to 10 inches
  //You can change this to match the distances you want
  y = map(x,0,10,0,255);
  //The y value is now on a scale of 0 to 255 which can be used to control an LED
  //We want to write the value to the LED
  digitalWrite(led,y);
  //Your LED should now change brightness depending how far away your hand is from the sensor
  
  //Wait 1/4 of a second to not overload the monitor
  delay(250);
  //You should now be getting information from the arudino!  
}
