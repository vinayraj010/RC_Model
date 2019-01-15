const int CH_1_PIN=11;
const int deadzone =20;
double x,y;
int VRsignal = 5;
void setup(){
  pinMode(VRsignal, OUTPUT);
  Serial.begin(9600); 
}
void loop(){
  x = pulseIn(11,HIGH);
  y = pulseToPWM(x);
analogWrite(VRsignal, y);
  int ch_1 = pulseIn(CH_1_PIN, HIGH,25000);
  Serial.println(pulseToPWM(ch_1));
  delay(5); }
//convert rc pulse value to motor PWM value
int pulseToPWM(int pulse){
  if (pulse>1000){
    pulse = map(pulse,1000,2000,-500,500);
    pulse= constrain(pulse,-255,255);
    }else{
      pulse=0;
      }
  if (abs(pulse)<= deadzone){
        pulse=0;
        }
        return pulse; }
