// define your pins
const int dimmer = A0; // Potentiometer pin
const int ledStrip = 5; // MOSFET gate control pin

void setup() {
  // put your setup code here, to run once:
  pinMode(ledStrip, OUTPUT);
  pinMode(dimmer, INPUT);
}

void loop() {
  // Get a reading from the potentiometer.
  int brightness = analogRead(dimmer);
  brightness = map(brightness, 0, 1023, 0, 255);
  // Turn the strip on based on the potentiometer value.
  // Turn on after 5 to reduce flickering at bottom values, else turn it off.
  if (brightness > 5) {
    analogWrite(ledStrip, brightness);
  } else {
    analogWrite(ledStrip, 0);
  }
  // Slight delay because why not.
  delay(2);
}
