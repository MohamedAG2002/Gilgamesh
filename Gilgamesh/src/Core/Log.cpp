#include "Gilgamesh/Core/Log.hpp"
#include "Gilgamesh/GilgPCH.hpp"

namespace gilg { // beginning of gilg
 
bool InitLogger()
{
  // @TODO
  return true;
}

void UnloadLogger()
{
  // @TODO
}

void LogAssertion(const String& expr, const String& msg, const String& fileName, U16 line)
{
  std::cout << "[GILG ASSERTION FAILED]: \'" << expr << "\'\n";
  std::cout << "[MESSAGE]: " << msg << '\n';
  std::cout << "[FILE]: " << fileName << '\n';
  std::cout << "[LINE]: " << line << '\n';
}

void LogInfo(LogLevel level, const char* msg, ...)
{
  std::string levels[] = {"NONE", "TRACE", "DEBUG", "INFO", "WARNING", "ERROR", "FATAL"};
  int index = (int)level;

  // @TODO: spdlog?
  std::cerr << "[" << levels[index] << "]: " << msg << '\n';
}

} // end of gilg
