const int CH_2_PIN=11;
const int CH_3_PIN=10;
const int deadzone =20;
int x,y,z,w;
int leda = 5;
int ledb = 6;

void setup(){
  pinMode(leda, OUTPUT);
  pinMode(ledb, OUTPUT);
  Serial.begin(9600);
  }
void loop(){
  x = pulseIn(11,HIGH);
  z = pulseIn(10,HIGH);
y = pulseToPWM(x);
w = pulseToPWM(z);
analogWrite(leda, y);
analogWrite(ledb, w);
  int ch_2 = pulseIn(CH_2_PIN, HIGH,25000);
  int ch_3 = pulseIn(CH_3_PIN, HIGH,25000);
  Serial.println(pulseToPWM(ch_2));
  Serial.println(pulseToPWM(ch_3));
  delay(5);
  }
//convert rc pulse value to motor PWM value
int pulseToPWM(int pulse){
  // if we're receiving numbers, convert them to motor PWM
  if (pulse>900){
    pulse = map(pulse,1000,2000,-500,500);
    pulse= constrain(pulse,-255,255);
    }else{
      pulse=0;
      }

      // Anything in deadzone should stop the motor
      if (abs(pulse)<= deadzone){
        pulse=0;
        }
        return pulse;
  }
