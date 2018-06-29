//LightSlots2
// int lights[8] = {g1, r1, g2, r2, g3, r3, g4, r4};
int gLights[4] = {2, 4, 6, 8};
int rLights[4] = {3, 5, 7, 9};

//Car Count
int sensor1[4] = {0, 0, 0, 0};
int sensor2[4] = {0, 0, 0, 0};

int numCarToRelease = 0;

void setup() {
  // put your setup code here, to run once:


  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);


  
}

void loop() {
  
  
  // put your main code here, to run repeatedly:
  getCount();
  int currLight = getPriorityRoad();
  
  //turn on green light for priority road
  turnOnGLight(currLight);
  
  //janz check if cars went out already

  //reset numCarToRelease
  numCarToRelease = 0;

  //turn off green light
  turnOffGLight(currLight);
  
  //turn on red light
  turnOnRLight(currLight);
}

void getCount(){
  //janz insert code here
  
}

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
  int temp [4]= {0, 0, 0, 0};

  //get carCount
  for(int i = 0; i < sizeof(temp); i++)
    temp[i] = sensor1[i] - sensor2[i];

  //return Priority Road
  int max = getMax(temp);
  numCarToRelease = temp[max];

  return max;
}




