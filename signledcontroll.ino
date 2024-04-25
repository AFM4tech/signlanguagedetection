#include <SoftwareSerial.h>

// Define Bluetooth TX and RX pins
#define BT_TX 2
#define BT_RX 3

// Define pins for controlling loads
#define LOAD1_PIN 4
#define LOAD2_PIN 5
#define LOAD3_PIN 6

// Initialize software serial object
SoftwareSerial bluetooth(BT_TX, BT_RX);

void setup() {
  // Set pins for controlling loads as outputs
  pinMode(LOAD1_PIN, OUTPUT);
  pinMode(LOAD2_PIN, OUTPUT);
  pinMode(LOAD3_PIN, OUTPUT);
  
  // Set baud rate for Bluetooth communication
  bluetooth.begin(9600);
}

void loop() {
  if (bluetooth.available() > 0) {
    char command = bluetooth.read(); // Read incoming command
    
    // Execute corresponding action based on received command
    switch (command) {
      case '1':
        turnOnLoad(LOAD1_PIN);
        break;
      case '2':
        turnOffLoad(LOAD1_PIN);
        break;
      case '3':
        turnOnLoad(LOAD2_PIN);
        break;
      case '4':
        turnOffLoad(LOAD2_PIN);
        break;
      case '5':
        turnOnLoad(LOAD3_PIN);
        break;
      case '6':
        turnOffLoad(LOAD3_PIN);
        break;
      default:
        // Invalid command, do nothing
        break;
    }
  }
}

// Function to turn on a load
void turnOnLoad(int pin) {
  digitalWrite(pin, HIGH);
}

// Function to turn off a load
void turnOffLoad(int pin) {
  digitalWrite(pin, LOW);
}
