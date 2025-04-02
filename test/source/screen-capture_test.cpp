#include <string>

#include "screen-capture/screen-capture.hpp"

auto main() -> int
{
  auto const exported = exported_class {};

  return std::string("screen-capture") == exported.name() ? 0 : 1;
}
