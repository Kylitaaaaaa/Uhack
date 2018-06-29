//LightSlots
// int lights[8] = {s11, s12, s21, s22, s31, s32, s41, s42};
int lightsArr[8] = {1, 2, 3, 4, 5, 6, 7, 8};

//Car Count
int sensor1[4] = {0, 0, 0, 0};
int sensor2[4] = {0, 0, 0, 0};

void setup() {
  // put your setup code here, to run once:

  for(int i = 1; i< sizeof(lightsArr); i++){
    pinMode(lightsArr[i], OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  getCount();
  turnOnGreen();
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

void turnOnLight(int num){
  digitalWrite(lightsArr[num], HIGH);
  delay(1000);
}

void turnOffLight(int num){
  digitalWrite(lightsArr[num], LOW);
  delay(1000);
}

void turnOnGreen(){
  int temp [4]= {0, 0, 0, 0};

  //get carCount
  for(int i = 0; i < sizeof(temp); i++)
    temp[i] = sensor1[i] - sensor2[i];

  //per Light
  turnOnLight(getMax(temp));
  
}




