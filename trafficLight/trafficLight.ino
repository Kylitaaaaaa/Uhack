int greenLight = 13;
int redLight = 11;

//LightSlots
int gL1 = 2;
int rL1 = 3;

int gL2 = 4;
int rL2 = 5;

int gL2 = 6;
int rL2 = 7;

int gL2 = 8;
int rL2 = 9;

//Car Count
int s11 = 0;
int s12 = 0;

int s21 = 0;
int s22 = 0;

int s31 = 0;
int s32 = 0;

int s41 = 0;
int s42 = 0;

void setup() {
  // put your setup code here, to run once:
  
  pinMode(gL1, OUTPUT);
  pinMode(rL1, OUTPUT);

  pinMode(gL2, OUTPUT);
  pinMode(rL2, OUTPUT);

  pinMode(gL3, OUTPUT);
  pinMode(rL3, OUTPUT);

  pinMode(gL4, OUTPUT);
  pinMode(rL4, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  getCount();
}

void getCount(){
  
}

void turnOnLight(lNum){
  digitalWrite(lNum, HIGH);
  delay(1000);
}

void turnOffLight(lNum){
  digitalWrite(lNum, LOW);
  delay(1000);
}

