#include "StdInc.h"
#include "CLuaFmod.hpp" // helper :)

void CLuaFMOD::LoadFunctions()
{
    constexpr static const std::pair<const char*, lua_CFunction> functions[]{
        {"createFmodStudioCore",createFmodStudioCore},
        {"createCoreFmod",createCoreFmod},
        {"initFmodCore",initFmodCore},
        {"initFmodStudio",initFmodStudio},
        {"globalCloseFmod",globalCloseFmod},
        {"closeCoreFmod",closeCoreFmod},
        {"closeStudioFmod",closeStudioFmod},
        {"fmodAllUpdate",fmodAllUpdate},
        {"loadFmodBankFile",loadFmodBankFile},
        {"unloadFmodBankFile",unloadFmodBankFile},
        {"getFmodBankLoadingState",getFmodBankLoadingState},
        {"setFmodMuteAllSounds",setFmodMuteAllSounds},
        {"isFmodMuteAllSounds",isFmodMuteAllSounds},
        {"loadFmodEvent",loadFmodEvent},
        {"playFmodEvent",playFmodEvent},
        {"stopFmodEvent",stopFmodEvent},
        {"getFmodEventPlaybackState",getFmodEventPlaybackState},
        {"setPauseFmodEvent",setPauseFmodEvent},
        {"getPauseFmodEvent",getPauseFmodEvent},
        {"setEventVolume",setEventVolume},
        {"getEventVolume",getEventVolume},
        {"setPosFmodEvent",setPosFmodEvent},
        {"getPosFmodEvent",getPosFmodEvent},
        {"setFmodEventParameterByName",setFmodEventParameterByName},
        {"updateFmodEventParameterByName",updateFmodEventParameterByName},
        {"set3DListenerPosition",set3DListenerPosition},
        {"IsFmodCoreInit",IsFmodCoreInit},
        {"IsFmodStudioInit",IsFmodStudioInit},
        {"getFmodDirectory",getFmodDirectory},


    };


    // Add functions
    for (const auto& [name, func] : functions)
        CLuaCFunctions::AddFunction(name, func);
}

void CLuaFMOD::AddClass(lua_State* luaVM)
{
        lua_newclass(luaVM);
        lua_classfunction(luaVM, "createFmodStudioCore",            "createFmodStudioCore");
        lua_classfunction(luaVM, "createCoreFmod",                  "createCoreFmod");
        lua_classfunction(luaVM, "initFmodCore",                    "initFmodCore");
        lua_classfunction(luaVM, "initFmodStudio",                  "initFmodStudio");
        lua_classfunction(luaVM, "globalCloseFmod",                 "globalCloseFmod");
        lua_classfunction(luaVM, "closeCoreFmod",                   "closeCoreFmod");
        lua_classfunction(luaVM, "closeStudioFmod",                 "closeStudioFmod");
        lua_classfunction(luaVM, "fmodAllUpdate",                   "fmodAllUpdate");
        lua_classfunction(luaVM, "loadFmodBankFile",                "loadFmodBankFile");
        lua_classfunction(luaVM, "unloadFmodBankFile",              "unloadFmodBankFile");
        lua_classfunction(luaVM, "getFmodBankLoadingState",         "getFmodBankLoadingState");
        lua_classfunction(luaVM, "setFmodMuteAllSounds",            "setFmodMuteAllSounds");
        lua_classfunction(luaVM, "isFmodMuteAllSounds",             "isFmodMuteAllSounds");
        lua_classfunction(luaVM, "loadFmodEvent",                   "loadFmodEvent");
        lua_classfunction(luaVM, "playFmodEvent",                   "playFmodEvent");
        lua_classfunction(luaVM, "stopFmodEvent",                   "stopFmodEvent");
        lua_classfunction(luaVM, "getFmodEventPlaybackState",       "getFmodEventPlaybackState");
        lua_classfunction(luaVM, "setPauseFmodEvent",               "setPauseFmodEvent");
        lua_classfunction(luaVM, "getPauseFmodEvent",               "getPauseFmodEvent");
        lua_classfunction(luaVM, "setEventVolume",                  "setEventVolume");
        lua_classfunction(luaVM, "getEventVolume",                  "getEventVolume");
        lua_classfunction(luaVM, "setPosFmodEvent",                 "setPosFmodEvent");
        lua_classfunction(luaVM, "getPosFmodEvent",                 "getPosFmodEvent");
        lua_classfunction(luaVM, "setFmodEventParameterByName",     "setFmodEventParameterByName");
        lua_classfunction(luaVM, "updateFmodEventParameterByName",  "updateFmodEventParameterByName");
        lua_classfunction(luaVM, "set3DListenerPosition",           "set3DListenerPosition");
        lua_classfunction(luaVM, "IsFmodCoreInit",                  "IsFmodCoreInit");
        lua_classfunction(luaVM, "IsFmodStudioInit",                "IsFmodStudioInit");
        lua_classfunction(luaVM, "getFmodDirectory",                "getFmodDirectory");      

        lua_registerclass(luaVM, "FMOD", "Element");
}




//int CLuaFMOD::getFmodCore(lua_State* luaVM)
//{
//    lua_push_element_fmod_core(luaVM, f_system);
//    //lua_pushlightuserdata(luaVM, &f_system); // выдает статичный указатель вроде ка
//    return 1;
//}




bool is_fmod_core_init = false;
bool IsFmodCoreInit()
{
    return is_fmod_core_init;
}
int CLuaFMOD::IsFmodCoreInit(lua_State* luaVM)
{

    lua_pushboolean(luaVM, ::IsFmodCoreInit());
    return 1;
}

bool is_fmod_studio_init = false;
bool IsFmodStudioInit()
{
     return is_fmod_studio_init;
}
int CLuaFMOD::IsFmodStudioInit(lua_State* luaVM)
{
     lua_pushboolean(luaVM, ::IsFmodStudioInit());
     return 1;
}



int CLuaFMOD::createFmodStudioCore(lua_State* luaVM)
{
     if (::IsFmodStudioInit() == false)
     {
        is_fmod_studio_init = true;
        lua_pushstring(luaVM, FMODErrorCheck(FMOD::Studio::System::create(&f_studio), "create Studio Core"));
        f_studio->update();
        return 1;
     }
     else
     {
        lua_pushstring(luaVM, const_to_string ("fmod studio has already been created"));
        return 1;
     }
     return 1;
}



int CLuaFMOD::createCoreFmod(lua_State* luaVM)
{
     //FMOD::System*    localSystem;
     //CScriptArgReader argStream(luaVM);
     //argStream.ReadUserData(localSystem);
  

     if (::IsFmodCoreInit() == false)
     {
         is_fmod_core_init = true;
         lua_pushstring(luaVM, FMODErrorCheck(FMOD::System_Create(&f_system), "create Core"));
         f_system->setSoftwareFormat(AUDIO_SAMPLE_RATE, FMOD_SPEAKERMODE_STEREO, 0);
         f_system->set3DSettings(1.0, DISTANCEFACTOR, 0.5f);
         f_system->getMasterChannelGroup(&mastergroup);
         f_system->update();
         return 1;
     }
     else
     {
         lua_pushstring(luaVM, const_to_string("Ядро уже создано"));
         return 1;
     }
     return 1;
}


SString closeCoreFmod()
{
     if (::IsFmodCoreInit())
     {
         f_system->update();
         FMOD_RESULT result = f_system->close();
         if (result != FMOD_OK)
         {
             return FMODErrorCheck(result, "closeCoreFmod -> close");
         }
         f_system->update();
         result = f_system->release();
         if (result != FMOD_OK)
         {
             return FMODErrorCheck(result, "closeCoreFmod -> release");

         }
         is_fmod_core_init = false;
         f_system = nullptr;
     }
     return "status - OK";
 }
int CLuaFMOD::closeCoreFmod(lua_State* luaVM)
{
     lua_pushstring(luaVM, ::closeCoreFmod());
     return 1;
}




SString closeStudioFmod()
{
     if (f_studio == nullptr)
     {
         return "status - already closed";
     }

     if (::IsFmodStudioInit() == true)
     {
         f_studio->update();

         FMOD_RESULT result = f_studio->unloadAll();
         f_studio->update();
         if (result != FMOD_OK)
         {
             //return FMODErrorCheck(result, "closeStudioFmod -> unloadAll");
         }
         f_studio->update();
         result = f_studio->release();
         if (result != FMOD_OK)
         {
             //return FMODErrorCheck(result, "closeStudioFmod -> release");
         }
         is_fmod_studio_init = false;
         f_studio = nullptr;
         return "status - OK";
     }
     return "fmod studio not used";
 }
int CLuaFMOD::closeStudioFmod(lua_State* luaVM)
{
     lua_pushstring(luaVM, ::closeStudioFmod());
     return 1;
}


 bool globalCloseFmod()
{
     auto statusOk = "status - OK";
     if (closeCoreFmod() == statusOk && closeStudioFmod() == statusOk)
     {
         return true;
     }
     return false;
 }
int CLuaFMOD::globalCloseFmod(lua_State* luaVM)
{
     lua_pushboolean(luaVM, ::globalCloseFmod());
     return 1;
}


// FMOD API INIT CORE
SString initFmodCore(int mxchannel, const char* flagName)
{
     if (::IsFmodCoreInit() == true)
     {
         return FMODErrorCheck(f_system->init(mxchannel, getFmodCoreFlag(flagName), nullptr), "initCoreFmod");
         f_system->update();
     } else
         return "the fmod core must be created for initialization";
 }
int CLuaFMOD::initFmodCore(lua_State* luaVM)
{
     int              mxchannel;
     SString          flagName;
     CScriptArgReader argStream(luaVM);
     argStream.ReadNumber(mxchannel);
     argStream.ReadString(flagName);
     lua_pushstring(luaVM, ::initFmodCore(mxchannel, flagName));
     return 1;
}


// FMOD API INIT STUDIO CORE
SString initFmodStudio(int channel, const char* flagName, const char* flag)
{
    if (::IsFmodStudioInit() == true)
    {
        return FMODErrorCheck(f_studio->initialize(channel, getFmodStudioFlag(flagName), getFmodCoreFlag(flag), extraDriverData), "initFmodStudio");
        f_studio->update();
    } else
    return "the fmod studio must be created for initialization";
}

int CLuaFMOD::initFmodStudio(lua_State* luaVM)
{
    int              channel;
    SString          flagName;
    SString          flag;
    CScriptArgReader argStream(luaVM);
    argStream.ReadNumber(channel);
    argStream.ReadString(flagName);
    argStream.ReadString(flag);
    lua_pushstring(luaVM, ::initFmodStudio(channel, flagName, flag));
    return 1;
}


bool fmodAllUpdate()
{
    if (::IsFmodCoreInit() == true)
    {
    f_system->update();
    }
    if (::IsFmodStudioInit() == true)
    {
        f_studio->update();
    }
    return true;
}

 int CLuaFMOD::fmodAllUpdate(lua_State* luaVM)
{
    lua_pushboolean(luaVM, ::fmodAllUpdate());
     return 1;
 }

 void set3DListenerPosition(float posX, float posY, float posZ, float forwardX, float forwardY, float forwardZ, float upX, float upY, float upZ)
 {
     listenerpos = {posX, posY, posZ};
     forward =     {forwardX, forwardY, forwardZ};
     up =          {upX, upY, upZ};
     f_system->set3DListenerAttributes(0, &listenerpos, 0, &forward, &up);
 }

 int CLuaFMOD::set3DListenerPosition(lua_State* luaVM)
 {
     float            posX, posY, posZ, forwardX, forwardY, forwardZ, upX, upY, upZ;
     CScriptArgReader argStream(luaVM);
     argStream.ReadNumber(posX);
     argStream.ReadNumber(posY);
     argStream.ReadNumber(posZ);
     argStream.ReadNumber(forwardX);
     argStream.ReadNumber(forwardY);
     argStream.ReadNumber(forwardZ);
     argStream.ReadNumber(upX);
     argStream.ReadNumber(upY);
     argStream.ReadNumber(upZ);

     ::set3DListenerPosition( posX, posY, posZ, forwardX, forwardY, forwardZ, upX, upY, upZ);
     lua_pushboolean(luaVM, true);
     return 1;
 }


 // Логика загрузки/выгрузки/проверки банк файлов
bool loadFmodBankFile(const char* bankDir)
 {
     FMOD::Studio::Bank* pBank;
     if (f_studio->loadBankFile(bankDir, FMOD_STUDIO_LOAD_BANK_NORMAL, &pBank) == FMOD_OK)
     {
        ArrayMap->mBanks[bankDir] = pBank;
        return true;
     }
     return false;
 }

 int CLuaFMOD::loadFmodBankFile(lua_State* luaVM)
 {
     SString          bankDir;
     CScriptArgReader argStream(luaVM);
     argStream.ReadString(bankDir);
     lua_pushboolean(luaVM, ::loadFmodBankFile(bankDir));
     return 1;
 }

 bool unloadFmodBankFile(const char* bankDir)
 {
     result = ArrayMap->mBanks[bankDir]->unload();
     if (result == FMOD_OK)
     {
        if (ArrayMap->mBanks.erase(bankDir))
        {
            return true;
        }
     }
     return false;
 }

  int CLuaFMOD::unloadFmodBankFile(lua_State* luaVM)
 {
     bool             state = false;
     SString          bankDir;
     CScriptArgReader argStream(luaVM);
     argStream.ReadString(bankDir);
     state = ::unloadFmodBankFile(bankDir);
     lua_pushboolean(luaVM, state);
     return 1;
 }

 SString getFmodBankLoadingState(const char* bankDir)
 {
     FMOD_STUDIO_LOADING_STATE state;
     if (FMOD_OK == (result = ArrayMap->mBanks[bankDir]->getLoadingState(&state) ))
         return SString("%s",getLocalizedLoadingStateBank[state].state);
return SString("[Ошибка -> %s] [Функция -> %s] [Параметры -> %s]", FMOD_ErrorString(result), "getFmodBankLoadingState",bankDir);            // при загрузке ресурсов произошла ошибка
 }

   int CLuaFMOD::getFmodBankLoadingState(lua_State* luaVM)
 {
     SString          bankDir;
     CScriptArgReader argStream(luaVM);
     argStream.ReadString(bankDir);
     lua_pushstring(luaVM, ::getFmodBankLoadingState(bankDir));
     return 1;
 }


// Логика событий

SString loadFmodEvent(const char* eventName)
 {
     FMOD::Studio::EventDescription* pEventDescription = NULL;
     result = f_studio->getEvent(eventName, &pEventDescription);
     if (pEventDescription)
     {
        FMOD::Studio::EventInstance* pEventInstance = NULL;
        pEventDescription->createInstance(&pEventInstance);
        if (pEventInstance)
        {
            if (ArrayMap->mEvents[eventName] = pEventInstance);
            {
                return SString("%s -> Загружен", eventName);
            }
        }
     }
     return SString("[Ошибка -> %s] [Функция -> %s] [Параметры -> %s]", FMOD_ErrorString(result), "loadFmodEvent", eventName);  
 }

int CLuaFMOD::loadFmodEvent(lua_State* luaVM)
{
     SString          eventName;
     CScriptArgReader argStream(luaVM);
     argStream.ReadString(eventName);
     lua_pushstring(luaVM, ::loadFmodEvent(eventName));
     return 1;
}


SString playFmodEvent(const char* eventName)
 {
     auto localEvent = ArrayMap->mEvents.find(eventName);
     if (localEvent != ArrayMap->mEvents.end())
     {
        if (FMOD_OK == (result = ArrayMap->mEvents[eventName]->start()))
        {
            return SString("%s -> Запустили", eventName);
        }
        return SString("[Ошибка -> %s] [Функция -> %s] [Параметры -> %s]", FMOD_ErrorString(result), "playFmodEvent", eventName); 
     }
     return SString("[Ошибка -> %s] [Функция -> %s] [Параметры -> %s]", "Событие не найдено", "playFmodEvent", eventName); 
 }
 int CLuaFMOD::playFmodEvent(lua_State* luaVM)
 {
     SString          eventName;
     CScriptArgReader argStream(luaVM);
     argStream.ReadString(eventName);
     lua_pushstring(luaVM, ::playFmodEvent(eventName));
     return 1;
 }


// bImmediate = true = немедленая остановка звукового события
// bImmediate = false = звуковое событие будет остановлено с плавным затуханием
SString stopFmodEvent(const char* eventName, bool bImmediate)
 {
     auto                  localEvent = ArrayMap->mEvents.find(eventName);
     if (localEvent != ArrayMap->mEvents.end())
     {
        FMOD_STUDIO_STOP_MODE eMode;
        eMode = bImmediate ? FMOD_STUDIO_STOP_IMMEDIATE : FMOD_STUDIO_STOP_ALLOWFADEOUT;
        if (FMOD_OK == (result = localEvent->second->stop(eMode)))
        {
            return SString("%s -> Остановлен, Параметр затухания -> [%s]", eventName, bImmediate ? "немедленно" : "с затуханием");
        }
        return SString("[Ошибка -> %s] [Функция -> %s] [Параметры -> 1 - (%s) 2 - (%s) ]", FMOD_ErrorString(result), "playFmodEvent", eventName, bImmediate); 
     }
     return SString("[Ошибка -> %s] [Функция -> %s] [Параметры -> 1 - (%s) 2 - (%s) ]", "Событие не найдено", "playFmodEvent", eventName, bImmediate); 
 }
 int CLuaFMOD::stopFmodEvent(lua_State* luaVM)
 {
     SString          eventName;
     bool             bImmediate;
     CScriptArgReader argStream(luaVM);
     argStream.ReadString(eventName);
     argStream.ReadBool(bImmediate);
     lua_pushstring(luaVM, ::stopFmodEvent(eventName, bImmediate));
     return 1;
 }


 SString getFmodEventPlaybackState(const char* eventName)
 {
     auto localEvent = ArrayMap->mEvents.find(eventName);
     if (localEvent != ArrayMap->mEvents.end())
     {
        FMOD_STUDIO_PLAYBACK_STATE state;
        if (FMOD_OK == (result = ArrayMap->mEvents[eventName]->getPlaybackState(&state)))
        {
            return getLocalizedEventPlaying[state].state;
        }
     }
     return SString("%s", "Ошибка состояния");
 }
 int CLuaFMOD::getFmodEventPlaybackState(lua_State* luaVM)
 {
     SString          eventName;
     CScriptArgReader argStream(luaVM);
     argStream.ReadString(eventName);
     lua_pushstring(luaVM, ::getFmodEventPlaybackState(eventName));
     return 1;
 }


SString setPauseFmodEvent(const char* eventName,bool pState)
 {
     auto localEvent = ArrayMap->mEvents.find(eventName);
     if (localEvent != ArrayMap->mEvents.end())
     {
        if (FMOD_OK == (result = localEvent->second->setPaused(pState)))
        {
            return SString("%s", pState ? "Остановить" : "Продолжить");
        }
        return SString("[Ошибка -> %s] [Функция -> %s] [Параметры -> %s ]", FMOD_ErrorString(result), "setPauseFmodEvent", eventName); 
     }
     return SString("[Ошибка -> %s] [Функция -> %s] [Параметры -> %s ]", "Событие не найдено", "setPauseFmodEvent", eventName); 
 }
 int CLuaFMOD::setPauseFmodEvent(lua_State* luaVM)
 {
     SString          eventName;
     bool             pState;
     CScriptArgReader argStream(luaVM);
     argStream.ReadString(eventName);
     argStream.ReadBool(pState);
     lua_pushstring(luaVM, ::setPauseFmodEvent(eventName,pState));
     return 1;
 }


SString getPauseFmodEvent(const char* eventName)
 {
     bool pState;
     auto localEvent = ArrayMap->mEvents.find(eventName);
     if (localEvent != ArrayMap->mEvents.end())
     {
        if (FMOD_OK == (result = localEvent->second->getPaused(&pState)))
        {
            return SString("%s", pState ? "Пауза" : "Воспроизводится");
        }
        return SString("[Ошибка -> %s] [Функция -> %s] [Параметры -> %s ]", FMOD_ErrorString(result), "getPauseFmodEvent", eventName); 
     }
     return SString("[Ошибка -> %s] [Функция -> %s] [Параметры -> %s ]", "Событие не найдено", "getPauseFmodEvent", eventName); 
 }
 int CLuaFMOD::getPauseFmodEvent(lua_State* luaVM)
 {
     SString          eventName;
     CScriptArgReader argStream(luaVM);
     argStream.ReadString(eventName);
     lua_pushstring(luaVM, ::getPauseFmodEvent(eventName));
     return 1;
 }


 bool setEventVolume(const char* name, float value)
 {
     auto localEvent = ArrayMap->mEvents.find(name);
     if (localEvent != ArrayMap->mEvents.end())
     {
        if (ArrayMap->mEvents[name]->setVolume(value) == FMOD_OK)
            return true;
     }
     return false;
 }
 int CLuaFMOD::setEventVolume(lua_State* luaVM)
 {
     SString          eventName;
     float            value;
     CScriptArgReader argStream(luaVM);
     argStream.ReadString(eventName);
     argStream.ReadNumber(value);
     lua_pushboolean(luaVM, ::setEventVolume(eventName, value));
     return 1;
 }


float getEventVolume(const char* name)
 {
     auto localEvent = ArrayMap->mEvents.find(name);
     if (localEvent != ArrayMap->mEvents.end())
     {
        float volume = 0.0f;
        if (ArrayMap->mEvents[name]->getVolume(&volume) == FMOD_OK)
        {
            return volume;
        }
     }
     return -1000.0f;
 }
 int CLuaFMOD::getEventVolume(lua_State* luaVM)
 {
     SString          eventName;
     CScriptArgReader argStream(luaVM);
     argStream.ReadString(eventName);
     float numberFloat = ::getEventVolume(eventName);
     if (numberFloat == -1000.0f)
     {
        lua_pushboolean(luaVM, false);
     }
     lua_pushnumber(luaVM, numberFloat);
     return 1;
 }


// (posX, posY, posZ) представляет собой 3D-координаты положения объекта
// (velX, velY, velZ) - вектор направления движения объекта
 SString setPosFmodEvent(const char* eventName, float posX, float posY, float posZ, float velX, float velY, float velZ)
 {
     auto localEvent = ArrayMap->mEvents.find(eventName);
     if (localEvent != ArrayMap->mEvents.end())
     {
        //FMOD_3D_ATTRIBUTES attributes = {{posX, posY, posZ}, {velX, velY, velZ}};
        FMOD_3D_ATTRIBUTES attributes = {};
        attributes.position.x = posX;
        attributes.position.y = posY;
        attributes.position.z = posZ;
        attributes.velocity.x = velX;
        attributes.velocity.y = velY;
        attributes.velocity.z = velZ;
        if (FMOD_OK == (result = localEvent->second->set3DAttributes(&attributes)))
        {
            return SString("%s", true);
        }
        return SString("[Ошибка -> %s] [Функция -> %s] [Параметры -> %s ]", FMOD_ErrorString(result), "set3DPosFmodEvent", eventName);
     }
     return SString("[Ошибка -> %s] [Функция -> %s] [Параметры -> %s ]", "Событие не найдено", "set3DPosFmodEvent", eventName);
 }
 int CLuaFMOD::setPosFmodEvent(lua_State* luaVM)
 {
     SString          eventName;
     float            posX, posY, posZ, velX, velY, velZ;
     CScriptArgReader argStream(luaVM);
     argStream.ReadString(eventName);
     argStream.ReadNumber(posX);
     argStream.ReadNumber(posY);
     argStream.ReadNumber(posZ);
     argStream.ReadNumber(velX);
     argStream.ReadNumber(velY);
     argStream.ReadNumber(velZ);
     lua_pushstring(luaVM, ::setPosFmodEvent(eventName, posX, posY, posZ, velX, velY, velZ));
     return 1;
 }


float getPosFmodEvent(const char* eventName)
 {
     auto localEvent = ArrayMap->mEvents.find(eventName);
     if (localEvent != ArrayMap->mEvents.end())
     {
        FMOD_3D_ATTRIBUTES attributes;
        if (FMOD_OK == (result = localEvent->second->get3DAttributes(&attributes)))
        {
            return attributes.position.x, attributes.position.y, attributes.position.z, attributes.velocity.x, attributes.velocity.y, attributes.velocity.z;
        }
     }
     return 0, 0, 0, 0, 0, 0;
 }
 int CLuaFMOD::getPosFmodEvent(lua_State* luaVM)
 {
     SString          eventName;
     CScriptArgReader argStream(luaVM);
     argStream.ReadString(eventName);
     lua_pushnumber(luaVM, ::getPosFmodEvent(eventName));
     return 1;
 }


SString setFmodEventParameterByName(const char* eventName, const char* param, float value)
 {
     auto localEvent = ArrayMap->mEvents.find(eventName);
     if (localEvent != ArrayMap->mEvents.end())
     {
        if (FMOD_OK == (result = ArrayMap->mEvents[eventName]->setParameterByName(param, value)))
        {
            if (ArrayMap->mEvents[eventName]->start())
            {
                return SString("%s","Старт");
            }
            return SString("[Ошибка -> %s] [Функция -> %s] [Параметры -> (%s), (%s), (%s) ]", FMOD_ErrorString(result), "setFmodEventParameterByName", eventName, param,value);
        }
     }
     return SString("[Ошибка -> %s] [Функция -> %s] [Параметры -> (%s), (%s), (%s) ]", "Событие не найдено", "setFmodEventParameterByName", eventName, param, value);
 }
 int CLuaFMOD::setFmodEventParameterByName(lua_State* luaVM)
 {
     SString          eventName, param;
     float            value;
     CScriptArgReader argStream(luaVM);
     argStream.ReadString(eventName);
     argStream.ReadString(param);
     argStream.ReadNumber(value);
     lua_pushstring(luaVM, ::setFmodEventParameterByName(eventName,param,value));
     return 1;
 }

SString updateFmodEventParameterByName(const char* eventName, const char* param, float value)
 {
     auto localEvent = ArrayMap->mEvents.find(eventName);
     if (localEvent != ArrayMap->mEvents.end())
     {
        if (FMOD_OK == (result = ArrayMap->mEvents[eventName]->setParameterByName(param, value)))
        {
            return SString("%s", "успешно");
        }
        return SString("[Ошибка -> %s] [Функция -> %s] [Параметры -> (%s), (%s), (%s) ]", FMOD_ErrorString(result), "updateFmodEventParameterByName", eventName, param,value);
     }
     return SString("[Ошибка -> %s] [Функция -> %s] [Параметры -> (%s), (%s), (%s) ]", "Событие не найдено", "updateFmodEventParameterByName", eventName, param, value);
 }
 int CLuaFMOD::updateFmodEventParameterByName(lua_State* luaVM)
 {
     SString          eventName, param;
     float            value;
     CScriptArgReader argStream(luaVM);
     argStream.ReadString(eventName);
     argStream.ReadString(param);
     argStream.ReadNumber(value);
     lua_pushstring(luaVM, ::updateFmodEventParameterByName(eventName, param, value));
     return 1;
 }

// Настройки мастера получили при создании f_system
bool setFmodMuteAllSounds(bool mState)
 {
     (mastergroup->setMute(mState));
     muted = mState;
     return muted;
 }
 int CLuaFMOD::setFmodMuteAllSounds(lua_State* luaVM)
 {
     bool             mState;
     CScriptArgReader argStream(luaVM);
     argStream.ReadBool(mState);
     lua_pushboolean(luaVM, ::setFmodMuteAllSounds(mState));
     return 1;
 }



 bool isFmodMuteAllSounds()
 {
     return muted;
 }
 int CLuaFMOD::isFmodMuteAllSounds(lua_State* luaVM)
 {
     lua_pushboolean(luaVM, ::isFmodMuteAllSounds());
     return 1;
 }


 int CLuaFMOD::getFmodDirectory(lua_State* luaVM)
 {
     SString          resourceName;
     SString          file;
     CScriptArgReader argStream(luaVM);
     argStream.ReadString(resourceName);
     argStream.ReadString(file);
     auto returnData = ::getFmodDirectory(resourceName, file);
     if (returnData)
     {
        lua_pushstring(luaVM, returnData);
        return 1;
     }

     lua_pushboolean(luaVM, false);
     return 1;
 }

 SString createFmodSound(const char* sound_dir, const char* flagName)
 {
     FMOD::Sound* pSound = nullptr;
     result = f_system->createSound(sound_dir, getFmodFlagSound(flagName), nullptr, &pSound);
     if (result == FMOD_OK)
     {
        if (ArrayMap->mSounds[sound_dir] = pSound)
        {
            return SString("%s", true);
        }
        return SString("[Ошибка -> %s] [Функция -> %s] [Параметры -> (%s), (%s)]", FMOD_ErrorString(result), "createFmodSound", sound_dir,flagName);
     }
     return SString("[Ошибка -> %s] [Функция -> %s] [Параметры -> (%s), (%s)]", FMOD_ErrorString(result), "createFmodSound", sound_dir, flagName);
 }

 int CLuaFMOD::createFmodSound(lua_State* luaVM)
 {
     SString          sound_dir;
     SString          sound_flag;
     CScriptArgReader argStream(luaVM);
     argStream.ReadString(sound_dir);
     argStream.ReadString(sound_flag);

     auto returnData = ::createFmodSound(sound_dir, sound_flag);
     if (returnData)
     {
        lua_pushstring(luaVM, returnData);
        return 1;
     }
     lua_pushboolean(luaVM, false);
     return 1;
 }


 int playFmodSound(const char* soundDir)
 {
     int            nChannelID = ArrayMap->mnNextChannelId++;
     FMOD::Channel* pChannel = nullptr;
     result = f_system->playSound(ArrayMap->mSounds[soundDir], nullptr, false, &pChannel);
     ArrayMap->mChannels[nChannelID] = pChannel;
     if (result == FMOD_OK)
     {
        return -1;
     }
     return nChannelID;
 }

  int CLuaFMOD::playFmodSound(lua_State* luaVM)
 {
     SString          sound_dir;
     CScriptArgReader argStream(luaVM);
     argStream.ReadString(sound_dir);
     auto returnData = ::playFmodSound(sound_dir);
     if (returnData)
     {
        lua_pushnumber(luaVM, returnData);
        return 1;
     }
     lua_pushboolean(luaVM, false);
     return 1;
 }


 int stopFmodSound(const char* soundDir)
 {
     return 1;
 }

