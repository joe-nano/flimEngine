#pragma once
#ifndef CAMERAMANAGER_H
#define CAMERAMANAGER_H

#include "AzulCore.h"
#include "err.h"

class CameraManager
{
private:


	Camera * currentCam;
	Camera * p2DCam;

public:

	//big four

	CameraManager();
	CameraManager(const CameraManager&) = delete;
	CameraManager& operator=(const CameraManager&) = delete;
	~CameraManager() { /*DebugMsg::out("Camera Manager cleaned\n");*/ };

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	errcode CameraManager::InitCamera();
	///
	/// \brief	Initializes the camera.
	///
	/// \author	Jack Campbell
	/// \date	3/5/2017
	///
	/// \return	An errcode.
	////////////////////////////////////////////////////////////////////////////////////////////////////

	errcode InitCamera();

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	errcode CameraManager::InitCamera(Camera* out);
	///
	/// \brief	Initializes the camera and passes it to the value.
	///
	/// \author	Jack Campbell
	/// \date	3/5/2017
	///
	/// \param [in,out]	out	Output camera variable.
	///
	/// \return	An errcode.
	////////////////////////////////////////////////////////////////////////////////////////////////////

	errcode InitCamera(Camera* out);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	Camera& CameraManager::MainCamera();
	///
	/// \brief	Returns Main camera.
	///
	/// \author	Jack Campbell
	/// \date	3/5/2017
	///
	/// \return	A reference to a Camera.
	////////////////////////////////////////////////////////////////////////////////////////////////////

	Camera& MainCamera();

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	errcode CameraManager::MainCamera(Camera* out);
	///
	/// \brief	Returns Main camera and an errcode.
	///
	/// \author	Jack Campbell
	/// \date	3/5/2017
	///
	/// \param [in,out]	out	If non-null, the out.
	///
	/// \return	An errcode.
	////////////////////////////////////////////////////////////////////////////////////////////////////

	errcode MainCamera(Camera* out);

	Camera& Get2DCamera();
	errcode Get2DCamera(Camera* out);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	errcode CameraManager::ShutDown();
	///
	/// \brief	Shuts down the camera manager and frees any resources it is using.
	///
	/// \author	Jack Campbell
	/// \date	3/5/2017
	///
	/// \return	An errcode.
	////////////////////////////////////////////////////////////////////////////////////////////////////

	errcode ShutDown();

};


#endif CAMERAMANAGER_H
