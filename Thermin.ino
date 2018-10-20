#include <Audio.h>

AudioSynthWaveform    waveform1;
AudioOutputAnalog     sgtl5000_1;
AudioConnection       patchCord1(waveform1, 0, sgtl5000_1, 0);

int sensorPin01 = 0;           // analog pin used to connect the sharp sensor
int val01 = 0;                 // variable to store the values from sensor(initially zero)

int sensorPin02 = 1;           // analog pin used to connect the sharp sensor
int val02 = 0;                 // variable to store the values from sensor(initially zero)

void setup() {
  
  AudioMemory(20);
  waveform1.begin(WAVEFORM_TRIANGLE);

  //send a test signal for 1 second
  waveform1.frequency(1000L);
  waveform1.amplitude(0.9);
  delay(1000);
}

void loop() {

  val01 = analogRead(sensorPin01);       // reads the value of the sharp sensor
  val02 = analogRead(sensorPin02);       // reads the value of the sharp sensor

  float sourceFrequency = map(val01, 90, 1000, 100, 2000);
  waveform1.frequency(sourceFrequency);

  float sourceAmplitude = ((float)map(val02, 90, 1000, 0, 1000))/1000;
  waveform1.amplitude(sourceAmplitude);
  
}
