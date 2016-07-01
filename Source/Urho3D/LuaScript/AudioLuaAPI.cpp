// #include "../Audio/Audio.h"
// #include "../Audio/AudioDefs.h"
// #include "../Audio/AudioEvents.h"
// #include "../Audio/BufferedSoundStream.h"
// #include "../Audio/OggVorbisSoundStream.h"
// #include "../Audio/Sound.h"
// #include "../Audio/SoundListener.h"
// #include "../Audio/SoundSource.h"
// #include "../Audio/SoundSource3D.h"
// #include "../Audio/SoundStream.h"

// #include "../LuaScript/LuaScriptUtils.h"

// #include <kaguya.hpp>

// namespace Urho3D
// {

// static void RegisterAudio(kaguya::State& lua)
// {
//     using namespace kaguya;

//     lua["KAudio"].setClass(UserdataMetatable<Audio, Object>(false)
//         .addStaticFunction("new", &KCreateObject<Audio>)
//         .addStaticFunction("__gc", &KReleaseObject<Audio>)

//         .addFunction("GetType", &Audio::GetType)
//         .addFunction("GetTypeName", &Audio::GetTypeName)
//         .addFunction("GetTypeInfo", &Audio::GetTypeInfo)
//         .addStaticFunction("GetTypeStatic", &Audio::GetTypeStatic)
//         .addStaticFunction("GetTypeNameStatic", &Audio::GetTypeNameStatic)
//         .addStaticFunction("GetTypeInfoStatic", &Audio::GetTypeInfoStatic)
//         .addFunction("SetMode", &Audio::SetMode)
//         .addFunction("Update", &Audio::Update)
//         .addFunction("Play", &Audio::Play)
//         .addFunction("Stop", &Audio::Stop)
//         .addFunction("SetMasterGain", &Audio::SetMasterGain)
//         .addFunction("PauseSoundType", &Audio::PauseSoundType)
//         .addFunction("ResumeSoundType", &Audio::ResumeSoundType)
//         .addFunction("ResumeAll", &Audio::ResumeAll)
//         .addFunction("SetListener", &Audio::SetListener)
//         .addFunction("StopSound", &Audio::StopSound)
//         .addFunction("GetSampleSize", &Audio::GetSampleSize)
//         .addFunction("GetMixRate", &Audio::GetMixRate)
//         .addFunction("GetInterpolation", &Audio::GetInterpolation)
//         .addFunction("IsStereo", &Audio::IsStereo)
//         .addFunction("IsPlaying", &Audio::IsPlaying)
//         .addFunction("IsInitialized", &Audio::IsInitialized)
//         .addFunction("GetMasterGain", &Audio::GetMasterGain)
//         .addFunction("IsSoundTypePaused", &Audio::IsSoundTypePaused)
//         .addFunction("GetListener", &Audio::GetListener)
//         .addFunction("GetSoundSources", &Audio::GetSoundSources)
//         .addFunction("HasMasterGain", &Audio::HasMasterGain)
//         .addFunction("AddSoundSource", &Audio::AddSoundSource)
//         .addFunction("RemoveSoundSource", &Audio::RemoveSoundSource)
//         .addFunction("GetMutex", &Audio::GetMutex)
//         .addFunction("GetSoundSourceMasterGain", &Audio::GetSoundSourceMasterGain)
//         .addFunction("MixOutput", &Audio::MixOutput)

//         .addProperty("type", &Audio::GetType)
//         .addProperty("typeName", &Audio::GetTypeName)
//         .addProperty("typeInfo", &Audio::GetTypeInfo)
//         .addProperty("sampleSize", &Audio::GetSampleSize)
//         .addProperty("mixRate", &Audio::GetMixRate)
//         .addProperty("interpolation", &Audio::GetInterpolation)
//         .addProperty("stereo", &Audio::IsStereo)
//         .addProperty("playing", &Audio::IsPlaying)
//         .addProperty("initialized", &Audio::IsInitialized)
//         .addProperty("listener", &Audio::GetListener, &Audio::SetListener)
//         .addProperty("soundSources", &Audio::GetSoundSources)
//         .addProperty("mutex", &Audio::GetMutex)
//         .addStaticField("SAMPLESIZEMUL", &Audio::SAMPLE_SIZE_MUL)
//     );
//     lua["KRegisterAudioLibrary"] = function(&RegisterAudioLibrary);
// }

// static void RegisterAudioDefs(kaguya::State& lua)
// {
//     using namespace kaguya;

//     lua["KSOUND_MASTER"] = SOUND_MASTER;
//     lua["KSOUND_EFFECT"] = SOUND_EFFECT;
//     lua["KSOUND_AMBIENT"] = SOUND_AMBIENT;
//     lua["KSOUND_VOICE"] = SOUND_VOICE;
//     lua["KSOUND_MUSIC"] = SOUND_MUSIC;
// }

// static void RegisterAudioEvents(kaguya::State& lua)
// {
//     using namespace kaguya;

//     lua["KE_SOUNDFINISHED"] = E_SOUNDFINISHED;
// }

// static void RegisterBufferedSoundStream(kaguya::State& lua)
// {
//     using namespace kaguya;

//     lua["KBufferedSoundStream"].setClass(UserdataMetatable<BufferedSoundStream, SoundStream>(false)
//         .setConstructors<BufferedSoundStream()>()
//         .addStaticFunction("__gc", &KReleaseObject<BufferedSoundStream>)

//         .addFunction("GetData", &BufferedSoundStream::GetData)

//         .addOverloadedFunctions("AddData",
//             static_cast<void(BufferedSoundStream::*)(void*, unsigned int)>(&BufferedSoundStream::AddData),
//             static_cast<void(BufferedSoundStream::*)(SharedArrayPtr<signed char>, unsigned int)>(&BufferedSoundStream::AddData),
//             static_cast<void(BufferedSoundStream::*)(SharedArrayPtr<short>, unsigned int)>(&BufferedSoundStream::AddData))

//         .addFunction("Clear", &BufferedSoundStream::Clear)
//         .addFunction("GetBufferNumBytes", &BufferedSoundStream::GetBufferNumBytes)
//         .addFunction("GetBufferLength", &BufferedSoundStream::GetBufferLength)

//         .addProperty("bufferNumBytes", &BufferedSoundStream::GetBufferNumBytes)
//         .addProperty("bufferLength", &BufferedSoundStream::GetBufferLength)
//     );
// }

// static void RegisterOggVorbisSoundStream(kaguya::State& lua)
// {
//     using namespace kaguya;

//     lua["KOggVorbisSoundStream"].setClass(UserdataMetatable<OggVorbisSoundStream, SoundStream>(false)
//         .setConstructors<OggVorbisSoundStream(const Sound*)>()
//         .addStaticFunction("__gc", &KReleaseObject<OggVorbisSoundStream>)

//         .addFunction("GetData", &OggVorbisSoundStream::GetData)
//     );
// }

// static void RegisterSound(kaguya::State& lua)
// {
//     using namespace kaguya;

//     lua["KSound"].setClass(UserdataMetatable<Sound, Resource>(false)
//         .addStaticFunction("new", &KCreateObject<Sound>)
//         .addStaticFunction("__gc", &KReleaseObject<Sound>)

//         .addFunction("GetType", &Sound::GetType)
//         .addFunction("GetTypeName", &Sound::GetTypeName)
//         .addFunction("GetTypeInfo", &Sound::GetTypeInfo)
//         .addStaticFunction("GetTypeStatic", &Sound::GetTypeStatic)
//         .addStaticFunction("GetTypeNameStatic", &Sound::GetTypeNameStatic)
//         .addStaticFunction("GetTypeInfoStatic", &Sound::GetTypeInfoStatic)
//         .addFunction("BeginLoad", &Sound::BeginLoad)
//         .addFunction("LoadRaw", &Sound::LoadRaw)
//         .addFunction("LoadWav", &Sound::LoadWav)
//         .addFunction("LoadOggVorbis", &Sound::LoadOggVorbis)
//         .addFunction("SetSize", &Sound::SetSize)
//         .addFunction("SetData", &Sound::SetData)
//         .addFunction("SetFormat", &Sound::SetFormat)
//         .addFunction("SetLooped", &Sound::SetLooped)
//         .addFunction("SetLoop", &Sound::SetLoop)
//         .addFunction("GetDecoderStream", &Sound::GetDecoderStream)
//         .addFunction("GetData", &Sound::GetData)
//         .addFunction("GetStart", &Sound::GetStart)
//         .addFunction("GetRepeat", &Sound::GetRepeat)
//         .addFunction("GetEnd", &Sound::GetEnd)
//         .addFunction("GetLength", &Sound::GetLength)
//         .addFunction("GetDataSize", &Sound::GetDataSize)
//         .addFunction("GetSampleSize", &Sound::GetSampleSize)
//         .addFunction("GetFrequency", &Sound::GetFrequency)
//         .addFunction("GetIntFrequency", &Sound::GetIntFrequency)
//         .addFunction("IsLooped", &Sound::IsLooped)
//         .addFunction("IsSixteenBit", &Sound::IsSixteenBit)
//         .addFunction("IsStereo", &Sound::IsStereo)
//         .addFunction("IsCompressed", &Sound::IsCompressed)
//         .addFunction("FixInterpolation", &Sound::FixInterpolation)

//         .addProperty("type", &Sound::GetType)
//         .addProperty("typeName", &Sound::GetTypeName)
//         .addProperty("typeInfo", &Sound::GetTypeInfo)
//         .addProperty("decoderStream", &Sound::GetDecoderStream)
//         .addProperty("data", &Sound::GetData)
//         .addProperty("start", &Sound::GetStart)
//         .addProperty("repeat", &Sound::GetRepeat)
//         .addProperty("end", &Sound::GetEnd)
//         .addProperty("length", &Sound::GetLength)
//         .addProperty("dataSize", &Sound::GetDataSize)
//         .addProperty("sampleSize", &Sound::GetSampleSize)
//         .addProperty("frequency", &Sound::GetFrequency)
//         .addProperty("intFrequency", &Sound::GetIntFrequency)
//         .addProperty("looped", &Sound::IsLooped, &Sound::SetLooped)
//         .addProperty("sixteenBit", &Sound::IsSixteenBit)
//         .addProperty("stereo", &Sound::IsStereo)
//         .addProperty("compressed", &Sound::IsCompressed)
//         .addProperty("size", &Sound::SetSize)
//     );
// }

// static void RegisterSoundListener(kaguya::State& lua)
// {
//     using namespace kaguya;

//     lua["KSoundListener"].setClass(UserdataMetatable<SoundListener, Component>(false)
//         .addStaticFunction("new", &KCreateObject<SoundListener>)
//         .addStaticFunction("__gc", &KReleaseObject<SoundListener>)

//         .addFunction("GetType", &SoundListener::GetType)
//         .addFunction("GetTypeName", &SoundListener::GetTypeName)
//         .addFunction("GetTypeInfo", &SoundListener::GetTypeInfo)
//         .addStaticFunction("GetTypeStatic", &SoundListener::GetTypeStatic)
//         .addStaticFunction("GetTypeNameStatic", &SoundListener::GetTypeNameStatic)
//         .addStaticFunction("GetTypeInfoStatic", &SoundListener::GetTypeInfoStatic)

//         .addProperty("type", &SoundListener::GetType)
//         .addProperty("typeName", &SoundListener::GetTypeName)
//         .addProperty("typeInfo", &SoundListener::GetTypeInfo)
//     );
// }

// static void RegisterSoundSource(kaguya::State& lua)
// {
//     using namespace kaguya;

//     lua["KSTREAM_BUFFER_LENGTH"] = STREAM_BUFFER_LENGTH;
//     lua["KSoundSource"].setClass(UserdataMetatable<SoundSource, Component>(false)
//         .addStaticFunction("new", &KCreateObject<SoundSource>)
//         .addStaticFunction("__gc", &KReleaseObject<SoundSource>)

//         .addFunction("GetType", &SoundSource::GetType)
//         .addFunction("GetTypeName", &SoundSource::GetTypeName)
//         .addFunction("GetTypeInfo", &SoundSource::GetTypeInfo)
//         .addStaticFunction("GetTypeStatic", &SoundSource::GetTypeStatic)
//         .addStaticFunction("GetTypeNameStatic", &SoundSource::GetTypeNameStatic)
//         .addStaticFunction("GetTypeInfoStatic", &SoundSource::GetTypeInfoStatic)

//         .addOverloadedFunctions("Play",
//             static_cast<void(SoundSource::*)(Sound*)>(&SoundSource::Play),
//             static_cast<void(SoundSource::*)(Sound*, float)>(&SoundSource::Play),
//             static_cast<void(SoundSource::*)(Sound*, float, float)>(&SoundSource::Play),
//             static_cast<void(SoundSource::*)(Sound*, float, float, float)>(&SoundSource::Play),
//             static_cast<void(SoundSource::*)(SoundStream*)>(&SoundSource::Play))

//         .addFunction("Stop", &SoundSource::Stop)
//         .addFunction("SetSoundType", &SoundSource::SetSoundType)
//         .addFunction("SetFrequency", &SoundSource::SetFrequency)
//         .addFunction("SetGain", &SoundSource::SetGain)
//         .addFunction("SetAttenuation", &SoundSource::SetAttenuation)
//         .addFunction("SetPanning", &SoundSource::SetPanning)
//         .addFunction("SetAutoRemove", &SoundSource::SetAutoRemove)
//         .addFunction("SetPlayPosition", &SoundSource::SetPlayPosition)
//         .addFunction("GetSound", &SoundSource::GetSound)
//         .addFunction("GetPlayPosition", &SoundSource::GetPlayPosition)
//         .addFunction("GetSoundType", &SoundSource::GetSoundType)
//         .addFunction("GetTimePosition", &SoundSource::GetTimePosition)
//         .addFunction("GetFrequency", &SoundSource::GetFrequency)
//         .addFunction("GetGain", &SoundSource::GetGain)
//         .addFunction("GetAttenuation", &SoundSource::GetAttenuation)
//         .addFunction("GetPanning", &SoundSource::GetPanning)
//         .addFunction("GetAutoRemove", &SoundSource::GetAutoRemove)
//         .addFunction("IsPlaying", &SoundSource::IsPlaying)
//         .addFunction("Update", &SoundSource::Update)
//         .addFunction("Mix", &SoundSource::Mix)
//         .addFunction("UpdateMasterGain", &SoundSource::UpdateMasterGain)

//         .addProperty("type", &SoundSource::GetType)
//         .addProperty("typeName", &SoundSource::GetTypeName)
//         .addProperty("typeInfo", &SoundSource::GetTypeInfo)
//         .addProperty("sound", &SoundSource::GetSound)
//         .addProperty("playPosition", &SoundSource::GetPlayPosition, &SoundSource::SetPlayPosition)
//         .addProperty("soundType", &SoundSource::GetSoundType, &SoundSource::SetSoundType)
//         .addProperty("timePosition", &SoundSource::GetTimePosition)
//         .addProperty("frequency", &SoundSource::GetFrequency, &SoundSource::SetFrequency)
//         .addProperty("gain", &SoundSource::GetGain, &SoundSource::SetGain)
//         .addProperty("attenuation", &SoundSource::GetAttenuation, &SoundSource::SetAttenuation)
//         .addProperty("panning", &SoundSource::GetPanning, &SoundSource::SetPanning)
//         .addProperty("autoRemove", &SoundSource::GetAutoRemove, &SoundSource::SetAutoRemove)
//         .addProperty("playing", &SoundSource::IsPlaying)
//     );
// }

// static void RegisterSoundSource3D(kaguya::State& lua)
// {
//     using namespace kaguya;

//     lua["KSoundSource3D"].setClass(UserdataMetatable<SoundSource3D, SoundSource>(false)
//         .addStaticFunction("new", &KCreateObject<SoundSource3D>)
//         .addStaticFunction("__gc", &KReleaseObject<SoundSource3D>)

//         .addFunction("GetType", &SoundSource3D::GetType)
//         .addFunction("GetTypeName", &SoundSource3D::GetTypeName)
//         .addFunction("GetTypeInfo", &SoundSource3D::GetTypeInfo)
//         .addStaticFunction("GetTypeStatic", &SoundSource3D::GetTypeStatic)
//         .addStaticFunction("GetTypeNameStatic", &SoundSource3D::GetTypeNameStatic)
//         .addStaticFunction("GetTypeInfoStatic", &SoundSource3D::GetTypeInfoStatic)
//         .addFunction("DrawDebugGeometry", &SoundSource3D::DrawDebugGeometry)
//         .addFunction("Update", &SoundSource3D::Update)
//         .addFunction("SetDistanceAttenuation", &SoundSource3D::SetDistanceAttenuation)
//         .addFunction("SetAngleAttenuation", &SoundSource3D::SetAngleAttenuation)
//         .addFunction("SetNearDistance", &SoundSource3D::SetNearDistance)
//         .addFunction("SetFarDistance", &SoundSource3D::SetFarDistance)
//         .addFunction("SetInnerAngle", &SoundSource3D::SetInnerAngle)
//         .addFunction("SetOuterAngle", &SoundSource3D::SetOuterAngle)
//         .addFunction("SetRolloffFactor", &SoundSource3D::SetRolloffFactor)
//         .addFunction("CalculateAttenuation", &SoundSource3D::CalculateAttenuation)
//         .addFunction("GetNearDistance", &SoundSource3D::GetNearDistance)
//         .addFunction("GetFarDistance", &SoundSource3D::GetFarDistance)
//         .addFunction("GetInnerAngle", &SoundSource3D::GetInnerAngle)
//         .addFunction("GetOuterAngle", &SoundSource3D::GetOuterAngle)
//         .addFunction("RollAngleoffFactor", &SoundSource3D::RollAngleoffFactor)

//         .addProperty("type", &SoundSource3D::GetType)
//         .addProperty("typeName", &SoundSource3D::GetTypeName)
//         .addProperty("typeInfo", &SoundSource3D::GetTypeInfo)
//         .addProperty("nearDistance", &SoundSource3D::GetNearDistance, &SoundSource3D::SetNearDistance)
//         .addProperty("farDistance", &SoundSource3D::GetFarDistance, &SoundSource3D::SetFarDistance)
//         .addProperty("innerAngle", &SoundSource3D::GetInnerAngle, &SoundSource3D::SetInnerAngle)
//         .addProperty("outerAngle", &SoundSource3D::GetOuterAngle, &SoundSource3D::SetOuterAngle)
//         .addProperty("rolloffFactor", &SoundSource3D::SetRolloffFactor)
//     );
// }

// static void RegisterSoundStream(kaguya::State& lua)
// {
//     using namespace kaguya;

//     lua["KSoundStream"].setClass(UserdataMetatable<SoundStream, RefCounted>(false)
//         .setConstructors<SoundStream()>()
//         .addStaticFunction("__gc", &KReleaseObject<SoundStream>)

//         .addFunction("GetData", &SoundStream::GetData)
//         .addFunction("SetFormat", &SoundStream::SetFormat)
//         .addFunction("SetStopAtEnd", &SoundStream::SetStopAtEnd)
//         .addFunction("GetSampleSize", &SoundStream::GetSampleSize)
//         .addFunction("GetFrequency", &SoundStream::GetFrequency)
//         .addFunction("GetIntFrequency", &SoundStream::GetIntFrequency)
//         .addFunction("GetStopAtEnd", &SoundStream::GetStopAtEnd)
//         .addFunction("IsSixteenBit", &SoundStream::IsSixteenBit)
//         .addFunction("IsStereo", &SoundStream::IsStereo)

//         .addProperty("sampleSize", &SoundStream::GetSampleSize)
//         .addProperty("frequency", &SoundStream::GetFrequency)
//         .addProperty("intFrequency", &SoundStream::GetIntFrequency)
//         .addProperty("stopAtEnd", &SoundStream::GetStopAtEnd, &SoundStream::SetStopAtEnd)
//         .addProperty("sixteenBit", &SoundStream::IsSixteenBit)
//         .addProperty("stereo", &SoundStream::IsStereo)
//     );
// }

// void RegisterAudioLuaAPI(kaguya::State& lua)
// {
//     RegisterAudio(lua);
//     RegisterAudioDefs(lua);
//     RegisterAudioEvents(lua);
//     RegisterBufferedSoundStream(lua);
//     RegisterOggVorbisSoundStream(lua);
//     RegisterSound(lua);
//     RegisterSoundListener(lua);
//     RegisterSoundSource(lua);
//     RegisterSoundSource3D(lua);
//     RegisterSoundStream(lua);
// }
// }
