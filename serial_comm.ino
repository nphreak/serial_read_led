/*
 *  Creating an script that receive a command from serial port using serial.read
 * 
 */

int ledPin = 12;
boolean ledOn = true;
boolean endString = false;
char data;
String dataString;

void setup() {
  // put your setup code here, to run once:s
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  while(Serial.available() > 0){    
    data = Serial.read();
    Serial.write(data);
    switch(data){
      case '1':
        turnLedOn();
        break;
      case '0':
        turnLedOff();
        break;
      case 'a':
        ledToggle();
        break;
      default:
        Serial.write("deu errado");
        break;
    }
  }
}

void turnLedOn(){
  digitalWrite(ledPin, HIGH);
  ledOn = true;
  Serial.println("liga");
}

void turnLedOff(){
  digitalWrite(ledPin, LOW);
  ledOn = false;
  Serial.println("desliga");
}

void ledToggle(){
  if (ledOn){
    ledOn = false;
    turnLedOff();
  }
  else {
    ledOn = true;
    turnLedOn();
  }
}
