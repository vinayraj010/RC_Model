/* For Reading PWM Receiver Signal Using Arduino connect
GND->to the GND of the receiver, 
5v to the -> 5v, and 
signal of the receiver to the ~ pwm pin2 of arduino
*/
double channel ;
void setup() {
  pinMode(2, INPUT);
  Serial.begin(9600);
}
void loop() {
  channel = pulseIn(2,HIGH);
  Serial.println(channel);
}
