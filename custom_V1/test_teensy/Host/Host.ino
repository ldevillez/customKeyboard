
#define clk 14
#define data_out 11

uint8_t send_data = 0;
uint8_t data_to_send = 3;
uint16_t period_clk = 500;
uint8_t bit_index = 5;
uint8_t clk_status = 0;
unsigned long p1 = 0;
unsigned long p2 = 0;

const int ledPin = 13;

void setup()
{
  pinMode(ledPin, OUTPUT);
  pinMode(clk, OUTPUT);
  pinMode(data_out, OUTPUT);
  p1 = millis();
  Serial.begin(115200);
}

void loop()
{
  delay(10);
  p2 = millis();
  if(send_data == 1){
    if(p2-p1>period_clk){

      clk_status = 1 - clk_status;
      if(clk_status == 1){
        digitalWrite(clk, HIGH);
        digitalWrite(ledPin,HIGH);
        Serial.print(1);
        Serial.print(" ");
        Serial.print(p2);
        Serial.print("\n");
      }
      else{
        Serial.print(0);
        Serial.print(" ");
        Serial.print(p2);
        Serial.print("\n");
        digitalWrite(clk, LOW);
        digitalWrite(ledPin,LOW);
      }

      if(clk_status == 1){
        if(data_to_send %2 == 1)
          digitalWrite(data_out,HIGH);
        else
          digitalWrite(data_out,LOW);
          
        data_to_send = data_to_send/2;
      } else {
        bit_index--;
      }
  
      if(bit_index <= 0){
        send_data = 0;
        Serial.println("CHECH");
        Serial.println();
      }
      p1 = p2;

    }

  } else {
    delay(5000);
    send_data = 1;
    bit_index = 5;
    data_to_send = 3;
    p1 = millis(); 
  }
}
