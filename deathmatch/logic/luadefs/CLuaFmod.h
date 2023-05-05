#pragma once
#include "CLuaDefs.h"

class CLuaFMOD : public CLuaDefs
{
public:
    static void LoadFunctions();
    static void AddClass(lua_State* luaVM);

    // Создание и инициализация
    LUA_DECLARE(createFmodStudioCore);            // Создание ядра FMOD Studio
    LUA_DECLARE(createCoreFmod);                  // Создание ядра FMOD
    LUA_DECLARE(initFmodCore);                    // Инициализация ядра FMOD
    LUA_DECLARE(initFmodStudio);                  // Инициализация FMOD Studio
    LUA_DECLARE(globalCloseFmod);                 // Освобождение всех ресурсов FMOD
    LUA_DECLARE(closeCoreFmod);                   // Закрытие ядра FMOD
    LUA_DECLARE(closeStudioFmod);                 // Закрытие FMOD Studio

    // Обновление FMOD
    LUA_DECLARE(fmodAllUpdate);

    // Работа с банками звуков
    LUA_DECLARE(loadFmodBankFile);                   // Загрузка банка звуков
    LUA_DECLARE(unloadFmodBankFile);                 // Выгрузка банка звуков
    LUA_DECLARE(getFmodBankLoadingState);            // Получение состояния загрузки банка звуков

    // Работа со звуками
    LUA_DECLARE(setFmodMuteAllSounds);            // Установка мута на все звуки
    LUA_DECLARE(isFmodMuteAllSounds);             // Получение состояния мута на все звуки

    // Работа с событиями звуков
    LUA_DECLARE(loadFmodEvent);                             // Загрузка события звука
    LUA_DECLARE(playFmodEvent);                             // Воспроизведение события звука
    LUA_DECLARE(stopFmodEvent);                             // Остановка события звука
    LUA_DECLARE(getFmodEventPlaybackState);                 // Получение состояния воспроизведения события звука
    LUA_DECLARE(setPauseFmodEvent);                         // Пауза события звука
    LUA_DECLARE(getPauseFmodEvent);                         // Получение состояния паузы события звука
    LUA_DECLARE(setEventVolume);                            // Установка громкости события звука
    LUA_DECLARE(getEventVolume);                            // Получение громкости события звука
    LUA_DECLARE(setPosFmodEvent);                           // Установка позиции воспроизведения события звука
    LUA_DECLARE(getPosFmodEvent);                           // Получение позиции воспроизведения события звука
    LUA_DECLARE(setFmodEventParameterByName);               // Установка параметра события звука по имени
    LUA_DECLARE(updateFmodEventParameterByName);            // Обновление параметра события звука по имени

    // Работа со слушателем и 3D звуком
    LUA_DECLARE(set3DListenerPosition);            // Установка позиции слушателя в пространстве

    // Дополнительные проверки
    LUA_DECLARE(IsFmodCoreInit);            // Проверка инициализации ядра FMOD
    LUA_DECLARE(IsFmodStudioInit);          // Проверка инициализации FMOD STUDIO

    // Прочее
    LUA_DECLARE(getFmodDirectory);

    // Звук
    LUA_DECLARE(createFmodSound);
    LUA_DECLARE(playFmodSound);
    LUA_DECLARE(stopFmodSound);
    LUA_DECLARE(IsFmodSoundPlaying);
};
