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
#include <egl/egl.h>
#include <vg/openvg.h>
#include <gles/gl.h>

class CEGLRendering : public CBase
	{
public:
	~CEGLRendering();

	static TInt TimerCallBack(TAny* aDemo);
    void Redraw();

protected:
    CEGLRendering(RWindow& aWindow, EGLenum aApi);
    void ConstructL();
    TSize WindowSize() const;

	void StartRedrawTimer();
	void StopRedrawTimer();

    static void EGLCheckError();
    static void EGLCheckReturnError(EGLBoolean aBool);
    static void VGCheckError();
    static void GLCheckError();

private:
    void EglSetupL();
    virtual void KhrSetup() = 0;
    virtual void KhrPaint() = 0;
    void EglSwapBuffers();

private:
	RWindow& iWindow;
	const EGLenum iApi;
	CPeriodic* iRedrawTimer;
	EGLDisplay iDisplay;
	EGLSurface iSurface;
	EGLContext iContext;
	};

#endif

