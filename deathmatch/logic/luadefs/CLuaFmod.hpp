#include "CLuaFmod.h"
//#include "StdInc.h"

#define destroy(x)     erase(x)
#define insert(x1, x2) insert(x1, x2);

FMOD_RESULT result;                            // Other
void*       extraDriverData = NULL;            // Other

FMOD::System*         f_system;
FMOD::Studio::System* f_studio;


//static const unsigned int MAX_AUDIO_CHANNELS = 1024;
static const int    AUDIO_SAMPLE_RATE = 44100;
const float DISTANCEFACTOR = 1.0f;
FMOD_VECTOR listenerpos = {0.0f, 0.0f, -1.0f * DISTANCEFACTOR};
FMOD_VECTOR forward = {0.0f, 0.0f, 1.0f};
FMOD_VECTOR up = {0.0f, 1.0f, 0.0f};
FMOD::ChannelGroup* mastergroup = 0;
FMOD::Reverb3D* reverb;
FMOD_VECTOR revPos = {0.0f, 0.0f, 0.0f};
float revMinDist = 10.0f, revMaxDist = 50.0f;
bool muted = false;


//std::map<std::string, FMOD::Sound*> sounds;
//std::map<std::string, FMOD::Channel*> loopsPlaying;
//std::map<std::string, FMOD::Studio::Bank*> soundBanks;
//std::map<std::string, FMOD::Studio::EventDescription*> eventDescriptions;
//std::map<std::string, FMOD::Studio::EventInstance*> eventInstances;
//



struct myArray
{
    int                                                     mnNextChannelId;
    typedef std::map<SString, std::map<SString, SString> >  testBank;
    typedef std::map<SString, FMOD::Studio::Bank*>          BankMap;
    typedef std::map<SString, FMOD::Sound*>                 SoundMap;
    typedef std::map<int, FMOD::Channel*>                   ChannelMap;
    typedef std::map<SString, FMOD::Studio::EventInstance*> EventMap;

    testBank   mTest;
    BankMap    mBanks;
    EventMap   mEvents;
    SoundMap   mSounds;
    ChannelMap mChannels;
};
//myArray* ArrayMap = nullptr;
myArray* ArrayMap = new myArray();


const char* getFmodDirectory(const char* resourceName, const char* file)
{
    return SString("%s\\resources\\%s\\%s", g_pClientGame->GetFileCacheRoot(), resourceName, file);
}
//
const char* ShortenOutputStringResult(const SString& val1, const char* result)
{
    return (val1 + result).c_str();
}

SString FMODErrorCheck(FMOD_RESULT result, const char* funcName)
{
    return SString("%s [function -> %s]", FMOD_ErrorString(result), funcName);
}

SString const_to_string(const char* text)
{
    return SString("%s", text);
}


struct localized_state_bank
{
    unsigned int id;
    SString      state;
};

static const SFixedArray<localized_state_bank, 5> getLocalizedLoadingStateBank = {{
    {0, "происходит выгрузка ресурсов"},
    {1, "ресурсы выгружены и освобождены"},
    {2, "загрузка ресурсов в память"},
    {3, "ресурсы загружены в память и готовы к использованию"},
    {4, "при загрузке ресурсов произошла ошибка"},
}};

struct localized_event_playing
{
    unsigned int id;
    SString      state;
};

static const SFixedArray<localized_event_playing, 5> getLocalizedEventPlaying = {{
    {0, "Воспроизведение"},
    {1, "Удерживание"},
    {2, "Остановлено"},
    {3, "Запуск"},
    {4, "Остановка"},
}};


 struct flagfmodstudioinit
{
    const char*  Flag_Name;
    unsigned int flag;
};

static const SFixedArray<flagfmodstudioinit, 7> getFmodStudioFlags = {{
    {"FMOD_STUDIO_INIT_NORMAL", FMOD_STUDIO_INIT_NORMAL},
    {"FMOD_STUDIO_INIT_LIVEUPDATE", FMOD_STUDIO_INIT_LIVEUPDATE},
    {"FMOD_STUDIO_INIT_ALLOW_MISSING_PLUGINS", FMOD_STUDIO_INIT_ALLOW_MISSING_PLUGINS},
    {"FMOD_STUDIO_INIT_SYNCHRONOUS_UPDATE", FMOD_STUDIO_INIT_SYNCHRONOUS_UPDATE},
    {"FMOD_STUDIO_INIT_DEFERRED_CALLBACKS", FMOD_STUDIO_INIT_DEFERRED_CALLBACKS},
    {"FMOD_STUDIO_INIT_LOAD_FROM_UPDATE", FMOD_STUDIO_INIT_LOAD_FROM_UPDATE},
    {"FMOD_STUDIO_INIT_MEMORY_TRACKING", FMOD_STUDIO_INIT_MEMORY_TRACKING},
}};

unsigned int getFmodStudioFlag(const char* flagName)
{
    for (unsigned int i = 0; i <= (6); i++)
    {
        if (stricmp(flagName, getFmodStudioFlags[i].Flag_Name) == 0 ||
            (getFmodStudioFlags[i].Flag_Name && stricmp(flagName, getFmodStudioFlags[i].Flag_Name) == 0))
        {
            return getFmodStudioFlags[i].flag;
        }
    }
    return getFmodStudioFlags[0].flag;
}


 struct flagfmodinit
{
    const char*  Flag_Name;
    unsigned int flag;
};

static const SFixedArray<flagfmodinit, 13> getFmodFlags = {{
    {"FMOD_INIT_NORMAL", FMOD_INIT_NORMAL},
    {"FMOD_INIT_STREAM_FROM_UPDATE", FMOD_INIT_STREAM_FROM_UPDATE},
    {"FMOD_INIT_MIX_FROM_UPDATE", FMOD_INIT_MIX_FROM_UPDATE},
    {"FMOD_INIT_3D_RIGHTHANDED", FMOD_INIT_3D_RIGHTHANDED},
    {"FMOD_INIT_CHANNEL_LOWPASS", FMOD_INIT_CHANNEL_LOWPASS},
    {"FMOD_INIT_CHANNEL_DISTANCEFILTER", FMOD_INIT_CHANNEL_DISTANCEFILTER},
    {"FMOD_INIT_PROFILE_ENABLE", FMOD_INIT_PROFILE_ENABLE},
    {"FMOD_INIT_VOL0_BECOMES_VIRTUAL", FMOD_INIT_VOL0_BECOMES_VIRTUAL},
    {"FMOD_INIT_GEOMETRY_USECLOSEST", FMOD_INIT_GEOMETRY_USECLOSEST},
    {"FMOD_INIT_PREFER_DOLBY_DOWNMIX", FMOD_INIT_PREFER_DOLBY_DOWNMIX},
    {"FMOD_INIT_THREAD_UNSAFE", FMOD_INIT_THREAD_UNSAFE},
    {"FMOD_INIT_PROFILE_METER_ALL", FMOD_INIT_PROFILE_METER_ALL},
    {"FMOD_INIT_MEMORY_TRACKING", FMOD_INIT_MEMORY_TRACKING},
}};

unsigned int getFmodCoreFlag(const char* flagName)
{
    for (unsigned int i = 0; i <= (12); i++)
    {
        if (stricmp(flagName, getFmodFlags[i].Flag_Name) == 0 || (getFmodFlags[i].Flag_Name && stricmp(flagName, getFmodFlags[i].Flag_Name) == 0))
        {
            return getFmodFlags[i].flag;
        }
    }
    return getFmodFlags[0].flag;
}


struct flagfmodSound
{
    const char*  Flag_Name;
    unsigned int soundFlag;
};

static const SFixedArray<flagfmodSound, 29> getFmodSoundFlags = {{
    {"FMOD_DEFAULT", FMOD_DEFAULT},
    {"FMOD_LOOP_OFF", FMOD_LOOP_OFF},
    {"FMOD_LOOP_NORMAL", FMOD_LOOP_NORMAL},
    {"FMOD_LOOP_BIDI", FMOD_LOOP_BIDI},
    {"FMOD_2D", FMOD_2D},
    {"FMOD_3D", FMOD_3D},
    {"FMOD_CREATESTREAM", FMOD_CREATESTREAM},
    {"FMOD_CREATESAMPLE", FMOD_CREATESAMPLE},
    {"FMOD_CREATECOMPRESSEDSAMPLE", FMOD_CREATECOMPRESSEDSAMPLE},
    {"FMOD_OPENUSER", FMOD_OPENUSER},
    {"FMOD_OPENMEMORY", FMOD_OPENMEMORY},
    {"FMOD_OPENMEMORY_POINT", FMOD_OPENMEMORY_POINT},
    {"FMOD_OPENRAW", FMOD_OPENRAW},
    {"FMOD_OPENONLY", FMOD_OPENONLY},
    {"FMOD_ACCURATETIME", FMOD_ACCURATETIME},
    {"FMOD_MPEGSEARCH", FMOD_MPEGSEARCH},
    {"FMOD_NONBLOCKING", FMOD_NONBLOCKING},
    {"FMOD_UNIQUE", FMOD_UNIQUE},
    {"FMOD_3D_HEADRELATIVE", FMOD_3D_HEADRELATIVE},
    {"FMOD_3D_WORLDRELATIVE", FMOD_3D_WORLDRELATIVE},
    {"FMOD_3D_INVERSEROLLOFF", FMOD_3D_INVERSEROLLOFF},
    {"FMOD_3D_LINEARROLLOFF", FMOD_3D_LINEARROLLOFF},
    {"FMOD_3D_LINEARSQUAREROLLOFF", FMOD_3D_LINEARSQUAREROLLOFF},
    {"FMOD_3D_INVERSETAPEREDROLLOFF", FMOD_3D_INVERSETAPEREDROLLOFF},
    {"FMOD_3D_CUSTOMROLLOFF", FMOD_3D_CUSTOMROLLOFF},
    {"FMOD_3D_IGNOREGEOMETRY", FMOD_3D_IGNOREGEOMETRY},
    {"FMOD_IGNORETAGS", FMOD_IGNORETAGS},
    {"FMOD_LOWMEM", FMOD_LOWMEM},
    {"FMOD_VIRTUAL_PLAYFROMSTART", FMOD_VIRTUAL_PLAYFROMSTART},
}};

unsigned int getFmodFlagSound(const char* flagName)
{
    for (unsigned int i = 0; i <= (28); i++)
    {
        if (stricmp(flagName, getFmodSoundFlags[i].Flag_Name) == 0 ||
            (getFmodSoundFlags[i].Flag_Name && stricmp(flagName, getFmodSoundFlags[i].Flag_Name) == 0))
        {
            return getFmodSoundFlags[i].soundFlag;
        }
    }
    return getFmodSoundFlags[0].soundFlag;
}

