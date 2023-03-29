# DIYSynth
## SMinimalWaveFileHeader
The struct's fields are defined as follows:

# m_szChunkID:
an array of four bytes that contains the ASCII characters "RIFF", indicating that this is a RIFF format WAV file.

# m_nChunkSize:
a 32-bit unsigned integer that specifies the size of the entire file (in bytes) minus 8 bytes, which is the size of the RIFF chunk ID and chunk size fields themselves.

m_szFormat: an array of four bytes that contains the ASCII characters "WAVE", indicating that this is a WAV file.

m_szSubChunk1ID: an array of four bytes that contains the ASCII characters "fmt ", indicating the start of the "fmt" subchunk.

m_nSubChunk1Size: a 32-bit unsigned integer that specifies the size of the "fmt" subchunk (in bytes).

m_nAudioFormat: a 16-bit unsigned integer that specifies the audio format (PCM, IEEE float, etc.).

m_nNumChannels: a 16-bit unsigned integer that specifies the number of audio channels (mono, stereo, etc.).

m_nSampleRate: a 32-bit unsigned integer that specifies the sample rate (number of samples per second).

m_nByteRate: a 32-bit unsigned integer that specifies the byte rate (number of bytes per second).

m_nBlockAlign: a 16-bit unsigned integer that specifies the block alignment (number of bytes per audio frame).

m_nBitsPerSample: a 16-bit unsigned integer that specifies the number of bits per sample.

m_szSubChunk2ID: an array of four bytes that contains the ASCII characters "data", indicating the start of the data subchunk.

m_nSubChunk2Size: a 32-bit unsigned integer that specifies the size of the data subchunk (in bytes).

The #ifndef and #define preprocessor directives at the top of the file are used to prevent multiple definitions of the SMinimalWaveFileHeader struct when this header file is included in multiple source files.

Overall, this code defines a struct that can be used to parse and write the headers of WAV files.
