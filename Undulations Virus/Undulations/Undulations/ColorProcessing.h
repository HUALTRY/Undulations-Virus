#ifndef _COLORPROCESSING_
#define _COLORPROCESSING_


#define MAX(X,Y) (X > Y? X : Y)
#define MIN(X,Y) (X < Y? X : Y)


typedef union
{
	struct
	{
		unsigned char r;
		unsigned char g;
		unsigned char b;
		unsigned char unused;
	};
	COLORREF rgb;
}PRGBQUAD;


typedef struct
{
	float h;
	float s;
	float v;
}HSVQUAD;


class ColorConversion
{
private:
	HSVQUAD hsvColor;
	PRGBQUAD rgbColor;
	float R,G,B;
	float H,S,V;
	float max,min;
	float _H;
	float F,P,Q,T;
public:
	ColorConversion()
	{
		R = 0,G = 0,B = 0;
		H = 0,S = 0,V = 0;
		max = 0,min = 0;
		_H = 0;
		F = 0,P = 0,Q = 0,T = 0;
		memset(&hsvColor, 0, sizeof(hsvColor));
		memset(&rgbColor, 0, sizeof(rgbColor));
	}
	HSVQUAD RGBToHSV(float,float,float);
	PRGBQUAD HSVToRGB(float,float,float);
};



#endif