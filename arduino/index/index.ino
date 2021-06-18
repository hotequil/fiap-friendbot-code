char dataSerial;

#define FORWARD 'u'
#define BACK 'd'
#define RIGHT 'r'
#define LEFT 'l'

#define SPEED_ENGINE 128
#define STOP_ENGINE 0

#define ENGINE_LEFT_FORWARD 3
#define ENGINE_LEFT_BACK 5
#define ENGINE_RIGHT_FORWARD 6
#define ENGINE_RIGHT_BACK 9

void run(int leftForwardValue, int leftBackValue, int rightForwardValue, int rightBackValue){
  analogWrite(ENGINE_LEFT_FORWARD, leftForwardValue);
  analogWrite(ENGINE_LEFT_BACK, leftBackValue);
  analogWrite(ENGINE_RIGHT_FORWARD, rightForwardValue);
  analogWrite(ENGINE_RIGHT_BACK, rightBackValue);
}

void setup(){
  Serial.begin(9600);
}

void loop(){ 
  if(Serial.available()){
    dataSerial = Serial.read();

    Serial.println(dataSerial);

    switch(dataSerial){
      case FORWARD:        
        run(SPEED_ENGINE, STOP_ENGINE, SPEED_ENGINE, STOP_ENGINE);
        break;        
      case BACK:
        run(STOP_ENGINE, SPEED_ENGINE, STOP_ENGINE, SPEED_ENGINE);
        break;
      case RIGHT:  
        run(SPEED_ENGINE, STOP_ENGINE, STOP_ENGINE, SPEED_ENGINE);
        break;
      case LEFT:
        run(STOP_ENGINE, SPEED_ENGINE, SPEED_ENGINE, STOP_ENGINE);
        break;
      default:
        run(STOP_ENGINE, STOP_ENGINE, STOP_ENGINE, STOP_ENGINE);
    }
  }
}
