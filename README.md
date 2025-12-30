
# 😎 Composite Lens Flare Plugin
A Composite Lens flare plugin based on froyok's Implementation made for binary versions of Unreal Engine. 
Written in C++ and HLSL this lens plugin uses Unreal's `FSceneViewExtension` to hook into the post processing pass of Unreal Engine.  
<div align="center">
  <img src="docs/header_img.jpg" alt="AppImage01" />
</div>

## 📦 Features
- Separate Lens flare layer, can be used side by side with Unreal's default lens flare system.  
- Component based integration with post process volumes.
- Preset support.
- Tweakable blur steps general and threshold pass.
- toggleable Ghosts, Halo and Glare.
- Starburst texture support.
- Separate lens dirt texture support.

## How to Use
To use custom lens flare simply enable the plugin in your project and drop in `Composite Lens Post Process Volume` from Place actors tab, if your level already has default unreal post process volumes you can attach `Lens Flare Component` to your already existing post process volume actors.
### 🧊 New Post Process Volume
<div align="center">
  <img src="docs/place_actor_img.jpg" alt="AppImage01" />
</div>

### ⚙️ Post Process Volume For Existing Actors
<div align="center">
  <img src="docs/add_comp_img.jpg" alt="AppImage01" />
</div>

## ⛰️ Images
Preset 2 For Dusk and low light scenes.
<div align="center">
  <img src="docs/dusk_img.jpg" alt="AppImage01" />
</div>

High Glare for night scenes.
<div align="center">
  <img src="docs/night_img.jpg" alt="AppImage01" />
</div>

Emissives also supported due to image space nature of this system.
<div align="center">
  <img src="docs/emissive_img.jpg" alt="AppImage01" />
</div>
