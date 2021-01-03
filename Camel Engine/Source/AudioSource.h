#pragma once
#include "Globals.h"
#include "Component.h"
#include "WwiseLibrary.h"
#include "MathGeoLib/include/MathGeoLib.h"
#include <string>

class GameObject;

class AudioSource : public Component {
public:
	AudioSource(GameObject* parent);
	~AudioSource();

	void Update() override;
	void OnEditor() override;

	const char* GetName();
	const float3& GetSourcePosition();
	const uint& GetID();

	const char* GetAudioBank();
	void SetAudioBank(char* name);

	const bool& GetMuted();
	void SetMuted(bool& muted);
	
	const bool& GetPlayOnAwake();
	void SetPlayOnAwake(bool& _play_on_awake);

	const bool& GetLoopActive();
	void SetLoopActive(bool& on_loop);

	const uint& GetPriority();
	void SetPriority(uint& _priority);

	const float& GetVolume();
	void SetVolume(float& _volume);

	const float& GetPitch();
	void SetPitch(float& _pitch);

	const bool& GetStereo();
	void SetStereo(bool& stereo);

	const float& GetStereoPan();
	void SetStereoPan(float& pan);

	const bool& GetIsSpatial();
	void SetIsSpatial(bool& spatial);

	const float& GetSpatialMaxDist();
	void SetSpatialMaxDist(float& max_dist);

	const float& GetSpatialMinDist();
	void SetSpatialMinDistance(float& min_dist);

	const uint& GetMusicSwapTime();
	void SetMusicSwapTime(uint& swap_time);

	const char* GetAudioToPlay();
	void SetAudioToPlay(char* audio);

	void PlayAudioByEvent(const char* name);
	void PauseAudioByEvent(const char* name);
	void ResumeAudioByEvent(const char* name);
	void StopAudioByEvent(const char* name);

public:

private:

	const char* audio_name, *audio_to_play;
	AkSoundPosition source_pos;
	uint id, music_swap_time;

	int priority;
	float volume, pitch, stereo_pan, spatial_min_distance, spatial_max_distance;
	bool is_muted, play_on_awake, to_loop, is_stereo, is_mono, is_spatial;
};