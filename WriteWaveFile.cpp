#include "SMinimalWaveFileHeader.cpp"
#include <string.h>

bool WriteWaveFile(const char *szFileName, void *pData, int32_t nDataSize, int16_t nNumChannels,
                   int32_t nSampleRate, int32_t nBitsPerSample)
{
    // open the file if we can
    FILE *File = fopen(szFileName, "w+b");
    if (!File)
    {
        return false;
    }

    // write the header
    SMinimalWaveFileHeader waveHeader;
  
    //fill out the main chunk
	memcpy(waveHeader.m_szChunkID,"RIFF",4);
	waveHeader.m_nChunkSize = nDataSize + 36;
	memcpy(waveHeader.m_szFormat,"WAVE",4);

	//fill out sub chunk 1 "fmt "
	memcpy(waveHeader.m_szSubChunk1ID,"fmt ",4);
	waveHeader.m_nSubChunk1Size = 16;
	waveHeader.m_nAudioFormat = 1;
	waveHeader.m_nNumChannels = nNumChannels;
	waveHeader.m_nSampleRate = nSampleRate;
	waveHeader.m_nByteRate = nSampleRate * nNumChannels * nBitsPerSample / 8;
	waveHeader.m_nBlockAlign = nNumChannels * nBitsPerSample / 8;
	waveHeader.m_nBitsPerSample = nBitsPerSample;

	//fill out sub chunk 2 "data"
	memcpy(waveHeader.m_szSubChunk2ID,"data",4);
	waveHeader.m_nSubChunk2Size = nDataSize;

	//write the header
	fwrite(&waveHeader,sizeof(SMinimalWaveFileHeader),1,File);

	//write the wave data itself
	fwrite(pData,nDataSize,1,File);

	//close the file and return success
	fclose(File);
	return true;
}
