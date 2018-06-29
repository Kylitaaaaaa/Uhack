//LightSlots
int gL{2, 4, 6, 8};
int rL{3, 5, 7, 9};

//Car Count
int sensor1{0, 0, 0, 0};
int sensor2{0, 0, 0, 0};

void setup() {
  // put your setup code here, to run once:
  
  pinMode(gL1[0], OUTPUT);
  pinMode(rL1[0], OUTPUT);

  pinMode(gL2[1], OUTPUT);
  pinMode(rL2[1], OUTPUT);

  pinMode(gL3[2], OUTPUT);
  pinMode(rL3[2], OUTPUT);

  pinMode(gL4[3], OUTPUT);
  pinMode(rL4[3], OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  getCount();
}

void getCount(){
  
  
}

int turnOnGreen(){
  int temp = {0, 0, 0, 0};

  //get carCount
  for(int i = 0; i < sizeof(temp); i++)
    temp[i] = sensor1[i] - sensor2[i];

  
}

void turnOnLight(lNum){
  digitalWrite(lNum, HIGH);
  delay(1000);
}

void turnOffLight(lNum){
  digitalWrite(lNum, LOW);
  delay(1000);
}

