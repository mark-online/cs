/**
* Copyright (c) 2011 Enel Studio.
*
* @author Kim ByeongSu <kcando@enel.co.kr>
*/
#include "stdafx.h"
#include "ScreenShot.h"
#include "FileSystem.h"
#include <windowsx.h>

namespace esut
{

ScreenShot::ScreenShot() :
    bmpInfo_(NULL),
    bitsArray_(NULL),
    bmpHdrSize_(0),
    bitsArraySize_(0)
{
	const HDC hDisplayDC = CreateDC(_T("DISPLAY"), NULL, NULL, NULL);
	if (hDisplayDC == NULL) {
        return;
    }

    bool bResult = false;
	const int nWidth = GetDeviceCaps(hDisplayDC, HORZRES);
	const int nHeight = GetDeviceCaps(hDisplayDC, VERTRES);
	HBITMAP hBitmap = CreateCompatibleBitmap(hDisplayDC, nWidth, nHeight);
	if (hBitmap != NULL) {
		const HDC hMemDC = CreateCompatibleDC(hDisplayDC);
		if (hMemDC) {
			const HBITMAP hbmpSafeBitmap = SelectBitmap(hMemDC, hBitmap);
			BitBlt(hMemDC, 0, 0, nWidth, nHeight, hDisplayDC, 0, 0, SRCCOPY);

			BITMAP bmpInfo;
			GetObject(hBitmap, sizeof(bmpInfo), &bmpInfo);
			WORD wPalSize = 0;
            WORD wBmpBits = bmpInfo.bmPlanes * bmpInfo.bmBitsPixel;
			if (wBmpBits <= 1) {
				wBmpBits = 1;  // monochrome image
				wPalSize = 2;
			}
			else if (wBmpBits <= 4) {
				wBmpBits = 4;  // palette-based 4 bpp image
				wPalSize = 16;
			}
			else if (wBmpBits <= 8) {
				wBmpBits = 8;  // palette-based 8 bpp image
				wPalSize = 256;
			}
			else {
				wBmpBits = 16; // force to 16 bpp image (don't allow 24 bpp)
				wPalSize = 0;  // don't use palette
			}

			bmpHdrSize_ = sizeof(BITMAPINFOHEADER) + wPalSize * sizeof(RGBQUAD);
			bmpInfo_ = (PBITMAPINFO)new BYTE[bmpHdrSize_];
			ZeroMemory(bmpInfo_, bmpHdrSize_);
			BITMAPINFOHEADER& bmpHdr = bmpInfo_->bmiHeader;
			bmpHdr.biSize = sizeof(bmpHdr);
			bmpHdr.biWidth = nWidth;
			bmpHdr.biHeight = nHeight;
			bmpHdr.biPlanes = 1;
			bmpHdr.biBitCount = wBmpBits;
			bmpHdr.biCompression = BI_RGB;

			// call GetDIBits with a NULL bits array,
            // so it will calculate the biSizeImage field
			GetDIBits(hMemDC, hBitmap, 0, nHeight, NULL, bmpInfo_,
                DIB_RGB_COLORS);
            if (bmpHdr.biSizeImage == 0) {
				bmpHdr.biSizeImage =
                    (wBmpBits * nWidth + 31) / 32 * 4 * nHeight;
            }
			bitsArraySize_ = bmpHdr.biSizeImage;
			bitsArray_ = new BYTE[bitsArraySize_];
            if (GetDIBits(hMemDC, hBitmap, 0, nHeight, bitsArray_, bmpInfo_,
                DIB_RGB_COLORS)) {
				bResult = true;
			}

			SelectBitmap(hMemDC, hbmpSafeBitmap);
			DeleteDC(hMemDC);
		}
		DeleteBitmap(hBitmap);
	}
	DeleteDC(hDisplayDC);

	if (! bResult) {
        reset();
	}
}


ScreenShot::~ScreenShot()
{
    reset();
}


bool ScreenShot::capture(const std::string& filename)
{
    if (! bmpInfo_) {
		return false;
    }

    File file(filename, "wb");
    if (! file.isOpened()) {
        return false;
    }

    BITMAPFILEHEADER bmpfh;
    ZeroMemory(&bmpfh, sizeof(bmpfh));
    bmpfh.bfType = 'MB';
    bmpfh.bfOffBits = sizeof(bmpfh) + bmpHdrSize_;
    bmpfh.bfSize = bmpfh.bfOffBits + bitsArraySize_;
    file.write(&bmpfh, sizeof(bmpfh));
    file.write(bmpInfo_, bmpHdrSize_);
    file.write(bitsArray_, bitsArraySize_);
    return true;
}


void ScreenShot::reset()
{
    delete[] (PBYTE)bitsArray_;
    bitsArray_ = NULL;
    delete[] (PBYTE)bmpInfo_;
    bmpInfo_ = NULL;

    bmpHdrSize_ = 0;
    bitsArraySize_ = 0;
}

} // namespace esut
