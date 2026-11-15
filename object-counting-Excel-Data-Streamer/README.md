# Object Counting System using Arduino and Microsoft Excel Data Streamer

## Problem Statement
Design and develop an object counting system using sensors and Data Streamer in Microsoft Excel to monitor and record the number of objects in real time. The system should capture data through Arduino and visualize it in Excel for analysis.

## Aim
To count objects detected by an IR sensor using Arduino Uno and send the object count and sensor state to Microsoft Excel through USB serial communication using Data Streamer.

## Components
| Component | Quantity |
|---|---:|
| Arduino Uno | 1 |
| IR obstacle detection sensor module | 1 |
| USB cable (Arduino to computer) | 1 |
| Breadboard and jumper wires | As needed |
| Computer with Microsoft Excel and Data Streamer add-in | 1 |

## Connections
| IR sensor pin | Arduino Uno pin |
|---|---|
| OUT | D2 |
| VCC | 5V |
| GND | GND |

## Working
1. The IR sensor detects an object in front of it.
2. The Arduino reads the sensor output on digital pin D2.
3. When the signal changes from HIGH to LOW, the Arduino treats it as a new object detection.
4. A 100 ms debounce interval helps prevent repeated counts from rapid signal changes.
5. The Arduino sends two comma-separated values every 200 ms: `ObjectCount` and `SensorState`.
6. Microsoft Excel Data Streamer receives the serial data and displays it for real-time monitoring and recording.

## How to run
1. Connect the IR sensor to the Arduino Uno according to the connection table.
2. Connect the Arduino Uno to the computer using a USB cable.
3. Open the Arduino IDE and create a new sketch.
4. Copy the code from `object_counting_excel.cpp` into the sketch.
5. Select **Board: Arduino Uno** and the correct COM port, then click **Upload**.
6. Close the Arduino IDE Serial Monitor if it is open; the COM port can be used by only one application at a time.
7. Open Microsoft Excel and enable/open the **Data Streamer** add-in.
8. In the **Data Streamer** tab, choose **Connect a Device** and select the Arduino COM port. Set the baud rate to **9600** if prompted.
9. Start streaming data. Excel should receive the `ObjectCount` and `SensorState` fields.
10. Place an object in front of the IR sensor and observe the count update in Excel.

## Serial data format
The Arduino first sends the column headings:
```text
ObjectCount,SensorState
```
It then sends rows such as:
```text
0,0
1,1
1,0
2,1
```

- `ObjectCount`: Total number of detected objects so far.
- `SensorState`: `1` means the sensor output is LOW (object detected); `0` means the sensor output is HIGH (no object detected).

## Notes
- This code assumes the IR module gives a LOW output when an object is detected. If your module behaves the opposite way, the detection logic must be adjusted.
- Keep the sensor aligned and avoid placing objects too close together if the sensor cannot distinguish them.
- The code sends data over USB serial at **9600 baud**. Excel Data Streamer must use the same baud rate.
- The count is stored in Arduino RAM and resets to zero when the Arduino restarts.
