// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#ifndef __VEHICLETEST_H__
#define __VEHICLETEST_H__

#include "CoreUObject.h"
#include "CoreMinimal.h"
#include "Engine.h"

DECLARE_LOG_CATEGORY_EXTERN(VehicleTestLog, Log, All);

#define HMD_MODULE_INCLUDED 1

#define NETMODE_WORLD (((GEngine == nullptr) || (GetWorld() == nullptr)) ? TEXT("") \
        : (GEngine->GetNetMode(GetWorld()) == NM_Client) ? TEXT("[Client] ") \
        : (GEngine->GetNetMode(GetWorld()) == NM_ListenServer) ? TEXT("[ListenServer] ") \
        : (GEngine->GetNetMode(GetWorld()) == NM_DedicatedServer) ? TEXT("[DedicatedServer] ") \
        : TEXT("[Standalone] "))

#if _MSC_VER
#define FUNC_NAME    TEXT(__FUNCTION__)
#else // FIXME - GCC?
#define FUNC_NAME    TEXT(__func__)
#endif

#define TRACE(Format, ...) \
{ \
    SET_WARN_COLOR(COLOR_CYAN);\
    const FString Msg = FString::Printf(TEXT(Format), ##__VA_ARGS__); \
    if (Msg == "") \
    { \
        UE_LOG(VehicleTestLog, Log, TEXT("%s%s() : %s"), NETMODE_WORLD, FUNC_NAME, *GetNameSafe(this));\
    } \
    else \
    { \
        UE_LOG(VehicleTestLog, Log, TEXT("%s%s() : %s"), NETMODE_WORLD, FUNC_NAME, *Msg);\
    } \
    CLEAR_WARN_COLOR();\
}

#endif


