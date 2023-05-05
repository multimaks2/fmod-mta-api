#pragma once
#include "CLuaDefs.h"

class CLuaFMOD : public CLuaDefs
{
public:
    static void LoadFunctions();
    static void AddClass(lua_State* luaVM);

    // �������� � �������������
    LUA_DECLARE(createFmodStudioCore);            // �������� ���� FMOD Studio
    LUA_DECLARE(createCoreFmod);                  // �������� ���� FMOD
    LUA_DECLARE(initFmodCore);                    // ������������� ���� FMOD
    LUA_DECLARE(initFmodStudio);                  // ������������� FMOD Studio
    LUA_DECLARE(globalCloseFmod);                 // ������������ ���� �������� FMOD
    LUA_DECLARE(closeCoreFmod);                   // �������� ���� FMOD
    LUA_DECLARE(closeStudioFmod);                 // �������� FMOD Studio

    // ���������� FMOD
    LUA_DECLARE(fmodAllUpdate);

    // ������ � ������� ������
    LUA_DECLARE(loadFmodBankFile);                   // �������� ����� ������
    LUA_DECLARE(unloadFmodBankFile);                 // �������� ����� ������
    LUA_DECLARE(getFmodBankLoadingState);            // ��������� ��������� �������� ����� ������

    // ������ �� �������
    LUA_DECLARE(setFmodMuteAllSounds);            // ��������� ���� �� ��� �����
    LUA_DECLARE(isFmodMuteAllSounds);             // ��������� ��������� ���� �� ��� �����

    // ������ � ��������� ������
    LUA_DECLARE(loadFmodEvent);                             // �������� ������� �����
    LUA_DECLARE(playFmodEvent);                             // ��������������� ������� �����
    LUA_DECLARE(stopFmodEvent);                             // ��������� ������� �����
    LUA_DECLARE(getFmodEventPlaybackState);                 // ��������� ��������� ��������������� ������� �����
    LUA_DECLARE(setPauseFmodEvent);                         // ����� ������� �����
    LUA_DECLARE(getPauseFmodEvent);                         // ��������� ��������� ����� ������� �����
    LUA_DECLARE(setEventVolume);                            // ��������� ��������� ������� �����
    LUA_DECLARE(getEventVolume);                            // ��������� ��������� ������� �����
    LUA_DECLARE(setPosFmodEvent);                           // ��������� ������� ��������������� ������� �����
    LUA_DECLARE(getPosFmodEvent);                           // ��������� ������� ��������������� ������� �����
    LUA_DECLARE(setFmodEventParameterByName);               // ��������� ��������� ������� ����� �� �����
    LUA_DECLARE(updateFmodEventParameterByName);            // ���������� ��������� ������� ����� �� �����

    // ������ �� ���������� � 3D ������
    LUA_DECLARE(set3DListenerPosition);            // ��������� ������� ��������� � ������������

    // �������������� ��������
    LUA_DECLARE(IsFmodCoreInit);            // �������� ������������� ���� FMOD
    LUA_DECLARE(IsFmodStudioInit);          // �������� ������������� FMOD STUDIO

    // ������
    LUA_DECLARE(getFmodDirectory);

    // ����
    LUA_DECLARE(createFmodSound);
    LUA_DECLARE(playFmodSound);
    LUA_DECLARE(stopFmodSound);
    LUA_DECLARE(IsFmodSoundPlaying);
};
