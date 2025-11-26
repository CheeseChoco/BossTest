// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBossTest_init() {}
	BOSSTEST_API UFunction* Z_Construct_UDelegateFunction_BossTest_OnEnemyDied__DelegateSignature();
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_BossTest;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_BossTest()
	{
		if (!Z_Registration_Info_UPackage__Script_BossTest.OuterSingleton)
		{
			static UObject* (*const SingletonFuncArray[])() = {
				(UObject* (*)())Z_Construct_UDelegateFunction_BossTest_OnEnemyDied__DelegateSignature,
			};
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/BossTest",
				SingletonFuncArray,
				UE_ARRAY_COUNT(SingletonFuncArray),
				PKG_CompiledIn | 0x00000000,
				0xE2FF0028,
				0xE9CB87B9,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_BossTest.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_BossTest.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_BossTest(Z_Construct_UPackage__Script_BossTest, TEXT("/Script/BossTest"), Z_Registration_Info_UPackage__Script_BossTest, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0xE2FF0028, 0xE9CB87B9));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
