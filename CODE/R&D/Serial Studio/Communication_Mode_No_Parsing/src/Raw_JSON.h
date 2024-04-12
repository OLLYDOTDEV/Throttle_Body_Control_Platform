#include <ArduinoJson.h>

// raw JSON string from Serial Studio project editor 
const char* RAW_JSON = R"(
{
    "frameEnd": "*/",
    "frameParser": "function parse(frame, separator) {\n    return frame.split(separator);\n}",
    "frameStart": "/*",
    "groups": [
        {
            "datasets": [
                {
                    "alarm": 0,
                    "fft": false,
                    "fftSamples": 1024,
                    "graph": false,
                    "index": 1,
                    "led": false,
                    "log": false,
                    "max": 0,
                    "min": 0,
                    "title": "Test 1",
                    "units": "",
                    "value": "",
                    "widget": ""
                },
                {
                    "alarm": 0,
                    "fft": false,
                    "fftSamples": 1024,
                    "graph": false,
                    "index": 2,
                    "led": false,
                    "log": false,
                    "max": 0,
                    "min": 0,
                    "title": "Test 2",
                    "units": "",
                    "value": "",
                    "widget": ""
                },
                {
                    "alarm": 0,
                    "fft": false,
                    "fftSamples": 1024,
                    "graph": false,
                    "index": 3,
                    "led": false,
                    "log": false,
                    "max": 0,
                    "min": 0,
                    "title": "Test 3",
                    "units": "",
                    "value": "",
                    "widget": ""
                }
            ],
            "title": "1",
            "widget": ""
        }
    ],
    "separator": ",",
    "title": "Simple Test "
}
)";
