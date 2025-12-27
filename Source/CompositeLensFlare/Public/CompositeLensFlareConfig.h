// // Copyright (C) 2025 R.Haris Nauman. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "CompositeLensFlareConfig.generated.h"

/**
 * Ghost setting struct
 */
USTRUCT(BlueprintType)
struct FLensFlareGhostSettings
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Exedre")
	FLinearColor Color = FLinearColor::White;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Exedre")
	float Scale = 1.0f;
};

/**
 * 
 */
UCLASS()
class COMPOSITELENSFLARE_API UCompositeLensFlareConfig : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="General", meta=(UIMin = "0.0", UIMax = "1.0"))
	float Intensity = 0.1f;

	UPROPERTY(EditAnywhere, Category="General", meta=(ClampMin="0", ClampMax="4", UIMin = "0", UIMax = "4"))
	int FlareBlurSteps = 1;

	UPROPERTY(EditAnywhere, Category="General")
	FLinearColor Tint = FLinearColor(1.0f, 0.85f, 0.7f, 1.0f);

	UPROPERTY(EditAnywhere, Category="General")
	TObjectPtr<UTexture2D> Gradient = nullptr;
	

	UPROPERTY(EditAnywhere, Category="Threshold", meta=(UIMin = "0.0", UIMax = "10.0"))
	float ThresholdLevel = 1.0f;

	UPROPERTY(EditAnywhere, Category="Threshold", meta=(UIMin = "0.01", UIMax = "10.0"))
	float ThresholdRange = 1.0f;

	UPROPERTY(EditAnywhere, Category="Threshold", meta=(ClampMin="0", ClampMax="4", UIMin = "0", UIMax = "4"))
	int ThresholdBlurSteps = 1;
	
	UPROPERTY(EditAnywhere, Category="Ghosts")
	bool bEnableGhosts = true;
	
	UPROPERTY(EditAnywhere, Category="Ghosts", meta=(UIMin = "0.0", UIMax = "1.0", EditCondition="bEnableGhosts"))
	float GhostIntensity = 1.0f;

	UPROPERTY(EditAnywhere, Category="Ghosts", meta=(UIMin = "0.0", UIMax = "1.0", EditCondition="bEnableGhosts"))
	float GhostChromaShift = 0.015f;

	UPROPERTY(EditAnywhere, Category="Ghosts")
	TObjectPtr<UTexture2D> LensDirt = nullptr;

	UPROPERTY(EditAnywhere, Category="Ghosts")
	TObjectPtr<UTexture2D> StarbrustTexture = nullptr;
	
	UPROPERTY(EditAnywhere, Category="Ghosts", meta=(EditCondition="bEnableGhosts"))
	FLensFlareGhostSettings Ghost1 = {FLinearColor(1.0f, 0.8f, 0.4f, 1.0f), -1.5};

	UPROPERTY(EditAnywhere, Category="Ghosts", meta=(EditCondition="bEnableGhosts"))
	FLensFlareGhostSettings Ghost2 = {FLinearColor(1.0f, 1.0f, 0.6f, 1.0f), 2.5};

	UPROPERTY(EditAnywhere, Category="Ghosts", meta=(EditCondition="bEnableGhosts"))
	FLensFlareGhostSettings Ghost3 = {FLinearColor(0.8f, 0.8f, 1.0f, 1.0f), -5.0};

	UPROPERTY(EditAnywhere, Category="Ghosts", meta=(EditCondition="bEnableGhosts"))
	FLensFlareGhostSettings Ghost4 = {FLinearColor(0.5f, 1.0f, 0.4f, 1.0f), 10.0};

	UPROPERTY(EditAnywhere, Category="Ghosts", meta=(EditCondition="bEnableGhosts"))
	FLensFlareGhostSettings Ghost5 = {FLinearColor(0.5f, 0.8f, 1.0f, 1.0f), 0.7};

	UPROPERTY(EditAnywhere, Category="Ghosts", meta=(EditCondition="bEnableGhosts"))
	FLensFlareGhostSettings Ghost6 = {FLinearColor(0.9f, 1.0f, 0.8f, 1.0f), -0.4};

	UPROPERTY(EditAnywhere, Category="Ghosts", meta=(EditCondition="bEnableGhosts"))
	FLensFlareGhostSettings Ghost7 = {FLinearColor(1.0f, 0.8f, 0.4f, 1.0f), -0.2};

	UPROPERTY(EditAnywhere, Category="Ghosts", meta=(EditCondition="bEnableGhosts"))
	FLensFlareGhostSettings Ghost8 = {FLinearColor(0.9f, 0.7f, 0.7f, 1.0f), -0.1};

	UPROPERTY(EditAnywhere, Category="Halo")
	bool bEnableHalo = true;
	
	UPROPERTY(EditAnywhere, Category="Halo", meta=(UIMin = "0.0", UIMax = "1.0", EditCondition="bEnableHalo"))
	float HaloIntensity = 1.0f;

	UPROPERTY(EditAnywhere, Category="Halo", meta=(UIMin = "0.0", UIMax = "1.0", EditCondition="bEnableHalo"))
	float HaloWidth = 0.6f;

	UPROPERTY(EditAnywhere, Category="Halo", meta=(UIMin = "0.0", UIMax = "1.0", EditCondition="bEnableHalo"))
	float HaloMask = 0.5f;

	UPROPERTY(EditAnywhere, Category="Halo", meta=(UIMin = "0.0", UIMax = "1.0", EditCondition="bEnableHalo"))
	float HaloCompression = 0.65f;

	UPROPERTY(EditAnywhere, Category="Halo", meta=(UIMin = "0.0", UIMax = "1.0", EditCondition="bEnableHalo"))
	float HaloChromaShift = 0.015f;


	UPROPERTY(EditAnywhere, Category="Glare", meta=(UIMin = "0", UIMax = "10"))
	float GlareIntensity = 0.02f;

	UPROPERTY(EditAnywhere, Category="Glare", meta=(UIMin = "0.01", UIMax = "200"))
	float GlareDivider = 60.0f;

	UPROPERTY(EditAnywhere, Category="Glare", meta=(UIMin = "0.0", UIMax = "10.0"))
	FVector GlareScale = FVector(1.0f, 1.0f, 1.0f);

	UPROPERTY(EditAnywhere, Category="Glare", meta=(UIMin = "0.0", UIMax = "10.0"))
	FVector GlareAngles = FVector(1.047197f, 1.570796f, 2.617994f);

	UPROPERTY(EditAnywhere, Category="Glare")
	FLinearColor GlareTint = FLinearColor(1.0f, 1.0f, 1.0f, 1.0f);

	UPROPERTY(EditAnywhere, Category="Glare")
	TObjectPtr<UTexture2D> GlareLineMask = nullptr;
};
