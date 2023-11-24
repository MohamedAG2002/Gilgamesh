#include "Gilgamesh/Managers/AssetManager.hpp"
#include "Gilgamesh/Components/TextType.hpp"
#include "Gilgamesh/Graphics/Renderer2D.hpp"
#include "Gilgamesh/GilgPCH.hpp"

namespace gilg { // beginning gilg

U64 PushBackTexture(AssetManager& am, Renderer2D& renderer, const std::string&& path)
{
  U64 id = util::GetRandomNumber<U64>();

  return id;
}

void PushBackFont(AssetManager& am, const std::string&& path)
{
}

U64 PushBackMusic(AssetManager& am, const std::string&& path)
{
  U64 id = util::GetRandomNumber<U64>();

  return id;
}

U64 PushBackSound(AssetManager& am, const std::string&& path)
{
  U64 id = util::GetRandomNumber<U64>();

  return id;
}

void* GetTexture(AssetManager& am, U64 assetID)
{
  return nullptr;
}

void* GetFont(AssetManager& am, TextType type)
{
  return nullptr;
}

void* GetMusic(AssetManager& am, U64 assetID)
{
  return nullptr;
}

void* GetSound(AssetManager& am, U64 assetID)
{
  return nullptr;
}

void UnloadAssets(AssetManager& am)
{
}

} // end gilg
