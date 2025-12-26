// // Copyright (C) 2025 R.Haris Nauman. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CompositeLensFlareComponent.generated.h"

// Forward declaration
class UCompositeLensFlareConfig;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent, DisplayName = "Lens Flare Component"))
class COMPOSITELENSFLARE_API UCompositeLensFlareComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Ctor
	UCompositeLensFlareComponent();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Composite Lens Flare")
	TObjectPtr<UCompositeLensFlareConfig> CompositeLensFlareConfig;
};
