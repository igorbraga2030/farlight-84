#pragma once

#ifndef BLOODHUNT_H

#include <windows.h>
#include <psapi.h>
#include <tlhelp32.h>
#include <iostream>
#include <dwmapi.h>
#include  <d3d9.h>
#include  <d3dx9.h>

#include "singleton.h"
#include "vector.h"
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "dwmapi.lib")

inline namespace BloodHunt
{
	class Variables : public Singleton<Variables>
	{
	public:
		const char* dwProcessName = "SolarlandClient-Win64-Shipping.exe";
		DWORD dwProcessId = NULL;
		uint64_t dwProcess_Base = NULL;
		HWND gameHWND = NULL;

		int actor_count = NULL;
		int ScreenHeight = NULL;
		int ScreenWidth = NULL;
		int ScreenLeft = NULL;
		int ScreenRight = NULL;
		int ScreenTop = NULL;
		int ScreenBottom = NULL;

		float ScreenCenterX = ScreenWidth / 2;
		float ScreenCenterY = ScreenHeight / 2;

		DWORD_PTR game_instance = NULL;
		DWORD_PTR u_world = NULL;
		DWORD_PTR local_player_pawn = NULL;
		DWORD_PTR local_player_array = NULL;
		DWORD_PTR local_player = NULL;
		DWORD_PTR local_player_root = NULL;
		DWORD_PTR local_player_controller = NULL;
		DWORD_PTR local_player_state = NULL;
		DWORD_PTR persistent_level = NULL;
		DWORD_PTR actors = NULL;
	};
#define GameVars BloodHunt::Variables::Get()

	class Offsets : public Singleton<Offsets>
	{
	public:

		
DWORD offset_u_world = 0x71662A8;// 48 8B 1D ? ? ? ? 48 85 DB 74 ? 41 B0 01 sub_7FF6523B26B0 mov rbx, cs : 7FF658411CE0h // 0x7026B0 or // 0x23B26B0 // 676 1CE0
DWORD offset_g_names = 0x6FF5740;// 4C 8D 05 ? ? ? ? EB ? 48 8D 0D ? ? ? ? E8 sub_7FF6540BE2E0 db 48h; H 7FF651CB0000 // 0x240E2E0 7FF6582A2240
DWORD offset_g_obj = 0x7025690;// 48 8B 05 ? ? ? ? 48 8B 0C C8 4C 8D 04 D1 .text:00007FF6525547D8 sub_7FF652554750 mov rax, cs:7FF6582BAA90h
//Camera
DWORD offset_camera_manager = 0x02E8; // APlayerController->PlayerCameraManager
DWORD offset_camera_cache = 0x1c80 ; //APlayerCameraManager->CameraCachePrivate0x2230
DWORD offset_component_to_world = 0x260; // bComponentToWorldUpdated 0x14c 0x1c0 0x14c 0x4701c0 truct FTransform K2_GetComponentToWorld(); // Function Engine.SceneComponent.K2_GetComponentToWorld 0F 28 81 ? ? ? ? 48 8B C2 0F 28 89 ? ? ? ? 0F 29 02
DWORD offset_relative_location = 0x0124;/* + 0x144*/; //USceneComponent->RelativeLocation + 0x144
DWORD offset_relative_Rotation = 0x0130;//USceneComponent->RelativeLocation + 0x144
DWORD offset_ComponentVelocity = 0x0148 ; //USceneComponent->RelativeLocation + 0x144
//Engine
DWORD offset_persistent_level = 0x0030; //UWorld->PersistentLevel
DWORD offset_game_instance = 0x02C0; //UWolrd->OwningGameInstance
DWORD offset_Uscenecomponent = 0x230;
DWORD offset_local_players_array = 0x0038;; //UGameInstance->LocalPlayers
DWORD offset_player_controller = 0x0030; //UPlayer->PlayerController
DWORD offset_apawn = 0x02D0; //APlayerController->AcknowledgedPawn
DWORD offset_root_component = 0x0140; //AActor->RootComponent
DWORD offset_objectid = 0x18;
DWORD offset_actor_array = 0x0098; //UNetConnection->OwningActor
DWORD offset_actor_count = 0x00A0; //UNetConnection->MaxPacket
DWORD offset_actor_id = 0x18;
DWORD offset_player_state = 0x0258; //apawjn->PlayerState
DWORD offset_actor_mesh = 0x0298; //ACharacter->Mesh
DWORD offset_bone_array = 0x05e8;// Class: SkeletalMeshComponent ???? ; Transform[] CachedBoneSpaceTransforms ???? : struct USkinnedMeshComponent : UMeshComponent { struct USkeletalMesh* SkeletalMesh ???
DWORD offset_CachedCurrentWeapon = 0x1A18; // struct ASolarPlayerWeapon* CachedCurrentWeapon; // 0x1a18(0x08)
DWORD offset_RecoilComponent = 0x0598; // // struct UWeaponRecoilComponent* RecoilComponent; // 0x598(0x08)
DWORD offset_USingleWeaponConfig = 0x0488; // // struct USingleWeaponConfig* ; //
DWORD offset_UWeaponShootConfig = 0x718; // struct UWeaponShootConfig
DWORD offset_WeaponConfig = 0x00D0; // possibly WeaponFireModeType; WeaponAbilityTag; or struct FGameplayTag WeaponAbilityTag; // 0xd8(0x08)
DWORD offset_primaryammo = 0x280; // // struct UAmmoConfig* PrimaryAmmo;
DWORD offset_secondaryammo = 0x290; // UAmmoConfig* secondaryammo;
DWORD offset_secondaryupdateammo = 0x02F8; // UAmmoConfig* secondaryupdateammo;
DWORD offset_CurrentClipAmmo = 0x618; // int32_t CurrentClipAmmo; // 0x0618 (0x0004)
DWORD offset_bulletSpeedInitSpeed = 0x00D0; // // Class /Script/Solarland.AmmoConfig float InitSpeed; // 0x00D0 (0x0004)
DWORD offset_bulletSpeedProjectileMaxGravity = 0x0514; // // Class /Script/Solarland.AmmoConfig float ProjectileMaxGravity; // 0x0514 (0x0004)
DWORD offset_FAmmonRecoilScope = 0x03A4; // UAmmoConfig
DWORD offset_FAmmonRecoilRollStruct = 0x03A8; // UAmmoConfig
DWORD offset_FAmmonRecoilScope2 = 0x03E0; // UAmmoConfig
DWORD offset_FAmmonRecoilRollStruct2 = 0x03A0; //UAmmoConfig
DWORD offset_FAmmonRecoilScope3 = 0x03E0; //UAmmoConfig
DWORD offset_FAmmonRecoilRollStruct3 = 0x03A0; // UAmmoConfig
DWORD offset_WeaponTextType = 0x0680; //FString WeaponTextType; // 0x0868 (0x0010)
DWORD offset_Hp = 0x05F0; // //ASolarPlayerState float CurrentHealth; // 0x580(0x04)
DWORD offset_HpMax = 0x05F4; // ASolarPlayerState float MaxHealth; // 0x584(0x04)

DWORD offset_ShieldInfo = 0x05F8;
DWORD offset_ShieldLevel = 0x0; // offset_ShieldInfo + 0x
DWORD offset_Shield = 0x4; // offset_ShieldInfo + 0x
DWORD offset_ShieldMax = 0x1214;
DWORD offset_player_name = 0x03F0; // APlayerState PlayerNamePrivate 0x300 FString
DWORD offset_ASolarTeamInfotTeam = 0x0C60; // SolarTeamInfo* Team
DWORD offset_ASolarTeamInfotTeamID = 0x0250; // SolarTeamInfo->TeamID
DWORD offset_KillNum = 0x0838; // int KillNum
DWORD offset_bot = 0x0242; // PlayerState bool bIsABot
DWORD offset_ItemData = 0x0280; // Class: SolarItemActor : SolarItemData ItemData
DWORD offset_ItemID = 0x0c; //int
DWORD offset_ItemName = 0x18; //FString
DWORD ItemType = 0x4c; //SolarItemData->ItemType
DWORD offset_ItemQuality = 0x50; //int
	};

#define GameOffset BloodHunt::Offsets::Get()
}
#endif  !BLOODHUNT_H
