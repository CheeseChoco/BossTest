// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "BossTestCharacter.h"

#ifdef BOSSTEST_BossTestCharacter_generated_h
#error "BossTestCharacter.generated.h already included, missing '#pragma once' in BossTestCharacter.h"
#endif
#define BOSSTEST_BossTestCharacter_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class ABossTestCharacter *******************************************************
#define FID_Users_allja_Documents_GitHub_BossTest_BossTest_BossTest_Source_BossTest_BossTestCharacter_h_24_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execDoJumpEnd); \
	DECLARE_FUNCTION(execDoJumpStart); \
	DECLARE_FUNCTION(execDoLook); \
	DECLARE_FUNCTION(execDoMove);


BOSSTEST_API UClass* Z_Construct_UClass_ABossTestCharacter_NoRegister();

#define FID_Users_allja_Documents_GitHub_BossTest_BossTest_BossTest_Source_BossTest_BossTestCharacter_h_24_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesABossTestCharacter(); \
	friend struct Z_Construct_UClass_ABossTestCharacter_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend BOSSTEST_API UClass* Z_Construct_UClass_ABossTestCharacter_NoRegister(); \
public: \
	DECLARE_CLASS2(ABossTestCharacter, ACharacter, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Config), CASTCLASS_None, TEXT("/Script/BossTest"), Z_Construct_UClass_ABossTestCharacter_NoRegister) \
	DECLARE_SERIALIZER(ABossTestCharacter)


#define FID_Users_allja_Documents_GitHub_BossTest_BossTest_BossTest_Source_BossTest_BossTestCharacter_h_24_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	ABossTestCharacter(ABossTestCharacter&&) = delete; \
	ABossTestCharacter(const ABossTestCharacter&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ABossTestCharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ABossTestCharacter); \
	DEFINE_ABSTRACT_DEFAULT_CONSTRUCTOR_CALL(ABossTestCharacter) \
	NO_API virtual ~ABossTestCharacter();


#define FID_Users_allja_Documents_GitHub_BossTest_BossTest_BossTest_Source_BossTest_BossTestCharacter_h_21_PROLOG
#define FID_Users_allja_Documents_GitHub_BossTest_BossTest_BossTest_Source_BossTest_BossTestCharacter_h_24_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_allja_Documents_GitHub_BossTest_BossTest_BossTest_Source_BossTest_BossTestCharacter_h_24_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_allja_Documents_GitHub_BossTest_BossTest_BossTest_Source_BossTest_BossTestCharacter_h_24_INCLASS_NO_PURE_DECLS \
	FID_Users_allja_Documents_GitHub_BossTest_BossTest_BossTest_Source_BossTest_BossTestCharacter_h_24_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class ABossTestCharacter;

// ********** End Class ABossTestCharacter *********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_allja_Documents_GitHub_BossTest_BossTest_BossTest_Source_BossTest_BossTestCharacter_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
