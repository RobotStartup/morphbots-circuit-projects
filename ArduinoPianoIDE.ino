Made by Harmony Petty

const int BUTTON_PIN = 2;       // the number of the pushbutton pin
const int BUTTON_PIN2 = 3; 
const int BUTTON_PIN3 = 4;
const int BUTTON_PIN4 = 6;
const int BUTTON_PIN5 = 8; 
const int buzzer=13;
  
void setup() {
  Serial.begin(9600);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
   pinMode(BUTTON_PIN2, INPUT_PULLUP);
    pinMode(BUTTON_PIN3, INPUT_PULLUP);
     pinMode(BUTTON_PIN4, INPUT_PULLUP);
      pinMode(BUTTON_PIN5, INPUT_PULLUP);
      pinMode(buzzer,OUTPUT);
      
}

void loop() {
  int buttonState = digitalRead(BUTTON_PIN);
    int buttonState2 = digitalRead(BUTTON_PIN2);
      int buttonState3 = digitalRead(BUTTON_PIN3);
        int buttonState4 = digitalRead(BUTTON_PIN4);
          int buttonState5 = digitalRead(BUTTON_PIN5);

    if(buttonState==0){
      tone(buzzer,1000);
    }else if (buttonState2==0){
      tone(buzzer,1200);
    }else if (buttonState3==0){
      tone(buzzer,1500);
    }else if (buttonState4==0){
      tone(buzzer,1700);
    }else if (buttonState5==0){
      tone(buzzer,2000);
      
    }else{
      noTone(buzzer);
    }
 // Serial.println(buttonState);
}
