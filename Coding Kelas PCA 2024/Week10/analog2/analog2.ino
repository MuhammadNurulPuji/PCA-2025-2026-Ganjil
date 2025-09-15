int buf;
bool pause;
void setup() {
  // put your setup code here, to run once:
DDRD = 0x00; //PortD asinput
PORTD = 0xff; //internalpullup
DDRC = 0b00001111;  //portC sebagai output
}

void loop() {
  // put your main code here, to run repeatedly:
  if((PIND == 0b11111110)&(PIND != 0b11111101)){
    buf=0b00000001;
    for(int j=0;j<5;j++){
    for(int i=0; i<4; i++){
      PORTC= buf << i;
      delay(500);
    }
    }
    
    buf=0b00001000;
    for(int j=0;j<5;j++){
    for(int i=0; i<4; i++){
      PORTC= buf >> i;
      delay(500);
    }
    }
  }else if((PIND == 0b11111011)&(PIND != 0b11111101)){
    buf=0b00000001;
    for(int j=0;j<5;j++){
    for(int i=0; i<4; i++){
      PORTC= buf << i;
      delay(500);
    }
    }
  }else if((PIND == 0b11110111)&(PIND != 0b11111101)){
    buf=0b00001000;
    for(int j=0;j<5;j++){
    for(int i=0; i<4; i++){
      PORTC= buf >> i;
      delay(500);
    }
    }
  }else{
    PORTC=0xff;
  }
}