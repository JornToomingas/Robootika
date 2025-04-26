//Ülesanne 3
//Jörn Markus Toomingas


const int LM35 = A0;
const int motor = 13;
const int LedRed = 12;
const int LedGreen = 11;

void setup() {
  Serial.begin(9600);
  pinMode(motor, OUTPUT);
  pinMode(LedRed, OUTPUT);
  pinMode(LedGreen, OUTPUT);
  delay(2000);
}
//TMP sensor
void loop() {
  int value = analogRead(LM35);
  float Temperature = value * 500.0 / 1023.0;
  
//Prindib temperatuuri serial monitorile
  Serial.print("Temperature: ");
  Serial.print(Temperature);
  Serial.print(" °C  | ");

//Kui on >50 kraadi
  if (Temperature > 50) {
    digitalWrite(motor, HIGH);
    digitalWrite(LedRed, HIGH);
    digitalWrite(LedGreen, LOW);
    Serial.println("Mootor: SEES  | Ventilaator: SEES");
  }
//Kui on <50 kraadi
  else {
    digitalWrite(motor, LOW);
    digitalWrite(LedRed, LOW);
    digitalWrite(LedGreen, HIGH);
    Serial.println("Mootor: VÄLJAS  | Ventilaator: VÄLJAS");
  }
  delay(1000);
}


//abi: https://www.tinkercad.com/things/lf9NfwlqXl3-temperature-sensor-with-dc-motor-and-lcd-16x2
