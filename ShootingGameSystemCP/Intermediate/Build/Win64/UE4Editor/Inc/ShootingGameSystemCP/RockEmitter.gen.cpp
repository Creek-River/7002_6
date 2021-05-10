// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ShootingGameSystemCP/Private/RockEmitter.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRockEmitter() {}
// Cross Module References
	SHOOTINGGAMESYSTEMCP_API UClass* Z_Construct_UClass_ARockEmitter_NoRegister();
	SHOOTINGGAMESYSTEMCP_API UClass* Z_Construct_UClass_ARockEmitter();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_ShootingGameSystemCP();
// End Cross Module References
	void ARockEmitter::StaticRegisterNativesARockEmitter()
	{
	}
	UClass* Z_Construct_UClass_ARockEmitter_NoRegister()
	{
		return ARockEmitter::StaticClass();
	}
	struct Z_Construct_UClass_ARockEmitter_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_delayTime_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_delayTime;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ARockEmitter_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_ShootingGameSystemCP,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ARockEmitter_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "RockEmitter.h" },
		{ "ModuleRelativePath", "Private/RockEmitter.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ARockEmitter_Statics::NewProp_delayTime_MetaData[] = {
		{ "Category", "Emitter Properties" },
		{ "ModuleRelativePath", "Private/RockEmitter.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ARockEmitter_Statics::NewProp_delayTime = { "delayTime", nullptr, (EPropertyFlags)0x0020080000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ARockEmitter, delayTime), METADATA_PARAMS(Z_Construct_UClass_ARockEmitter_Statics::NewProp_delayTime_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ARockEmitter_Statics::NewProp_delayTime_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ARockEmitter_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ARockEmitter_Statics::NewProp_delayTime,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ARockEmitter_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ARockEmitter>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ARockEmitter_Statics::ClassParams = {
		&ARockEmitter::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_ARockEmitter_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_ARockEmitter_Statics::PropPointers),
		0,
		0x008000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ARockEmitter_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ARockEmitter_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ARockEmitter()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ARockEmitter_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ARockEmitter, 83312724);
	template<> SHOOTINGGAMESYSTEMCP_API UClass* StaticClass<ARockEmitter>()
	{
		return ARockEmitter::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ARockEmitter(Z_Construct_UClass_ARockEmitter, &ARockEmitter::StaticClass, TEXT("/Script/ShootingGameSystemCP"), TEXT("ARockEmitter"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ARockEmitter);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
