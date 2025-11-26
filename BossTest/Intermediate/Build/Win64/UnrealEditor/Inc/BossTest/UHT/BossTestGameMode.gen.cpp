// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BossTestGameMode.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeBossTestGameMode() {}

// ********** Begin Cross Module References ********************************************************
BOSSTEST_API UClass* Z_Construct_UClass_ABossTestGameMode();
BOSSTEST_API UClass* Z_Construct_UClass_ABossTestGameMode_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
UPackage* Z_Construct_UPackage__Script_BossTest();
// ********** End Cross Module References **********************************************************

// ********** Begin Class ABossTestGameMode ********************************************************
void ABossTestGameMode::StaticRegisterNativesABossTestGameMode()
{
}
FClassRegistrationInfo Z_Registration_Info_UClass_ABossTestGameMode;
UClass* ABossTestGameMode::GetPrivateStaticClass()
{
	using TClass = ABossTestGameMode;
	if (!Z_Registration_Info_UClass_ABossTestGameMode.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("BossTestGameMode"),
			Z_Registration_Info_UClass_ABossTestGameMode.InnerSingleton,
			StaticRegisterNativesABossTestGameMode,
			sizeof(TClass),
			alignof(TClass),
			TClass::StaticClassFlags,
			TClass::StaticClassCastFlags(),
			TClass::StaticConfigName(),
			(UClass::ClassConstructorType)InternalConstructor<TClass>,
			(UClass::ClassVTableHelperCtorCallerType)InternalVTableHelperCtorCaller<TClass>,
			UOBJECT_CPPCLASS_STATICFUNCTIONS_FORCLASS(TClass),
			&TClass::Super::StaticClass,
			&TClass::WithinClass::StaticClass
		);
	}
	return Z_Registration_Info_UClass_ABossTestGameMode.InnerSingleton;
}
UClass* Z_Construct_UClass_ABossTestGameMode_NoRegister()
{
	return ABossTestGameMode::GetPrivateStaticClass();
}
struct Z_Construct_UClass_ABossTestGameMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n *  Simple GameMode for a third person game\n */" },
#endif
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "BossTestGameMode.h" },
		{ "ModuleRelativePath", "BossTestGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Simple GameMode for a third person game" },
#endif
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ABossTestGameMode>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_ABossTestGameMode_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AGameModeBase,
	(UObject* (*)())Z_Construct_UPackage__Script_BossTest,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ABossTestGameMode_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ABossTestGameMode_Statics::ClassParams = {
	&ABossTestGameMode::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x008003ADu,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ABossTestGameMode_Statics::Class_MetaDataParams), Z_Construct_UClass_ABossTestGameMode_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ABossTestGameMode()
{
	if (!Z_Registration_Info_UClass_ABossTestGameMode.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ABossTestGameMode.OuterSingleton, Z_Construct_UClass_ABossTestGameMode_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ABossTestGameMode.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ABossTestGameMode);
ABossTestGameMode::~ABossTestGameMode() {}
// ********** End Class ABossTestGameMode **********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Users_allja_Documents_GitHub_BossTest_BossTest_BossTest_Source_BossTest_BossTestGameMode_h__Script_BossTest_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ABossTestGameMode, ABossTestGameMode::StaticClass, TEXT("ABossTestGameMode"), &Z_Registration_Info_UClass_ABossTestGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ABossTestGameMode), 2429024548U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_allja_Documents_GitHub_BossTest_BossTest_BossTest_Source_BossTest_BossTestGameMode_h__Script_BossTest_1432290904(TEXT("/Script/BossTest"),
	Z_CompiledInDeferFile_FID_Users_allja_Documents_GitHub_BossTest_BossTest_BossTest_Source_BossTest_BossTestGameMode_h__Script_BossTest_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_allja_Documents_GitHub_BossTest_BossTest_BossTest_Source_BossTest_BossTestGameMode_h__Script_BossTest_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
