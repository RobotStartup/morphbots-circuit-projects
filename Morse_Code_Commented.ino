// MorphBots YouTube Project 1: Morse Code Machine


// Constant variables: these will never change

const int button = 8; // Button input is coming from pin 8
const int led =  13; // Button input is coming from pin 13


// Variables that will change, this states that the button default is being pressed.
// This value will change when the button isn't being pressed.

int button_state = 0;   


void setup() {

  // Sets LED as the output
  pinMode(led, OUTPUT);

  // Sets button as input
  pinMode(button, INPUT_PULLUP);
}


void loop() {

  // Asks computer to read the input of the button
  button_state = digitalRead(button);


  // If the button is being pressed, then the LED should turn on
  if(button_state == 0)         
    digitalWrite(led, HIGH); 
    
  // If the computer doesn't read that the button is pressed, then the LED will stay off
  else                           
    digitalWrite(led, LOW); 
}
