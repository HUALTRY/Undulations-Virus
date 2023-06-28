#ifndef _EFFECTGENERATOR_
#define _EFFECTGENERATOR_

class ShaderClass;
class EffectGenerator;

typedef void(ShaderClass::*DRAW_SHADER)(int, int, int, PRGBQUAD*, PRGBQUAD*, int, int);

typedef struct
{
	DRAW_SHADER pShader;
	int duration;
	bool block;
	bool renovate;
} EFFECTARRAY;


class ShaderClass
{

private:
	float _x, _y;
	float e;
	float d;
	unsigned int mx, my;
	ImageProcessing imageProcessing;
	ColorConversion colorConversion;
	PRGBQUAD tmpColorDst, tmpColorSrc;
	HSVQUAD hsv;
public:
	ShaderClass()
	{
		_x = 0, _y = 0;
		e = 0;
		d = 0;
		mx = 0, my = 0;
		memset(&tmpColorSrc, 0, sizeof(tmpColorSrc));
		memset(&tmpColorDst, 0, sizeof(tmpColorDst));
		memset(&hsv, 0, sizeof(hsv));
	}
	void DrawShader1(int,int,int,PRGBQUAD*,PRGBQUAD*,int,int);
	void DrawShader2(int,int,int,PRGBQUAD*,PRGBQUAD*,int,int);
	void DrawShader3(int,int,int,PRGBQUAD*,PRGBQUAD*,int,int);
	void DrawShader4(int,int,int,PRGBQUAD*,PRGBQUAD*, int, int);
	void DrawShader5(int,int,int,PRGBQUAD*,PRGBQUAD*, int, int);
	void DrawShader6(int,int,int,PRGBQUAD*,PRGBQUAD*, int, int);
	void DrawShader7(int,int,int,PRGBQUAD*,PRGBQUAD*, int, int);
	void DrawShader8(int,int,int,PRGBQUAD*,PRGBQUAD*, int, int);
	void DrawShader9(int,int,int,PRGBQUAD*,PRGBQUAD*, int, int);
	void DrawShader10(int,int,int,PRGBQUAD*,PRGBQUAD*, int, int);
	void DrawShader11(int,int,int,PRGBQUAD*,PRGBQUAD*, int, int);
	void DrawShader12(int,int,int,PRGBQUAD*,PRGBQUAD*, int, int);
	void DrawShader13(int,int,int,PRGBQUAD*,PRGBQUAD*, int, int);
	void DrawShader14(int,int,int,PRGBQUAD*,PRGBQUAD*, int, int);
	void DrawShader15(int,int,int,PRGBQUAD*,PRGBQUAD*, int, int);
	void DrawShader16(int,int,int,PRGBQUAD*,PRGBQUAD*, int, int);
	void DrawShader17(int,int,int,PRGBQUAD*,PRGBQUAD*, int, int);
	void DrawShader18(int,int,int,PRGBQUAD*,PRGBQUAD*, int, int);
	void DrawShader19(int,int,int,PRGBQUAD*,PRGBQUAD*, int, int);
	void DrawShader20(int,int,int,PRGBQUAD*,PRGBQUAD*, int, int);
};


class EffectGenerator : public ShaderClass
{
private:
	int rndR;
	int rndW,rndH;
	int sW,sH;
	int rndX,rndY;
	DWORD rop[3];
	ShaderClass shCs;
	int64_t nSize;
	HDC hDstDC;
	HBITMAP hBmp;
    BITMAPINFO iBmp;
	DRAW_SHADER pShader;
    PRGBQUAD *colorSrc,*colorDst;
	void EGeneratorProcessing(int, int, HDC, HDC, PRGBQUAD*, PRGBQUAD*, SIZE_T, EFFECTARRAY);
public:
	EffectGenerator()
	{
		rndR = 0;
		rndW = 0, rndH = 0;
		sW = 0, sH = 0;
		rndX = 0, rndY = 0;
		nSize = NULL;
		hDstDC = NULL;
		hBmp = NULL;
		colorSrc = NULL,colorDst = NULL;
		memset(&iBmp, 0, sizeof(iBmp));
		iBmp.bmiHeader.biPlanes = 1;
		iBmp.bmiHeader.biBitCount = 32;
		iBmp.bmiHeader.biCompression = BI_RGB;
		iBmp.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
		memset(&pShader, 0, sizeof(pShader));
		rop[0] = SRCAND; rop[1] = SRCPAINT; rop[2] = SRCINVERT;
	}
	void EGenerator(HDC, int, int, EFFECTARRAY);
};




#endif