// // Copyright (C) 2025 R.Haris Nauman. All Rights Reserved.


#include "CompositeLensPostProcessVolume.h"

ACompositeLensPostProcessVolume::ACompositeLensPostProcessVolume()
{
	LensFlareComponent = CreateDefaultSubobject<UCompositeLensFlareComponent>("LensFlareComponent");
}
