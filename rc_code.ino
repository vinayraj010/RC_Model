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
  }
//convert rc pulse value to motor PWM value
int pulseToPWM(int pulse){
  if (pulse>1000){
    pulse = map(pulse,1000,2000,-500,500);
    pulse= constrain(pulse,-255,255);
    }else{
      pulse=0;
      }
 return pulse; 
 }






