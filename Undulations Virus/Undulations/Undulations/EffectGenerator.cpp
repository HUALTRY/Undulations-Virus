#include "Undulations.h"



void ShaderClass::DrawShader1(int width, int height, int step, PRGBQUAD* pColorDst, PRGBQUAD* pColorSrc, int x, int y)
{
	pColorDst[y * width + x].r &= ~(int)(sin(x) * (step * 10.f));
	pColorDst[y * width + x].g &= ~pColorSrc[y * width + x].r;
	pColorDst[y * width + x].b &= ~pColorSrc[y * width + x].r;
}


void ShaderClass::DrawShader2(int width, int height, int step, PRGBQUAD* pColorDst, PRGBQUAD* pColorSrc, int x, int y)
{
	pColorDst[y * width + x].r &= ~pColorSrc[y * width + x].g;
	pColorDst[y * width + x].g &= ~(int)(sin(y) * (step * 10.f));
	pColorDst[y * width + x].b &= ~pColorSrc[y * width + x].g;
}


void ShaderClass::DrawShader3(int width, int height, int step, PRGBQUAD* pColorDst, PRGBQUAD* pColorSrc, int x, int y)
{
	mx = 0, my = 0;
	d = imageProcessing.GetDistance(
		(float)x,
		(float)y,
		(float)width,
		(float)height,
		false
	);

	imageProcessing.Wave(
		20.f,
		d,
		height / 35.f,
		(float)step,
		&_x,
		&_y,
		true
	);

	mx += x + (unsigned int)_x; my += y + (unsigned int)_y;
	mx %= width; my %= height;

	pColorDst[y * width + x].r = pColorSrc[my * width + mx].b;
	pColorDst[y * width + x].g = pColorSrc[my * width + mx].b;
	pColorDst[y * width + x].b &= ((int)(sin(y) * (step * 10.f)) + (long)_x) + (long)_y;
}


void ShaderClass::DrawShader4(int width, int height, int step, PRGBQUAD* pColorDst, PRGBQUAD* pColorSrc, int x, int y)
{
	e = (float)(pow(x - (width / 2.f), 2.f) + pow(y - (height / 2.f), 2.f));
	pColorDst[y * width + x].rgb &= (pColorSrc[y * width + x].r ^
		((int)e + step) | pColorSrc[y * width + x].g) &
		pColorSrc[y * width + x].b + (int)e;
}


void ShaderClass::DrawShader5(int width, int height, int step, PRGBQUAD* pColorDst, PRGBQUAD* pColorSrc, int x, int y)
{
	mx = 0, my = 0;
	d = imageProcessing.GetDistance(
		(float)x,
		(float)y,
		(float)width,
		(float)height,
		false
	);

	imageProcessing.Convex(
		(float)x,
		(float)y,
		(float)width,
		(float)height,
		0.3f,
		d,
		&_x,
		&_y
	);

	tmpColorDst = pColorSrc[y * width + x];

	hsv = colorConversion.RGBToHSV(
		tmpColorDst.r,
		tmpColorDst.g,
		tmpColorDst.b
	);

	hsv.h = (hsv.h < 1.f ? hsv.h += 0.01f : 0);
	hsv.s = 1.f; hsv.v = 1.f;

	tmpColorDst = colorConversion.HSVToRGB(
		hsv.h,
		hsv.s,
		hsv.v
	);

	mx = (unsigned int)((_x > 0 && _x < width) && (_y > 0 && _y < height) ? _x : 0);
	my = (unsigned int)((_x > 0 && _x < width) && (_y > 0 && _y < height) ? _y : 0);

	mx %= width; my %= height;

	pColorDst[y * width + x].r = (pColorDst[y * width + x].r > 0x7F ?
		pColorSrc[my * width + mx].r :
		tmpColorDst.r);
	pColorDst[y * width + x].g = (pColorDst[y * width + x].g > 0x7F ?
		pColorSrc[my * width + mx].g :
		tmpColorDst.g);
	pColorDst[y * width + x].b = (pColorDst[y * width + x].b > 0x7F ?
		pColorSrc[my * width + mx].b :
		tmpColorDst.b);
}


void ShaderClass::DrawShader6(int width, int height, int step, PRGBQUAD* pColorDst, PRGBQUAD* pColorSrc, int x, int y)
{
	mx = 0, my = 0;
	d = imageProcessing.GetDistance(
		(float)x,
		(float)y,
		(float)width,
		(float)height,
		true
	);

	imageProcessing.Wave(
		5.f,
		d,
		height / 10.f,
		(float)step,
		&_x,
		&_y,
		false
	);

	mx += x + (unsigned int)_x; my += y + (unsigned int)_y;
	mx %= width; my %= height;

	pColorDst[y * width + x].r = (unsigned int)pColorSrc[my * width + mx].rgb;
	pColorDst[y * width + x].g = (pColorSrc[my * width + mx].r & step);
	pColorDst[y * width + x].b = (pColorSrc[my * width + mx].r & step);
}


void ShaderClass::DrawShader7(int width, int height, int step, PRGBQUAD* pColorDst, PRGBQUAD* pColorSrc, int x, int y)
{
	e = (float)(pow(x - (width / 2.f), 2.f) + pow(y - (height / 2.f), 2.f));
	pColorDst[y * width + x].r += (pColorSrc[y * width + x].b ^ step) & (int)e;
	pColorDst[y * width + x].g += (pColorSrc[y * width + x].b ^ step) & (int)e;
	pColorDst[y * width + x].b &= (unsigned int)pColorSrc[y * width + x].rgb | (int)e;
}


void ShaderClass::DrawShader8(int width, int height, int step, PRGBQUAD* pColorDst, PRGBQUAD* pColorSrc, int x, int y)
{
	mx = 0, my = 0;
	d = imageProcessing.GetDistance(
		(float)x,
		(float)y,
		(float)width,
		(float)height,
		true
	);

	imageProcessing.Wave(
		10.f,
		d,
		height / 20.f,
		(float)step,
		&_x,
		&_y,
		false
	);

	mx += x + (unsigned int)_x; my += y + (unsigned int)_y;
	mx %= width; my %= height;

	pColorDst[y * width + x].rgb = pColorSrc[my * width + mx].rgb |
		RGB(((pColorSrc[my * width + mx].g >> 5) + (int)step) ^ (int)(_x + _y),
			((pColorSrc[my * width + mx].b >> 5) + (int)step) & (int)(_x + _y),
			((pColorSrc[my * width + mx].r >> 5) + (int)step) & (int)(_x + _y));
}


void ShaderClass::DrawShader9(int width, int height, int step, PRGBQUAD* pColorDst, PRGBQUAD* pColorSrc, int x, int y)
{
	mx = 0, my = 0;
	d = imageProcessing.GetDistance(
		(float)x,
		(float)y,
		(float)width,
		(float)height,
		false
	);

	imageProcessing.Wave(
		10.f,
		d,
		height / 50.f,
		(float)step,
		&_x,
		&_y,
		true
	);

	mx += x + (unsigned int)_x; my += y + (unsigned int)_y;
	mx %= width; my %= height;

	pColorDst[y * width + x].r = pColorSrc[my * width + mx].r + (int)(_x + _y);
	pColorDst[y * width + x].g = pColorSrc[my * width + mx].g & (int)(_x + _y);
	pColorDst[y * width + x].b = pColorSrc[my * width + mx].b + (int)(_x + _y);
}


void ShaderClass::DrawShader10(int width, int height, int step, PRGBQUAD* pColorDst, PRGBQUAD* pColorSrc, int x, int y)
{
	mx = 0, my = 0;
	d = imageProcessing.GetDistance(
		(float)x,
		(float)y,
		(float)width,
		(float)height,
		false
	);

	imageProcessing.Concave(
		(float)x,
		(float)y,
		(float)width,
		(float)height,
		0.2f,
		d,
		&_x,
		&_y
	);

	mx = (unsigned int)((_x > 0 && _x < width) && (_y > 0 && _y < height) ? _x : 0);
	my = (unsigned int)((_x > 0 && _x < width) && (_y > 0 && _y < height) ? _y : 0);
	mx %= width; my %= height;

	pColorDst[y * width + x].rgb = RGB(
		(pColorSrc[my * width + mx].r & pColorSrc[my * width + mx].b) >> 2,
		((pColorSrc[my * width + mx].g | pColorSrc[my * width + mx].r) >> 2) & pColorDst[y * width + x].rgb,
		pColorSrc[my * width + mx].b ^ pColorSrc[my * width + mx].g
	);
}


void ShaderClass::DrawShader11(int width, int height, int step, PRGBQUAD* pColorDst, PRGBQUAD* pColorSrc, int x, int y)
{
	mx = 0, my = 0;
	d = imageProcessing.GetDistance(
		(float)x,
		(float)y,
		(float)width,
		(float)height,
		false
	);

	imageProcessing.Wave(
		10.f,
		d,
		height / 50.f,
		(float)step,
		&_x,
		&_y,
		true
	);

	mx += x + (unsigned int)_x; my += y + (unsigned int)_y;
	mx %= width; my %= height;

	tmpColorDst = pColorSrc[my * width + mx];

	hsv = colorConversion.RGBToHSV(
		tmpColorDst.r,
		tmpColorDst.g,
		tmpColorDst.b
	);

	hsv.h = (float)fmod(hsv.h + step / 100.f, 1.f);
	hsv.s = (hsv.s == tmpColorDst.g / 255.f ? 1.f : 0.5f);
	hsv.v = (hsv.v == tmpColorDst.b / 255.f ? 1.f : 0.5f);

	pColorDst[y * width + x] = colorConversion.HSVToRGB(
		hsv.h,
		hsv.s,
		hsv.v
	);
}


void ShaderClass::DrawShader12(int width, int height, int step, PRGBQUAD* pColorDst, PRGBQUAD* pColorSrc, int x, int y)
{
	mx = 0, my = 0;
	d = imageProcessing.GetDistance(
		(float)x,
		(float)y,
		(float)width,
		(float)height,
		false
	);

	imageProcessing.Wave(
		10.f,
		d,
		height / 25.f,
		(float)step,
		&_x,
		&_y,
		true
	);

	mx += x + (unsigned int)_x; my += y + (unsigned int)_y;
	mx %= width; my %= height;

	pColorDst[y * width + x].rgb = ~(pColorSrc[my * width + mx].r &
		pColorSrc[my * width + mx].g ^ pColorSrc[my * width + mx].b) ^
		((unsigned int)pColorSrc[my * width + mx].rgb >> 2);
}


void ShaderClass::DrawShader13(int width, int height, int step, PRGBQUAD* pColorDst, PRGBQUAD* pColorSrc, int x, int y)
{
	mx = 0, my = 0;
	d = imageProcessing.GetDistance(
		(float)x,
		(float)y,
		(float)width,
		(float)height,
		false
	);

	imageProcessing.Wave(
		10.f,
		d,
		height / 20.f,
		(float)step,
		&_x,
		&_y,
		true
	);

	mx += x + (unsigned int)_x; my += y + (unsigned int)_y;
	mx %= width; my %= height;

	pColorDst[y * width + x].r += ~(pColorSrc[my * width + mx].b & mx >> 2) & (int)_x;
	pColorDst[y * width + x].g &= (int)(_x + _y) & (pColorSrc[my * width + mx].rgb & ((int)_y >> 2));
	pColorDst[y * width + x].b += ~(pColorSrc[my * width + mx].b & my >> 2) & (int)_y;
}


void ShaderClass::DrawShader14(int width, int height, int step, PRGBQUAD* pColorDst, PRGBQUAD* pColorSrc, int x, int y)
{
	mx = 0, my = 0;
	d = imageProcessing.GetDistance(
		(float)x,
		(float)y,
		(float)width,
		(float)height,
		false
	);

	imageProcessing.Wave(
		10.f,
		d,
		height / 20.f,
		(float)step,
		&_x,
		&_y,
		true
	);

	mx += x + (unsigned int)_x; my += y + (unsigned int)_y;
	mx %= width; my %= height;

	pColorDst[y * width + x].r = pColorSrc[my * width + mx].b & ~(int)_x;
	pColorDst[y * width + x].g = pColorSrc[my * width + mx].b & ~(int)_y;
	pColorDst[y * width + x].b ^= ~pColorDst[y * width + x].rgb | ((int)(_x + _y) >> 2);
}


void ShaderClass::DrawShader15(int width, int height, int step, PRGBQUAD* pColorDst, PRGBQUAD* pColorSrc, int x, int y)
{
	mx = 0, my = 0;
	d = imageProcessing.GetDistance(
		(float)x,
		(float)y,
		(float)width,
		(float)height,
		false
	);

	imageProcessing.Convex(
		(float)x,
		(float)y,
		(float)width,
		(float)height,
		0.3f,
		d,
		&_x,
		&_y
	);

	mx = (unsigned int)((_x > 0 && _x < width) && (_y > 0 && _y < height) ? _x : 0);
	my = (unsigned int)((_x > 0 && _x < width) && (_y > 0 && _y < height) ? _y : 0);
	mx %= width; my %= height;

	tmpColorDst = pColorSrc[my * width + mx];

	hsv = colorConversion.RGBToHSV(
		tmpColorDst.r,
		tmpColorDst.g,
		tmpColorDst.b
	);

	hsv.h = (float)fmod(hsv.h + step / 100.f, 1.f);
	hsv.s = (float)fmod(hsv.s + step / 100.f, 1.f);
	hsv.v = 1.f;

	pColorDst[y * width + x] = colorConversion.HSVToRGB(
		hsv.h,
		hsv.s,
		hsv.v
	);
}


void ShaderClass::DrawShader16(int width, int height, int step, PRGBQUAD* pColorDst, PRGBQUAD* pColorSrc, int x, int y)
{
	mx = 0, my = 0;
	d = imageProcessing.GetDistance(
		(float)x,
		(float)y,
		(float)width,
		(float)height,
		false
	);

	imageProcessing.Wave(
		10.f,
		d,
		height / 50.f,
		(float)step,
		&_x,
		&_y,
		true
	);

	mx += x + (unsigned int)_x; my += y + (unsigned int)_y;
	mx %= width; my %= height;

	pColorDst[y * width + x].r &= pColorSrc[my * width + x].r | (int)_x;
	pColorDst[y * width + x].g &= pColorSrc[y * width + mx].g | (int)_y;
	pColorDst[y * width + x].b = pColorSrc[my * width + mx].b ^ (pColorSrc[my * width + mx].r & pColorSrc[my * width + mx].r);
}


void ShaderClass::DrawShader17(int width, int height, int step, PRGBQUAD* pColorDst, PRGBQUAD* pColorSrc, int x, int y)
{
	e = (float)atan2(sin(x) * 10.f, cos(y) * 10.f) * 10.f;
	pColorDst[y * width + x].rgb = ((pColorSrc[y * width + x].g + int(e)) &
		((int)e + step) + pColorSrc[y * width + x].r) &
		(pColorSrc[y * width + x].b + (int)e);
}


void ShaderClass::DrawShader18(int width, int height, int step, PRGBQUAD* pColorDst, PRGBQUAD* pColorSrc, int x, int y)
{
	e = (float)atan2(sin(x) * 10.f, cos(y) * 10.f) * 20.f;

	tmpColorDst = pColorSrc[y * width + x];

	hsv = colorConversion.RGBToHSV(
		tmpColorDst.r,
		tmpColorDst.g,
		tmpColorDst.b
	);

	hsv.h = (float)fmod(hsv.h + step / 100.f, 1.f);
	hsv.s = (float)fmod(hsv.s + e / 100.f, 1.f);
	hsv.v = (float)fmod(hsv.s + step / 100.f, 1.f);

	pColorDst[y * width + x] = colorConversion.HSVToRGB(
		hsv.h,
		hsv.s,
		hsv.v
	);
}


void ShaderClass::DrawShader19(int width, int height, int step, PRGBQUAD* pColorDst, PRGBQUAD* pColorSrc, int x, int y)
{
	mx = 0, my = 0;
	d = imageProcessing.GetDistance(
		(float)x,
		(float)y,
		(float)width,
		(float)height,
		false
	);
	imageProcessing.Wave(
		10.f,
		d,
		height / 20.f,
		(float)step,
		&_x,
		&_y,
		true
	);


	e = (float)atan2(sin(x) * 10.f, cos(y) * 10.f) * 20.f;

	mx += x + (unsigned int)_x; my += y + (unsigned int)_y;
	mx %= width; my %= height;

	pColorDst[y * width + x].r = (pColorSrc[my * width + mx].b & mx >> 2) & (int)e;
	pColorDst[y * width + x].g = (unsigned int)pColorDst[y * width + x].rgb | (my >> 2) & (int)e;
	pColorDst[y * width + x].b = pColorSrc[my * width + mx].g & (int)e;
}


void ShaderClass::DrawShader20(int width, int height, int step, PRGBQUAD* pColorDst, PRGBQUAD* pColorSrc, int x, int y)
{
	mx = 0, my = 0;
	d = imageProcessing.GetDistance(
		(float)x,
		(float)y,
		(float)width,
		(float)height,
		false
	);

	imageProcessing.Concave(
		(float)x,
		(float)y,
		(float)width,
		(float)height,
		0.2f,
		d,
		&_x,
		&_y
	);

	mx = (unsigned int)((_x > 0 && _x < width) && (_y > 0 && _y < height) ? _x : 0);
	my = (unsigned int)((_x > 0 && _x < width) && (_y > 0 && _y < height) ? _y : 0);
	mx %= width; my %= height;

	tmpColorDst = pColorSrc[my * width + mx];

	hsv = colorConversion.RGBToHSV(
		tmpColorDst.r,
		tmpColorDst.g,
		tmpColorDst.b
	);

	hsv.h = (float)fmod(hsv.h + step / 100.f, 1.f);
	hsv.s = 1.f;
	hsv.v = (float)fmod(hsv.v + step / 100.f, 1.f);

	pColorDst[y * width + x] = colorConversion.HSVToRGB(
		hsv.h,
		hsv.s,
		hsv.v
	);
}



void EffectGenerator::EGeneratorProcessing(int width, int height, HDC hDstDC, HDC hSrcDC,PRGBQUAD* colorDst, PRGBQUAD* colorSrc, SIZE_T nSize, EFFECTARRAY EffectProcess)
{
	pShader = EffectProcess.pShader;
	for (int index = 0; index < EffectProcess.duration; index++)
	{
		sW = (width / 5);
		sH = (height / 5);

		Sleep(10);

		BitBlt(hDstDC, 0, 0, width, height, hSrcDC, 0, 0, SRCCOPY);
		memcpy(colorSrc, colorDst, nSize);
		for (int x = 0; x < width; x++)
		{
			for (int y = 0; y < height; y++)
			{
				(shCs.*pShader)(width, height, index, colorDst, colorSrc, x, y);
			}
		}
		BitBlt(hSrcDC, 0, 0, width, height, hDstDC, 0, 0, SRCCOPY);

		if (EffectProcess.block)
		{
			for (int y = 0; y < 10; y++)
			{
				rndR = rand() % 3;

				rndW = rand() % width;
				rndH = rand() % height;

				rndX = rand() % 15 - 7;
				rndY = rand() % 15 - 7;

				BitBlt(
					hSrcDC,
					rndW + rndX, rndH + rndY,
					sW, sH,
					hSrcDC,
					rndW, rndH,
					rop[rndR]
				);
				BitBlt(
					hSrcDC,
					rndW + rndX, rndH + rndY,
					sW + rndX, sH + rndY,
					hSrcDC,
					rndW, rndH,
					SRCCOPY
				);
			}
		}
	}

	if (EffectProcess.renovate)
	{
		Sleep(100);
		RedrawWindow(NULL, NULL, NULL, RDW_INVALIDATE | RDW_ERASE | RDW_ALLCHILDREN);
	}
}


void EffectGenerator::EGenerator(HDC hSrcDC, int width, int height, EFFECTARRAY EffectProcess)
{
	iBmp.bmiHeader.biWidth = width;
	iBmp.bmiHeader.biHeight = height;
	nSize = static_cast<int64_t>(width * height) * sizeof(COLORREF);

	colorSrc = new PRGBQUAD[(unsigned int)nSize];
	ZeroMemory(colorSrc, (SIZE_T)nSize);

	hDstDC = CreateCompatibleDC(hSrcDC);
	hBmp = CreateDIBSection(hDstDC, &iBmp, DIB_RGB_COLORS, (void**)&colorDst, NULL, 0);
	if (hBmp != NULL)
	{
		SelectObject(hDstDC, hBmp);
		EGeneratorProcessing(width, height,hDstDC, hSrcDC,  colorDst, colorSrc,(SIZE_T)nSize, EffectProcess);
	}

	DeleteObject(&hBmp);
	DeleteDC(hDstDC);
	delete[]colorSrc;
}