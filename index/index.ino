#define SPEED_ENGINE 128
#define STOP_ENGINE 0

void run(int leftForwardValue, int leftBackValue, int rightForwardValue, int rightBackValue){
  analogWrite(3, leftForwardValue);
  analogWrite(6, rightForwardValue);
  analogWrite(5, leftBackValue);
  analogWrite(9, rightBackValue);
}

void setup(){
  Serial.begin(9600);
}

void loop(){ 
  if(Serial.available()){    
    switch(Serial.read()){
      case 'u':        
        run(STOP_ENGINE, SPEED_ENGINE, STOP_ENGINE, SPEED_ENGINE);
        break;        
      case 'd':
        run(SPEED_ENGINE, STOP_ENGINE, SPEED_ENGINE, STOP_ENGINE);
        break;
      case 'r':  
        run(STOP_ENGINE, SPEED_ENGINE, SPEED_ENGINE, STOP_ENGINE);
        break;
      case 'l':
        run(SPEED_ENGINE, STOP_ENGINE, STOP_ENGINE, SPEED_ENGINE);
        break;
      default:
        run(STOP_ENGINE, STOP_ENGINE, STOP_ENGINE, STOP_ENGINE);
    }
  }
}
