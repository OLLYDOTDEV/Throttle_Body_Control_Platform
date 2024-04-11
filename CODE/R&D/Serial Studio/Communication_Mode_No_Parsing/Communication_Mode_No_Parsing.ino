void setup() {
  // Initialize serial port
  Serial.begin(115200);

  // Setup pins

}

// Function to send ADC values in pre-defined JSON format
void sendJSONData() {
  // Fixed ADC values for testing
  const float adc1 = 1.23;
  const float adc2 = 2.34;
  const float adc3 = 3.45;
  const float adc4 = 4.56;
  const float adc5 = 5.67;

  // Create JSON string
  String json = "{\"ADC_Values\": {\"A1\": " + String(adc1, 2) + ", \"A2\": " + String(adc2, 2) + ", \"A3\": " + String(adc3, 2) + ", \"A4\": " + String(adc4, 2) + ", \"A5\": " + String(adc5, 2) + "}}";

  // Send JSON data to serial port
  Serial.println(json);
}

void loop() {
  // Call the function to send JSON data with fixed ADC values
  sendJSONData();

  // Wait 50 ms
  delay(50);
}
