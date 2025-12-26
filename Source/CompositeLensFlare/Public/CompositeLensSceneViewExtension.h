// Copyright (C) 2025 R.Haris Nauman. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScreenPass.h"
#include "SceneViewExtension.h"
#include "CompositeLensFlareConfig.h"

DECLARE_LOG_CATEGORY_EXTERN(LensSceneViewExtensionLog, Display, All);

// struct FLensFlareInputs;

/**
 * 
 */
class COMPOSITELENSFLARE_API FCompositeLensSceneViewExtension final : public FSceneViewExtensionBase
{
public:
	FCompositeLensSceneViewExtension(const FAutoRegister& AutoRegister);
	virtual ~FCompositeLensSceneViewExtension() override;

	// FSceneViewExtensionBase Interface
	virtual bool IsActiveThisFrame_Internal(const FSceneViewExtensionContext& Context) const override;
	virtual void SetupViewFamily(FSceneViewFamily& InViewFamily) override;
	virtual void SetupView(FSceneViewFamily& InViewFamily, FSceneView& InView) override;
	virtual void BeginRenderViewFamily(FSceneViewFamily& InViewFamily) override;
	virtual void SubscribeToPostProcessingPass(EPostProcessingPass Pass, const FSceneView& InView, FPostProcessingPassDelegateArray& InOutPassCallbacks, bool bIsPassEnabled) override;
	// --

	void Initialize();

private:
	FScreenPassTexture AddLensFlareDOFPass_RenderThread(FRDGBuilder& GraphBuilder, const FSceneView& View, const FPostProcessMaterialInputs& InOutInputs);
	void RenderLensFlare(FRDGBuilder& GraphBuilder, const FViewInfo& View, FScreenPassTexture BloomTexture, FScreenPassTextureSlice HalfSceneColor, FScreenPassTexture& Outputs);
	FRDGTextureRef RenderThreshold(FRDGBuilder& GraphBuilder, FRDGTextureRef InputTexture, FIntRect& InputRect, const FViewInfo& View);
	FRDGTextureRef RenderFlare(FRDGBuilder& GraphBuilder, FRDGTextureRef InputTexture, FIntRect& InputRect, const FViewInfo& View);
	FRDGTextureRef RenderGlare(FRDGBuilder& GraphBuilder, FRDGTextureRef InputTexture, FIntRect& InputRect, const FViewInfo& View);
	FRDGTextureRef RenderBlur(FRDGBuilder& GraphBuilder, FRDGTextureRef InputTexture, const FViewInfo& View, const FIntRect& Viewport, int BlurSteps);

	TStrongObjectPtr<UCompositeLensFlareConfig> Config;
	TStrongObjectPtr<UCompositeLensFlareConfig> DefaultConfig;
	
	// Cached blending and sampling states
	// which are re-used across render passes
	FRHIBlendState* ClearBlendState = nullptr;
	FRHIBlendState* AdditiveBlendState = nullptr;

	FRHISamplerState* BilinearClampSampler = nullptr;
	FRHISamplerState* BilinearBorderSampler = nullptr;
	FRHISamplerState* BilinearRepeatSampler = nullptr;
	FRHISamplerState* NearestRepeatSampler = nullptr;
};
