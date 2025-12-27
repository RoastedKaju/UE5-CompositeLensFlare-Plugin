// // Copyright (C) 2025 R.Haris Nauman. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/PostProcessVolume.h"
#include "CompositeLensFlareComponent.h"
#include "CompositeLensPostProcessVolume.generated.h"

UCLASS()
class COMPOSITELENSFLARE_API ACompositeLensPostProcessVolume : public APostProcessVolume
{
	GENERATED_BODY()

public:
	ACompositeLensPostProcessVolume();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadONLY, Category = "Lens Flare")
	TObjectPtr<UCompositeLensFlareComponent> LensFlareComponent;
};
