int buttonAPin = 2;     // Pin where the button is connected
int buttonAState = 0;   // Variable to hold the button state
int lastButtonAState = 0; // Variable to hold the last button state
int toggleState = 0;   // Variable to hold the toggle state (0 or 1)




int motorAPin = 10; // Pin for Motor A
int motorBPin = 11; // Pin for Motor B


void setup() {
  pinMode(buttonAPin, INPUT); // Set button pin as input

   
  pinMode(motorAPin, OUTPUT); // Set motor A pin as output
  pinMode(motorBPin, OUTPUT); // Set motor B pin as output

  
  Serial.begin(9600); // Initialize serial communication at 9600 baud rate
}

void loop() {

   
  
  buttonAState = digitalRead(buttonAPin); // Read the current state of the button

  // Check if the button state has changed from the last state (indicating a press)
  if (buttonAState != lastButtonAState) {
    if (buttonAState == LOW) { // Button is pressed (LOW)
      toggleState = !toggleState; // Toggle the state (0 -> 1 or 1 -> 0)
      Serial.print("A State: ");
      Serial.println(toggleState); // Print the current toggle state

      if (toggleState == 1) {
        // Activate the motor for 0.5 seconds
        digitalWrite(motorAPin, HIGH);
        digitalWrite(motorBPin, LOW);
        delay(500); // Wait for 0.5 seconds

        // Stop the motor
        digitalWrite(motorAPin, LOW);
        digitalWrite(motorBPin, LOW);
      }
      
      if (toggleState == 0) {
        // Activate the motor for 0.5 seconds
        digitalWrite(motorAPin, LOW);
        digitalWrite(motorBPin, HIGH);
        delay(500); // Wait for 0.5 seconds for

        // Stop the motor
        digitalWrite(motorAPin, LOW);
        digitalWrite(motorBPin, LOW);
      }
    }
    // Debounce delay to avoid multiple toggles due to noise
    delay(50);
  }

  lastButtonAState = buttonAState; // Update the last button state
}
