//LightSlots

int s1 = 6;
int s2 = 7;

//Car Count
int carCount1 = 0;
int carCount2 = 0;
boolean checker = true;

const unsigned int THRESHOLD = 2000;

// Stop counting after this value (we can assume it is total darkness)

const unsigned int MAX_T = 20000;

// Pin definitions

const int P_JNCT_PIN = 2;// P junction of sensing LED
const int N_JNCT_PIN = 3;// N junction of sensing LED
const int OUT_LED_PIN = 9;// Output LED pin (P junction pin)

const int P_JNCT_PIN2 = 6;// P junction of sensing LED
const int N_JNCT_PIN2 = 7;// N junction of sensing LED
const int OUT_LED_PIN2 = 10;// Output LED pin (P junction pin)

// Global variables

unsigned int sen_time;// Time it takes to discharge LED
unsigned int sen_time2;// Time it takes to discharge LED

int count = 0;

void setup() {
  Serial.begin(9600);

  // Set P junction pin to output low (GND)
  pinMode(P_JNCT_PIN, OUTPUT);
  digitalWrite(P_JNCT_PIN, LOW);

  // Set output LED pin to output
  pinMode(OUT_LED_PIN, OUTPUT);

  pinMode(P_JNCT_PIN2, OUTPUT);
  digitalWrite(P_JNCT_PIN2, LOW);

  // Set output LED pin to output
  pinMode(OUT_LED_PIN2, OUTPUT);


}

void loop() {

  if (checker) {
    readLED();
    
    if (carCount1 <= 5) {
      if ( sen_time > THRESHOLD ) {
        //Serial.println("high");
        digitalWrite(OUT_LED_PIN, HIGH);

      }
      else {
        Serial.println(carCount1);
      // Serial.println("+ Car");
        digitalWrite(OUT_LED_PIN, LOW);
        carCount1++;
      }
      if(carCount1 == 5)
        checker = false;
       
    }
  }

  else if (!checker) {
    readLED2();
    
   
    if (carCount1 >= 0) {
      if ( sen_time2 > THRESHOLD ) {
        //Serial.println("high");
        digitalWrite(OUT_LED_PIN2, HIGH);

      }
      else {
        Serial.println(carCount1);
        //Serial.println("- Car");
        digitalWrite(OUT_LED_PIN2, LOW);
        carCount1--;
      }
      if(carCount1 == 0)
        checker = true;
     
    }
  }


  delay(200);
  //get Priority Road
  //if (carCount1 > carCount2) {
  // releaseCars(1);
  //}
  //else
  //releaseCars(2);

}

void releaseCars(int n) {
  if (n == 1) {
    digitalWrite(s1, HIGH);
  }
  else {
    digitalWrite(s2, HIGH);
  }
  delay(3000);
}

void readLED() {

  unsigned int t;

  // Reset global LED discharge time

  sen_time = 0;

  // Apply reverse voltage to charge the sensing LED's capacitance
  pinMode(N_JNCT_PIN, OUTPUT);
  digitalWrite(N_JNCT_PIN, HIGH);

  // Isolate N junction and turn off pull-up resistor
  pinMode(N_JNCT_PIN, INPUT);
  digitalWrite(N_JNCT_PIN, LOW);

  // Count how long it takes for the LED to discharge

  for ( t = 0; t < MAX_T; t++ ) {
    if ( digitalRead(N_JNCT_PIN) == 0 ) {
      break;
    }
  }
  sen_time = t;
}

void readLED2() {

  unsigned int t;

  // Reset global LED discharge time

  sen_time2 = 0;

  // Apply reverse voltage to charge the sensing LED's capacitance
  pinMode(N_JNCT_PIN2, OUTPUT);
  digitalWrite(N_JNCT_PIN2, HIGH);

  // Isolate N junction and turn off pull-up resistor
  pinMode(N_JNCT_PIN2, INPUT);
  digitalWrite(N_JNCT_PIN2, LOW);

  // Count how long it takes for the LED to discharge

  for ( t = 0; t < MAX_T; t++ ) {
    if ( digitalRead(N_JNCT_PIN2) == 0 ) {
      break;
    }
  }
  sen_time2 = t;
}
