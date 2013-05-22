/*  Copyright 2011 AIT Austrian Institute of Technology
*
*   This file is part of OpenTLD.
*
*   OpenTLD is free software: you can redistribute it and/or modify
*   it under the terms of the GNU General Public License as published by
*    the Free Software Foundation, either version 3 of the License, or
*   (at your option) any later version.
*
*   OpenTLD is distributed in the hope that it will be useful,
*   but WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*   GNU General Public License for more details.
*
*   You should have received a copy of the GNU General Public License
*   along with OpenTLD.  If not, see <http://www.gnu.org/licenses/>.
*
*/

/*
 * main.h
 *
 *  Created on: Nov 18, 2011
 *      Author: Georg Nebehay
 */

#ifndef TLDINTERFACE_H_
#define TLDINTERFACE_H_

#include "TLD.h"
#include "ImAcq.h"
#include "Gui.h"
#include <iostream>

using namespace  std;

using namespace libface;

enum Retval
{
    PROGRAM_EXIT = 0,
    SUCCESS = 1
};

class tldinterface
{
public:
    tld::TLD *tld;
    ImAcq *imAcq;
    tld::Gui *gui;
    bool showOutput;
    const char *printResults;
    const char *saveDir;
    double threshold;
    bool showForeground;
    bool showNotConfident;
    bool selectManually;
    int *initialBB;
    bool reinit;
    bool exportModelAfterRun;
    bool loadModel;
    const char *modelPath;
    const char *modelExportFile;
    int seed;

    IplImage *tmpFace;
    const char *haarCascadePath;
    CvSeq *allFaces;
    CvMemStorage *tmpStorageFaceDetect;
    CvHaarClassifierCascade *faceDetectCascade;

    tldinterface()
    {
        tld = new tld::TLD();
        showOutput = 0;
        printResults = NULL;
        saveDir = ".";
        threshold = 0.5;
        showForeground = 0;

        selectManually = 0;

        initialBB = NULL;
        showNotConfident = true;

        reinit = 0;

        loadModel = false;

        exportModelAfterRun = false;
        modelExportFile = "model";
        seed = 0;
    }

    ~tldinterface()
    {
        delete tld;
        imAcqFree(imAcq);
    }
    pair<unitFaceModel *,IplImage *> generatefacemodel();
    pair<float,QString> getrecognitionconfidence(QList<unitFaceModel *> );
};

#endif /* TLDINTERFACE_H_ */
