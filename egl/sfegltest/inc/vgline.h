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

#ifndef __VGLINE_H__
#define __VGLINE_H__

#include "eglrendering.h"

class CVGLine : public CEGLRendering
    {
public:
    static CEGLRendering* NewL(RWindow& aWindow);
    static const TDesC& Name();

private:
    CVGLine(RWindow& aWindow);
    void KhrSetup();
    void KhrPaint();

private:
    VGPaint iVGPaint;
    VGPath iVGPath;
    };

#endif

