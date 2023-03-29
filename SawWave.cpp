#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstring>

#include "WriteWaveFile.cpp"
#include "SMinimalWaveFileHeader.h"

int generateSawWave() {

  const int kSampleRate = 44100;  // 44.1kHz
  const int kNumChannels = 1;     // mono
  const int kBitsPerSample = 16;  // 16-bit PCM audio
  const int kDataSize = kSampleRate * kNumChannels * kBitsPerSample / 8 * 20;  // 20 seconds of audio data

  // Allocate memory for audio data
  int16_t* audio_data = new int16_t[kDataSize / sizeof(int16_t)];

  // Generate saw wave
  const double kFrequency = 440.0;  // 440Hz
  const double kAmplitude = 0.5 * INT16_MAX;
  const double kPhaseIncrement = kFrequency / kSampleRate;
  double phase = 0.0;
  for (int i = 0; i < kDataSize / sizeof(int16_t); ++i) {
    const double value = kAmplitude * (2.0 * phase - 1.0);
    audio_data[i] = static_cast<int16_t>(value);
    phase += kPhaseIncrement;
    if (phase >= 1.0) {
      phase -= 1.0;
    }
  }

  // Write audio data to file
  WriteWaveFile("saw_wave.wav", audio_data, kDataSize, kNumChannels, kSampleRate, kBitsPerSample);

  // Clean up
  delete[] audio_data;

  return 0;
}
