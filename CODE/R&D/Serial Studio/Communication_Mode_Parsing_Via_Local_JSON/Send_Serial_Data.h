// Function to send data to serial studio 
// Should be included with other projects 
template<typename... Args>
void Send_Serial_Data(Args... args) {
  // Send frame start delimiter

  Serial.print("/*");

  // Convert each argument to string and send it over serial
  int Temp[] = { 0, (Serial.print(args), Serial.print(","), 0)... };


  // Send frame end delimiter
  Serial.println("*/");
}