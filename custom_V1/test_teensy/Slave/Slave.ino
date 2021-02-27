#define clk 20
#define data_in 0

uint8_t bit_index = 4;
uint8_t data_receive = 0;
const int ledPin = 13;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(clk, INPUT);
  pinMode(data_in, INPUT);
  Serial.begin(115200);
  attachInterrupt(clk, blink, FALLING);
}

void loop() {
  delay(10);
  Serial.println(digitalRead(data_in));
}

void blink(){
  if(digitalRead(data_in)){
    digitalWrite(ledPin,HIGH);
  } else {
    digitalWrite(ledPin,LOW);
  }
}
