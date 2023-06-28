#ifndef _AUDIOGENERATOR_
#define _AUDIOGENERATOR_

#pragma comment(lib,"Winmm.lib")

#define CHANNELS 1
#define BITS_PER_SAMPLE 16
#define PI 3.1415926


typedef struct
{
	DWORD sampleRate;
	DWORD waveLength;
	DWORD musicalNote[30][2];
} AUDIOARRAY;



class AudioGenerator
{
private:
	float temp;
	long int arrayIndex,arrayFlag;
	HWAVEOUT hWout;
	WAVEFORMATEX wFormat;
	WAVEHDR wHdr;
	BYTE *waveData;
	void AudioProcessing(BYTE*,DWORD,AUDIOARRAY,DWORD,long int);
public:
	AudioGenerator()
	{
		temp = 0;
		arrayIndex = 0,arrayFlag = 1;
		waveData = NULL;
		memset(&hWout, 0, sizeof(hWout));
		memset(&wFormat, 0, sizeof(wFormat));
		memset(&wHdr, 0, sizeof(wHdr));
	}
	static bool audioFlag;
	void AGenerator(DWORD,DWORD,AUDIOARRAY, DWORD);
};


#endif