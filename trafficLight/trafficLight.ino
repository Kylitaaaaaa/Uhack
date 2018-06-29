//Constants
int CARMAX = 3;

//road checkers
boolean roadChecker1 = false;
boolean roadChcker2 = false;
boolean roadChecker3 = false;
boolean roadChecker4 = false;

int roadChecker = 0;
//sensor Pins
//IR Sensor
int s11 = 10;
int s21;
int s31;
int s41;

//PIR Sensor;
int s12 = 11;
int s22;
int s32;
int s42;

//LightSlots2
// int lights[8] = {g1, r1, g2, r2, g3, r3, g4, r4};
int gLights[4] = {2, 4, 6, 8};
int rLights[4] = {3, 5, 7, 9};

int roads[4] = {0, 0, 0, 0};

//Car Count
int sensor1[4] = {0, 0, 0, 0};
int sensor2[4] = {CARMAX, CARMAX, CARMAX, CARMAX};

int numCarToRelease = 0;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(s11, INPUT);
  pinMode(s12, INPUT);  
}

void loop() {
  // put your main code here, to run repeatedly:

  //CHECK THE PRIORITY LANE
  while(true){
    if(s11 == CARMAX || s21 == CARMAX || s31 == CARMAX || s41 == CARMAX) break;
    if(digitalRead(s11) == HIGH){
      Serial.println("1 car entered at R1");
      sensor1[0]++;
      if(sensor1[0] == CARMAX)
        roadChecker = 1;
    }
    else if(digitalRead(s21) == HIGH){
      Serial.println("1 car entered at R2");
      sensor1[1]++;
      if(sensor1[0] == CARMAX)
        roadChecker = 2;
    }
    else if(digitalRead(s31) == HIGH){
      Serial.println("1 car entered at R3");
      sensor1[2]++;
      if(sensor1[0] == CARMAX)
        roadChecker = 3;
    }
    else if(digitalRead(s41) == HIGH){
      Serial.println("1 car entered at R4");
      sensor1[3]++;
      if(sensor1[0] == CARMAX)
        roadChecker = 4;
    }
  }

  //LOGIC PART
  while(true){
    turnOnGLight(roadChecker-1);
    if(digitalRead(s12) == HIGH){
       sensor2[roadChecker-1]--;
       sensor1[roadChecker-1]--;
       delay(100);
    if(sensor2[roadCheck-1] == 0) break;
    }
   
    
    
    
  }
  
  sensor2[roadChecker-1] = CARMAX;
  

  


  //check the no. of cars went out
  if(digitalRead(s12 == HIGH)
    Serial.println("1 car has went out");
    sensor2[0]++;
    sensor1[0]--;

  
  //janz check if cars went out already
  if(sensor2[0] == 0 && sensor2[1] == 0 && sensor2[2] == 0 && sensor2[3] == 0){
    Serial.println("All cars went out");
  }

  //reset numCarToRelease
  numCarToRelease = 0;

  //turn off green light
  turnOffGLight(roadChecker-1);

  

  
  //turn on red light
  turnOnRLight(roadChecker-1);
};

int getMax(int arr[]){
  int max = 0;
  for(int i = 1; i< sizeof(arr); i++){
    if(arr[max] < arr[i])
      max = i;
  }
  return max;
}

void turnOnGLight(int num){
  digitalWrite(gLights[num], HIGH);
  delay(1000);
}

void turnOffGLight(int num){
  digitalWrite(gLights[num], LOW);
  delay(1000);
}

void turnOnRLight(int num){
  digitalWrite(rLights[num], HIGH);
  delay(1000);
}

void turnOffRLight(int num){
  digitalWrite(rLights[num], LOW);
  delay(1000);
}

int getPriorityRoad(){
  
}

/*int getPriorityRoad(){
  int temp [4]= {0, 0, 0, 0};

  //get carCount
  for(int i = 0; i < sizeof(temp); i++)
    temp[i] = sensor1[i] - sensor2[i];

  //return Priority Road
  int max = getMax(temp);
  numCarToRelease = temp[max];

  return max;
}*/
