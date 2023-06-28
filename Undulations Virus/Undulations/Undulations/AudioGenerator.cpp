#include "Undulations.h"

bool AudioGenerator::audioFlag = true;

void AudioGenerator::AudioProcessing(BYTE *waveData,DWORD waveLength,AUDIOARRAY musicalNote,DWORD mnLength,long int waveSpeed)
{
	arrayIndex = 0,arrayFlag = 1;

	for (DWORD index = 0; index < waveLength; index++)
	{
		arrayIndex = (arrayIndex == (mnLength - 1) ? -arrayIndex : arrayIndex);
		arrayFlag = (arrayFlag > waveSpeed ? 1 : arrayFlag);
		temp = (float)((PI * musicalNote.musicalNote[abs(arrayIndex)][1]) / musicalNote.musicalNote[abs(arrayIndex)][0]);
		waveData[index] = (BYTE)(127 + (sin(temp * index) * 127));

		if(arrayFlag == waveSpeed)
		{
			arrayIndex++;
		}
		arrayFlag++;
	}
}

void AudioGenerator::AGenerator(DWORD sampleRate, DWORD waveLength,AUDIOARRAY musicalNote, DWORD mnLength)
{
	audioFlag = true;
	waveData = new BYTE[waveLength];
	ZeroMemory(waveData, waveLength);

	wFormat.nSamplesPerSec = sampleRate;
	wFormat.nChannels = CHANNELS;
	wFormat.wBitsPerSample = BITS_PER_SAMPLE;
	wFormat.nBlockAlign = 2;
	wFormat.wFormatTag = WAVE_FORMAT_PCM;
	wFormat.nAvgBytesPerSec = wFormat.nSamplesPerSec * 2;

	wHdr.lpData = (LPSTR)waveData;
	wHdr.dwBufferLength = waveLength;
	wHdr.dwFlags = NULL;
	wHdr.dwLoops = NULL;

	waveOutOpen(&hWout,WAVE_MAPPER,&wFormat,NULL,0,CALLBACK_NULL);
	waveOutPrepareHeader(hWout,&wHdr,sizeof(wHdr));
	AudioProcessing(waveData,waveLength,musicalNote,mnLength,2000);

	while(audioFlag)
	{
		waveOutWrite(hWout,&wHdr,sizeof(wHdr));
		Sleep(1);
	}

	waveOutReset(hWout);
	waveOutUnprepareHeader(hWout,&wHdr,sizeof(wHdr));
	waveOutClose(hWout);
	delete[] waveData;
}