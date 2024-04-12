// V1 - Now with JSON Suport
// By Oliver Bell
// Function to send data to serial studio

#include <Raw_JSON.h>  // only need if Format_Raw_JSON() is used otherwise can be left comemmented
// Call when serial studio communcation mode: Parse via JSON project
template <typename... Args>
void Send_Serial_Frame(Args... args)
{
  // Send frame start delimiter

  Serial.print("/*");

  // Convert each argument to string and send it over serial
  int Temp[] = {0, (Serial.print(args), Serial.print(","), 0)...};

  // Send frame end delimiter
  Serial.println("*/");
}

// Call when serial studio communication mode: Parse via JSON project
// Usage: setup() to take raw JSON and format it.
char* Format_Raw_JSON(const char *RAW_JSON_LOCAL) {
    StaticJsonDocument<1024> doc;
    deserializeJson(doc, RAW_JSON_LOCAL);

    // Remove unnecessary members
    doc.remove("frameEnd");
    doc.remove("frameParser");
    doc.remove("frameStart");

    // Replace "value": "" with "value": "%s",
    JsonArray groups = doc["groups"];
    for (JsonObject group : groups) {
        JsonArray datasets = group["datasets"];
        for (JsonObject dataset : datasets) {
            dataset["value"] = "%s";
        }
    }

    // Serialize the modified JSON to string
    char* jsonBuffer = (char*)malloc(1024); // Allocate memory dynamically
    if (jsonBuffer) { // Check if memory allocation succeeded
        size_t len = serializeJson(doc, jsonBuffer, 1024);
        jsonBuffer[len] = '\0'; // Null-terminate the string
    }
    return jsonBuffer;
}



template <typename... Args>
void Send_Serial_JSON(const char* Formated_JSON_Local, Args... args) {
    Serial.print("/*");

    // Print the formatted JSON string with the provided arguments
    Serial.printf(Formated_JSON_Local, args...);

    Serial.println("*/");
}
