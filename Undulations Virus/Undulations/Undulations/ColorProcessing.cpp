#include "Undulations.h"


HSVQUAD ColorConversion::RGBToHSV(float R,float G,float B)
{
	H = 0,S = 0,V = 0;
	R /= 255.f;G /= 255.f;B /= 255.f;
	max = MAX(R,MAX(G,B));
	min = MIN(R,MIN(G,B));

	H = (max == min ? 0 : H);
	H = (max == R && G >= B ? H = 60 * ((G - B) / (max - min)) : H);
	H = (max == R && G < B ? 60 * ((G - B) / (max - min)) + 360 : H);
	H = (max == G ? 60 * ((B - R) / (max - min)) + 120 : H);
	H = (max == B ? 60 * ((R - G) / (max - min)) + 240 : H);
	S = (max == 0? 0 : 1 - (min / max));
	V = max;

	hsvColor.h = H / 360.f;
	hsvColor.s = S;
	hsvColor.v = V;
	return hsvColor;

}


PRGBQUAD ColorConversion::HSVToRGB(float H,float S,float V)
{
	R = 0,G = 0,B = 0;
	_H = H * 360.f;
	F = 0,P = 0,Q = 0,T = 0;
    if(S == 0)
	{
		R = G = B = V;
	}
	else
	{
		_H = _H / 60;
		F = _H - (int)_H;
		P = V * (1 - S);
		Q = V * (1 - F * S);
		T = V * (1 - (1 - F) * S);
        switch((int)_H)
		{
            case 0 : R = V; G = T; B = P; break;
            case 1 : R = Q; G = V; B = P; break;
            case 2 : R = P; G = V; B = T; break;
            case 3 : R = P; G = Q; B = V; break;
            case 4 : R = T; G = P; B = V; break;
            case 5 : R = V; G = P; B = Q; break;
        }
	}

	rgbColor.r = (unsigned char)(R * 255.f + 0.5f);
	rgbColor.g = (unsigned char)(G * 255.f + 0.5f);
	rgbColor.b = (unsigned char)(B * 255.f + 0.5f);
	return rgbColor;

}