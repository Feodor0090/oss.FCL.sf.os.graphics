// Copyright (c) 2010 Nokia Corporation and/or its subsidiary(-ies).
// All rights reserved.
// This component and the accompanying materials are made available
// under the terms of "Eclipse Public License v1.0"
// which accompanies this distribution, and is available
// at the URL "http://www.eclipse.org/legal/epl-v10.html".
//
// Initial Contributors:
// Nokia Corporation - initial contribution.
//
// Contributors:
//
// Description:

#ifndef __EGLRENDERING_H__
#define __EGLRENDERING_H__

#include <e32base.h>
#include <w32std.h>
#include <EGL/egl.h>
#include <VG/openvg.h>

class CEGLRendering : public CBase
	{
public:
	static CEGLRendering* NewL(RWindow& aWindow);
	~CEGLRendering();

	void Start();
	void Stop();

	void UpdateDisplay();
	static TInt TimerCallBack(TAny* aDemo);

private:
	CEGLRendering(RWindow& aWindow);
	void ConstructL();

    static void EGLCheckError();
    static void EGLCheckReturnError(EGLBoolean aBool);
    static void VGCheckError();
    
    void EglSetupL();
    void VgSetup();
    void VgPaint();
	
private:
	RWindow& iWindow;
	CPeriodic* iTimer;
	CFbsBitmap* iBitmap;
	TInt iCount;
	EGLDisplay iDisplay;
	EGLSurface iSurface;
	EGLContext iContext;
	VGPaint iVGPaint;
	VGPath iVGPath;
	};

#endif

