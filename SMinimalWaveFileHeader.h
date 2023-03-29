#ifndef SMINIMALWAVEFILEHEADER_H
#define SMINIMALWAVEFILEHEADER_H

#include <stdint.h>
#include <stdio.h>
#include <string.h>

// This struct is the minimal required header for a WAV file.
struct SMinimalWaveFileHeader
{
    // The main chunk.
    unsigned char m_szChunkID[4];
    uint32_t m_nChunkSize;
    unsigned char m_szFormat[4];

    // Subchunk 1 "fmt".
    unsigned char m_szSubChunk1ID[4];
    uint32_t m_nSubChunk1Size;
    uint16_t m_nAudioFormat;
    uint16_t m_nNumChannels;
    uint32_t m_nSampleRate;
    uint32_t m_nByteRate;
    uint16_t m_nBlockAlign;
    uint16_t m_nBitsPerSample;

    // Subchunk 2 "data".
    unsigned char m_szSubChunk2ID[4];
    uint32_t m_nSubChunk2Size;

    // Then comes the data...
};

#endif // SMINIMALWAVEFILEHEADER_H
