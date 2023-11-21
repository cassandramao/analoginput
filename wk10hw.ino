int forcePin = A0; // Force sensor
int potPin = A2; // Potentiometer
const int ledPins[] = {10, 9, 6, 5}; // LEDs connected to PWM
const int numLED = 5; //number of LED plus 1
int forceValue;
int potValue;

void setup() {
  for (int i = 0; i < numLED; i++) {
    pinMode(ledPins[i], OUTPUT);
  } // output for LEDs
  Serial.begin(9600);
  // pinMode(potPin, INPUT);
}

void loop() {
  forceValue = analogRead(forcePin); // Read force sensor value
  potValue = analogRead(potPin); // Read potentiometer value
  int brightLED = map(potValue, 0, 1023, 0, 255); // map out the range for brightness
  // // code reference: https://www.youtube.com/watch?v=DLCDGCe7FRA

  int numLightup = map(forceValue, 0, 1023, 0, numLED); // map out the number of LEDs that light up

  // // Turn on the LEDs based on the force sensor reading
  // // Reference: https://www.youtube.com/watch?v=azBmL9qMK-8
  for (int i = 0; i < sizeof(ledPins); i++) {
    if (i < numLightup) {
      analogWrite(ledPins[i], potValue/4); // turn on the LEDs one by one with adjustable brightness
      // digitalWrite(ledPins[i], HIGH);
    } else {
      // digitalWrite(ledPins[i], LOW); // turn off the lights completely
      analogWrite(ledPins[i], 0);
    }
  }

  Serial.println(numLightup);

  delay(100);
}


