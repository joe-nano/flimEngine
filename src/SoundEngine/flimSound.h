#pragma once
#ifndef FLIMSOUND_H
#define FLIMSOUND_H


// audio engine includes
#include "SoundEngine.h"
#include "SoundCall.h"
#include "SoundCallRegistry.h"
#include "..\Flim\GameObject.h"
#include "flimReverb.h"
#include "flimFilter.h"
#include "..\Cottage.h"
#include "AzulCore.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
/// \enum	DistanceCurve
///\ingroup FLIMSOUND
/// \brief	Values that represent distance curves.
////////////////////////////////////////////////////////////////////////////////////////////////////

enum class DistanceCurve
{
	Linear,
	Logarithmic,
	Reverse_Logarithmic
};



////////////////////////////////////////////////////////////////////////////////////////////////////
/// \enum	SourceType
///\ingroup FLIMSOUND
/// \brief	Values that represent source types.
////////////////////////////////////////////////////////////////////////////////////////////////////

enum class SourceType
{
	Point,
	Plane
};

// a collidable with a soundcall; corresponds to emitter on game side

////////////////////////////////////////////////////////////////////////////////////////////////////
/// \class	flimSound
///
/// \brief	A flim sound.
///\ingroup FLIMSOUND
/// \author	Jack Campbell
/// \date	6/1/2017
////////////////////////////////////////////////////////////////////////////////////////////////////

class flimSound : public GameObject
{
public:

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	flimSound::flimSound(SoundCallID id, bool is3DSound = false, bool occ = false);
	///
	/// \brief	Constructor.
	///
	/// \author	Jack Campbell
	/// \date	6/1/2017
	///\ingroup FLIMSOUND
	/// \param	id		 	The identifier.
	/// \param	is3DSound	(Optional) True if this object is 3D sound.
	/// \param	occ		 	(Optional) True to occ.
	////////////////////////////////////////////////////////////////////////////////////////////////////

	flimSound(SoundCallID id, bool is3DSound = false, bool occ = false);

	flimSound() = delete;
	flimSound(const flimSound&) = default;
	flimSound& operator=(const flimSound&) = default;
	~flimSound();

	// 3D methods
	snd_err getOrientation(Vect& out) const;
	snd_err setOrientation(const Vect& orient);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	snd_err flimSound::getPosition(Vect& out) const;
	///
	/// \brief	Gets a position.
	///
	/// \author	Jack Campbell
	/// \date	6/1/2017
	///\ingroup FLIMSOUND
	/// \param [in,out]	out	The out.
	///
	/// \return	The position.
	////////////////////////////////////////////////////////////////////////////////////////////////////

	snd_err getPosition(Vect& out) const;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	snd_err flimSound::setPosition(const Vect& orient);
	///
	/// \brief	Sets a position.
	///
	/// \author	Jack Campbell
	/// \date	6/1/2017
	///\ingroup FLIMSOUND
	/// \param	orient	The orient.
	///
	/// \return	A snd_err.
	////////////////////////////////////////////////////////////////////////////////////////////////////

	snd_err setPosition(const Vect& orient);

	//snd_err setOrientation(float xF, float yF, float zF, float xU, float yU, float zU);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	snd_err flimSound::SetOrientation(const Vect & vect, float xU = 0.0f, float yU = 1.0f, float zU = 0.0f);
	///
	/// \brief	Sets an orientation.
	///
	/// \author	Jack Campbell
	/// \date	6/1/2017
	///\ingroup FLIMSOUND
	/// \param	vect	The vect.
	/// \param	xU  	(Optional) The x coordinate u.
	/// \param	yU  	(Optional) The y coordinate u.
	/// \param	zU  	(Optional) The z coordinate u.
	///
	/// \return	A snd_err.
	////////////////////////////////////////////////////////////////////////////////////////////////////

	snd_err SetOrientation(const Vect & vect, float xU = 0.0f, float yU = 1.0f, float zU = 0.0f);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	snd_err flimSound::getDistanceCurve(DistanceCurve& out);
	///
	/// \brief	Gets distance curve.
	///
	/// \author	Jack Campbell
	/// \date	6/1/2017
	///\ingroup FLIMSOUND
	/// \param [in,out]	out	The out.
	///
	/// \return	The distance curve.
	////////////////////////////////////////////////////////////////////////////////////////////////////

	snd_err getDistanceCurve(DistanceCurve& out);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	snd_err flimSound::setDistanceCurve(const DistanceCurve& distCurve);
	///
	/// \brief	Sets distance curve.
	///
	/// \author	Jack Campbell
	/// \date	6/1/2017
	///\ingroup FLIMSOUND
	/// \param	distCurve	The distance curve.
	///
	/// \return	A snd_err.
	////////////////////////////////////////////////////////////////////////////////////////////////////

	snd_err setDistanceCurve(const DistanceCurve& distCurve);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	snd_err flimSound::getReverb(flimReverb& out) const;
	///
	/// \brief	Gets a reverb.
	///
	/// \author	Jack Campbell
	/// \date	6/1/2017
	///\ingroup FLIMSOUND
	/// \param [in,out]	out	The out.
	///
	/// \return	The reverb.
	////////////////////////////////////////////////////////////////////////////////////////////////////

	snd_err getReverb(flimReverb& out) const;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	snd_err flimSound::getFilter(flimFilter& out) const;
	///
	/// \brief	Gets a filter.
	///
	/// \author	Jack Campbell
	/// \date	6/1/2017
	///\ingroup FLIMSOUND
	/// \param [in,out]	out	The out.
	///
	/// \return	The filter.
	////////////////////////////////////////////////////////////////////////////////////////////////////

	snd_err getFilter(flimFilter& out) const;

	// pass through methods -- to soundcall

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	snd_err flimSound::Pan(float p, int triggerTime = 0);
	///
	/// \brief	Pans.
	///
	/// \author	Jack Campbell
	/// \date	6/1/2017
	///\ingroup FLIMSOUND
	/// \param	p		   	The float to process.
	/// \param	triggerTime	(Optional) The trigger time.
	///
	/// \return	A snd_err.
	////////////////////////////////////////////////////////////////////////////////////////////////////

	snd_err Pan(float p, int triggerTime = 0);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	snd_err flimSound::Pan(float from, float to, float time, int triggerTime = 0);
	///
	/// \brief	Pans.
	///
	/// \author	Jack Campbell
	/// \date	6/1/2017
	///\ingroup FLIMSOUND
	/// \param	from	   	Source for the.
	/// \param	to		   	to.
	/// \param	time	   	The time.
	/// \param	triggerTime	(Optional) The trigger time.
	///
	/// \return	A snd_err.
	////////////////////////////////////////////////////////////////////////////////////////////////////

	snd_err Pan(float from, float to, float time, int triggerTime = 0);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	snd_err flimSound::Loop(bool toLoop, int triggerTime = 0);
	///
	/// \brief	Loops.
	///
	/// \author	Jack Campbell
	/// \date	6/1/2017
	///\ingroup FLIMSOUND
	/// \param	toLoop	   	True to to loop.
	/// \param	triggerTime	(Optional) The trigger time.
	///
	/// \return	A snd_err.
	////////////////////////////////////////////////////////////////////////////////////////////////////

	snd_err Loop(bool toLoop, int triggerTime = 0);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	snd_err flimSound::Pitch(float p, int triggerTime = 0);
	///
	/// \brief	Pitches.
	///
	/// \author	Jack Campbell
	/// \date	6/1/2017
	///\ingroup FLIMSOUND
	/// \param	p		   	The float to process.
	/// \param	triggerTime	(Optional) The trigger time.
	///
	/// \return	A snd_err.
	////////////////////////////////////////////////////////////////////////////////////////////////////

	snd_err Pitch(float p, int triggerTime = 0);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	snd_err flimSound::Pitch(float from, float to, float time, int triggerTime = 0);
	///
	/// \brief	Pitches.
	///
	/// \author	Jack Campbell
	/// \date	6/1/2017
	///\ingroup FLIMSOUND
	/// \param	from	   	Source for the.
	/// \param	to		   	to.
	/// \param	time	   	The time.
	/// \param	triggerTime	(Optional) The trigger time.
	///
	/// \return	A snd_err.
	////////////////////////////////////////////////////////////////////////////////////////////////////

	snd_err Pitch(float from, float to, float time, int triggerTime = 0);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	snd_err flimSound::Volume(float p, int triggerTime = 0);
	///
	/// \brief	Volumes.
	///
	/// \author	Jack Campbell
	/// \date	6/1/2017
	///\ingroup FLIMSOUND
	/// \param	p		   	The float to process.
	/// \param	triggerTime	(Optional) The trigger time.
	///
	/// \return	A snd_err.
	////////////////////////////////////////////////////////////////////////////////////////////////////

	snd_err Volume(float p, int triggerTime = 0);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	snd_err flimSound::Volume(float from, float to, float time, int triggerTime = 0);
	///
	/// \brief	Volumes.
	///
	/// \author	Jack Campbell
	/// \date	6/1/2017
	///\ingroup FLIMSOUND
	/// \param	from	   	Source for the.
	/// \param	to		   	to.
	/// \param	time	   	The time.
	/// \param	triggerTime	(Optional) The trigger time.
	///
	/// \return	A snd_err.
	////////////////////////////////////////////////////////////////////////////////////////////////////

	snd_err Volume(float from, float to, float time, int triggerTime = 0);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	snd_err flimSound::Play(bool toLoop = false, int t = 0, int _priority = 0);
	///
	/// \brief	Plays.
	///
	/// \author	Jack Campbell
	/// \date	6/1/2017
	///\ingroup FLIMSOUND
	/// \param	toLoop   	(Optional) True to to loop.
	/// \param	t		 	(Optional) The int to process.
	/// \param	_priority	(Optional) The priority.
	///
	/// \return	A snd_err.
	////////////////////////////////////////////////////////////////////////////////////////////////////

	snd_err Play(bool toLoop = false, int t = 0, int _priority = 0);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	snd_err flimSound::Stop(int t = 0);
	///
	/// \brief	Stops the given t.
	///
	/// \author	Jack Campbell
	/// \date	6/1/2017
	///\ingroup FLIMSOUND
	/// \param	t	(Optional) The int to process.
	///
	/// \return	A snd_err.
	////////////////////////////////////////////////////////////////////////////////////////////////////

	snd_err Stop(int t = 0);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	snd_err flimSound::Pause(int t = 0);
	///
	/// \brief	Pauses the given t.
	///
	/// \author	Jack Campbell
	/// \date	6/1/2017
	///\ingroup FLIMSOUND
	/// \param	t	(Optional) The int to process.
	///
	/// \return	A snd_err.
	////////////////////////////////////////////////////////////////////////////////////////////////////

	snd_err Pause(int t = 0);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	snd_err flimSound::IsPlaying(bool&);
	///
	/// \brief	Is playing.
	///
	/// \author	Jack Campbell
	/// \date	6/1/2017
	///\ingroup FLIMSOUND
	/// \param [in,out]	parameter1	The first parameter.
	///
	/// \return	A snd_err.
	////////////////////////////////////////////////////////////////////////////////////////////////////

	snd_err IsPlaying(bool&);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	snd_err flimSound::GetTimeSinceStarted(int&);
	///
	/// \brief	Gets time since started.
	///
	/// \author	Jack Campbell
	/// \date	6/1/2017
	///\ingroup FLIMSOUND
	/// \param [in,out]	parameter1	The first parameter.
	///
	/// \return	The time since started.
	////////////////////////////////////////////////////////////////////////////////////////////////////

	snd_err GetTimeSinceStarted(int&);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	snd_err flimSound::GetVolume(float&);
	///
	/// \brief	Gets a volume.
	///
	/// \author	Jack Campbell
	/// \date	6/1/2017
	///\ingroup FLIMSOUND
	/// \param [in,out]	parameter1	The first parameter.
	///
	/// \return	The volume.
	////////////////////////////////////////////////////////////////////////////////////////////////////

	snd_err GetVolume(float&);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	snd_err flimSound::GetPitch(float&);
	///
	/// \brief	Gets a pitch.
	///
	/// \author	Jack Campbell
	/// \date	6/1/2017
	///\ingroup FLIMSOUND
	/// \param [in,out]	parameter1	The first parameter.
	///
	/// \return	The pitch.
	////////////////////////////////////////////////////////////////////////////////////////////////////

	snd_err GetPitch(float&);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	snd_err flimSound::GetPan(float&);
	///
	/// \brief	Gets a pan.
	///
	/// \author	Jack Campbell
	/// \date	6/1/2017
	///\ingroup FLIMSOUND
	/// \param [in,out]	parameter1	The first parameter.
	///
	/// \return	The pan.
	////////////////////////////////////////////////////////////////////////////////////////////////////

	snd_err GetPan(float&);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	snd_err flimSound::GetPriority(int&);
	///
	/// \brief	Gets a priority.
	///
	/// \author	Jack Campbell
	/// \date	6/1/2017
	///\ingroup FLIMSOUND
	/// \param [in,out]	parameter1	The first parameter.
	///
	/// \return	The priority.
	////////////////////////////////////////////////////////////////////////////////////////////////////

	snd_err GetPriority(int&);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	snd_err flimSound::GetLoop(bool&);
	///
	/// \brief	Gets a loop.
	///
	/// \author	Jack Campbell
	/// \date	6/1/2017
	///\ingroup FLIMSOUND
	/// \param [in,out]	parameter1	The first parameter.
	///
	/// \return	The loop.
	////////////////////////////////////////////////////////////////////////////////////////////////////

	snd_err GetLoop(bool&);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	snd_err flimSound::SubmitSoundEndedCallback(CallbackCommand* cmd);
	///
	/// \brief	Callback, called when the submit sound ended.
	///
	/// \author	Jack Campbell
	/// \date	6/1/2017
	///\ingroup FLIMSOUND
	/// \param [in,out]	cmd	If non-null, the command.
	///
	/// \return	A snd_err.
	////////////////////////////////////////////////////////////////////////////////////////////////////

	snd_err SubmitSoundEndedCallback(CallbackCommand* cmd);

	// game object stuff
	errcode Update() override;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	errcode flimSound::Collision(GameObject *);
	///
	/// \brief	Collisions the given parameter 1.
	///
	/// \author	Jack Campbell
	/// \date	6/1/2017
	///\ingroup FLIMSOUND
	/// \param [in,out]	parameter1	If non-null, the first parameter.
	///
	/// \return	An errcode.
	////////////////////////////////////////////////////////////////////////////////////////////////////

	errcode Collision(GameObject *);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	errcode flimSound::Collision(Collidable *) override
	///
	/// \brief	Collisions the given parameter 1.
	///
	/// \author	Jack Campbell
	/// \date	6/1/2017
	///\ingroup FLIMSOUND
	/// \param [in,out]	parameter1	If non-null, the first parameter.
	///
	/// \return	An errcode.
	////////////////////////////////////////////////////////////////////////////////////////////////////

	errcode Collision(Collidable *) override { return errcode::success; };

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	errcode flimSound::CollisionTerrain(const CollisionVolumeAABB& aabb) override;
	///
	/// \brief	Collision terrain.
	///
	/// \author	Jack Campbell
	/// \date	6/1/2017
	///\ingroup FLIMSOUND
	/// \param	aabb	The aabb.
	///
	/// \return	An errcode.
	////////////////////////////////////////////////////////////////////////////////////////////////////

	errcode CollisionTerrain(const CollisionVolumeAABB& aabb) override; 

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	errcode flimSound::CollisionEnter(Collidable*);
	///
	/// \brief	Collision enter.
	///
	/// \author	Jack Campbell
	/// \date	6/1/2017
	/// \ingroup FLIMSOUND
	/// \param [in,out]	parameter1	If non-null, the first parameter.
	///
	/// \return	An errcode.
	////////////////////////////////////////////////////////////////////////////////////////////////////

	errcode CollisionEnter(Collidable*);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	errcode flimSound::CollisionExit();
	///
	/// \brief	Collision exit.
	///
	/// \author	Jack Campbell
	/// \date	6/1/2017
	///
	/// \return	An errcode.
	////////////////////////////////////////////////////////////////////////////////////////////////////

	errcode CollisionExit();


	// reverb

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	errcode flimSound::SetReverbLevel(float level);
	///
	/// \brief	Sets reverb level.
	///
	/// \author	Jack Campbell
	/// \date	6/1/2017
	///\ingroup FLIMSOUND
	/// \param	level	The level.
	///
	/// \return	An errcode.
	////////////////////////////////////////////////////////////////////////////////////////////////////

	errcode SetReverbLevel(float level);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	errcode flimSound::SetReverbTime(float time);
	///
	/// \brief	Sets reverb time.
	///
	/// \author	Jack Campbell
	/// \date	6/1/2017
	///\ingroup FLIMSOUND
	/// \param	time	The time.
	///
	/// \return	An errcode.
	////////////////////////////////////////////////////////////////////////////////////////////////////

	errcode SetReverbTime(float time);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	errcode flimSound::SetReverbPreDelay(float time);
	///
	/// \brief	Sets reverb pre delay.
	///
	/// \author	Jack Campbell
	/// \date	6/1/2017
	///\ingroup FLIMSOUND
	/// \param	time	The time.
	///
	/// \return	An errcode.
	////////////////////////////////////////////////////////////////////////////////////////////////////

	errcode SetReverbPreDelay(float time);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	errcode flimSound::SetReverbSize(float size);
	///
	/// \brief	Sets reverb size.
	///
	/// \author	Jack Campbell
	/// \date	6/1/2017
	///\ingroup FLIMSOUND
	/// \param	size	The size.
	///
	/// \return	An errcode.
	////////////////////////////////////////////////////////////////////////////////////////////////////

	errcode SetReverbSize(float size);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	errcode flimSound::SetReverbDensity(float density);
	///
	/// \brief	Sets reverb density.
	///
	/// \author	Jack Campbell
	/// \date	6/1/2017
	///\ingroup FLIMSOUND
	/// \param	density	The density.
	///
	/// \return	An errcode.
	////////////////////////////////////////////////////////////////////////////////////////////////////

	errcode SetReverbDensity(float density);


	errcode SetReverbPreset(flimReverb reverb);

private:
	SoundCallID sndID;
	SoundCall* snd;

	bool is3D;
	bool occlusionEnabled; // some sort of collision registration with a ray to the listener
	Model* occlusionSphere;
	Vect position;
	Vect orientation;
	DistanceCurve distanceCurve;
	SourceType sourceType;

	//Reverb
	// reverb object -- getters and setters, parameters adjusted internally
	flimReverb reverb;

	//Filter
	// filter object -- getters and setters, parameters adjusted internally
	flimFilter filter;
};



#endif