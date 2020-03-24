#ifndef SITERESPONSE_H
#define SITERESPONSE_H

#include <functional>
#include "EffectiveFEModel.h"
#include "siteLayering.h"
#include "soillayer.h"
#include "outcropMotion.h"

#include "StandardStream.h"
#include "FileStream.h"
#include "OPS_Stream.h"

class SiteResponse {

public:
    SiteResponse(std::string configureFile,std::string anaDir,std::string outDir,std::string femLog, std::function<void(double)> callbackFunction);
    SiteResponse(std::string configureFile,std::string anaDir,std::string outDir,std::string femLog);
	~SiteResponse();

    void init(std::string configureFile,std::string anaDir,std::string outDir);
    int run();
    void buildTcl();
    void buildTcl3D();

    std::function<void(double)> m_callbackFunction;

    FileStream *ferr_true;

	
private:
    SiteResponseModel *model;
    // read the motion
    OutcropMotion motionX;
    OutcropMotion motionZ;
    std::string m_configureFile;
    std::string m_analysisDir;
    std::string m_outputDir;
    std::string m_femLog;

};

#endif
