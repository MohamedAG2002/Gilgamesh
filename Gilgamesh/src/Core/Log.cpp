#include "Gilgamesh/Core/Log.hpp"
#include "Gilgamesh/GilgPCH.hpp"

namespace gilg { // beginning of gilg
 
void LogAssertion(const String& expr, const String& msg, const String& fileName, U16 line)
{
  std::cout << "[GILG ASSERTION FAILED]: \'" << expr << "\'\n";
  std::cout << "[MESSAGE]: " << msg << '\n';
  std::cout << "[FILE]: " << fileName << '\n';
  std::cout << "[LINE]: " << line << '\n';
}

} // end of gilg
