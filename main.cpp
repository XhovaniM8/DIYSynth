#include "WriteWaveFile.cpp"
#include "SminimalWaveFileHeader.h"

int main(){
    // parameters for WriteWaveFile are (filename, data, datasize, numchannels, samplerate, bitspersample)

    // Example 1: Write a wave file with no data
    WriteWaveFile("test.wav", NULL, 0, 0, 0, 0);

    // Example 2: Write a wave file with data
    int16_t data[] = {0, 100, 200, 300};
    int32_t dataSize = sizeof(data);
    int16_t numChannels = 2;
    int32_t sampleRate = 44100;
    int16_t bitsPerSample = 16;
    WriteWaveFile("test2.wav", data, dataSize, numChannels, sampleRate, bitsPerSample);

    return 0;
}
