/*
 * (C) 2001-2012 Marmalade. All Rights Reserved.
 *
 * This document is protected by copyright, and contains information
 * proprietary to Marmalade.
 *
 * This file consists of source code released by Marmalade under
 * the terms of the accompanying End User License Agreement (EULA).
 * Please do not use this program/source code before you have read the
 * EULA and have agreed to be bound by its terms.
 */
/*
 * WARNING: this is an autogenerated file and will be overwritten by
 * the extension interface script.
 */
#ifndef S3E_EXT_APPTRACKERIOS_H
#define S3E_EXT_APPTRACKERIOS_H

#include <s3eTypes.h>



enum AppTrackeriOSCallback {
	APPTRACKERIOS_MODULELOADED,
	APPTRACKERIOS_MODULEFAILED,
	APPTRACKERIOS_MODULECLOSED,
	APPTRACKERIOS_MODULECACHED,
	APPTRACKERIOS_MODULECLICKED,
	APPTRACKERIOS_MEDIAFINISHED,
	APPTRACKERIOS_CALLBACK_MAX
};
// \cond HIDDEN_DEFINES
S3E_BEGIN_C_DECL
// \endcond

/**
 * Report if the AppTrackeriOS extension is available.
 * @return S3E_TRUE if the AppTrackeriOS extension is available. S3E_FALSE otherwise.
 */
s3eBool AppTrackeriOSAvailable();

/**
 * Registers a callback to be called for an operating system event.
 *
 * The available callback types are listed in @ref AppTrackeriOSCallback.
 * @param cbid ID of the event for which to register.
 * @param fn callback function.
 * @param userData Value to pass to the @e userData parameter of @e NotifyFunc.
 * @return
 *  - @ref S3E_RESULT_SUCCESS if no error occurred.
 *  - @ref S3E_RESULT_ERROR if the operation failed.\n
 *
 * @see AppTrackeriOSUnRegister
 * @note For more information on the system data passed as a parameter to the callback
 * registered using this function, see the @ref AppTrackeriOSCallback enum.
 * @note It is not necessary to define a return value for any registered callback.
 */
s3eResult AppTrackeriOSRegister(AppTrackeriOSCallback cbid, s3eCallback fn, void* userData);

/**
 * Unregister a callback for a given event.
 * @param cbid ID of the callback to unregister.
 * @param fn Callback Function.
 * @return
 * - @ref S3E_RESULT_SUCCESS if no error occurred.
 * - @ref S3E_RESULT_ERROR if the operation failed.\n
 * @see AppTrackeriOSRegister
 */
s3eResult AppTrackeriOSUnRegister(AppTrackeriOSCallback cbid, s3eCallback fn);

s3eResult AppTrackeriOS_startSession(const char* apiKey);

s3eResult AppTrackeriOS_closeSession();

s3eResult AppTrackeriOS_event(const char* eventName);

s3eResult AppTrackeriOS_eventWithValue(const char* eventName, const char* valueString);

s3eResult AppTrackeriOS_loadModule(const char* location);

s3eResult AppTrackeriOS_loadModuleToCache(const char* location_code);

s3eResult AppTrackeriOS_destroyModule();

s3eResult AppTrackeriOS_fixAdOrientation(int landscape_portrait_or_auto);

s3eResult AppTrackeriOS_setAgeRange(const char* ageRange);

s3eResult AppTrackeriOS_setGender(const char* gender);

bool AppTrackeriOS_isAdReady(const char* placement);

// \cond HIDDEN_DEFINES
S3E_END_C_DECL
// \endcond

#endif /* !S3E_EXT_APPTRACKERIOS_H */
