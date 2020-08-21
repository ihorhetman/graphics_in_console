//
// 2016-10-22 23:35 alkhizha
//
#include "graphics.h"
//#include<iostream>
using namespace Grfx;

   Graphics::Graphics()
   {
	// ������������� �������
        // Initialize GDI+.
        Gdiplus::GdiplusStartupInput gdiplusStartupInput;
        Gdiplus::GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

	hWnd = GetConsoleWindow();
	hDC = GetDC(hWnd);
        gr = new Gdiplus::Graphics(hDC); // Remarks (https://msdn.microsoft.com/en-us/library/ms536160(v=vs.85).aspx):
                                // When you use this constructor to create a Graphics::Graphics object,
                                // make sure that the Graphics::Graphics object is deleted or goes out of scope
                                // before the device context is released
                                // � ���������, ��� ���������� ��������� �������������� �������� ������� �������
                                // ����� ������� - ���� ���������/���������� ������ �����������.
                                // ����� ��������� ������ �� ����� ���������� ��� ������� GdiplusShutdown
        
        Gdiplus::Color blackColor(255, 0, 0, 0);
        gr->Clear(blackColor);
   }
   Graphics::~Graphics()
   {
	delete gr;
        Gdiplus::GdiplusShutdown(gdiplusToken);
	ReleaseDC(hWnd, hDC);
   }	

   void Graphics::setcolor(int c)
   {
        BYTE byRed = 0, byGreen = 0, byBlue = 0;
        byRed = 255*(c&0x4);
        byGreen = 255*(c&0x2);
        byBlue = 255*(c&0x1);
        color = Gdiplus::Color(255, byRed, byGreen, byBlue);
   }

   void Graphics::line(int x, int y, int x2, int y2)
   {
       Gdiplus::Pen      pen  (color);
       gr->DrawLine(&pen, x, y, x2, y2);
   }

   void Graphics::circle(int x, int y, int r)
   {
       Gdiplus::Pen      pen  (color);
       gr->DrawEllipse(&pen, x-r, y-r, r, r);
   }
   void Graphics::rectangle(int x, int y, int x2, int y2)
   {
       Gdiplus::Pen      pen  (color);
       gr->DrawLine(&pen, x, y, x, y2);
       gr->DrawLine(&pen, x, y, x2, y);
       gr->DrawLine(&pen, x2, y, x2, y2);
       gr->DrawLine(&pen, x, y2, x2, y2);
   }

   void Grfx::Graphics::triangle(int x, int y, int x2, int y2, int x3, int y3)
   {
	   Gdiplus::Pen		pen(color);
	   gr->DrawLine(&pen, x, y, x2, y2);
	   gr->DrawLine(&pen, x2, y2, x3, y3);
	   gr->DrawLine(&pen, x, y, x3, y3);
   }
