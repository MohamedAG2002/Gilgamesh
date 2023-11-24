#pragma once

#include "Gilgamesh/Components/TextType.hpp"
#include "Gilgamesh/Graphics/Renderer2D.hpp"
#include "Gilgamesh/GilgPCH.hpp"

namespace gilg { // beginning gilg

struct AssetManager
{
  std::unordered_map<U64, void*> textures;
  std::unordered_map<TextType, void*> fonts;
  std::unordered_map<U64, void*> music;
  std::unordered_map<U64, void*> sounds;
};

U64 PushBackTexture(AssetManager& am, Renderer2D& renderer, const std::string& path);
void PushBackFont(AssetManager& am, const std::string&& path);
U64 PushBackMusic(AssetManager& am, const std::string&& path);
U64 PushBackSound(AssetManager& am, const std::string&& path);

void* GetTexture(AssetManager& am, U64 assetID);
void* GetFont(AssetManager& am, TextType type);
void* GetMusic(AssetManager& am, U64 assetID);
void* GetSound(AssetManager& am, U64 assetID);

void UnloadAssets(AssetManager& am); 

} // end gilg
