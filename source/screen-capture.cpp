#include <string>

#include "screen-capture/screen-capture.hpp"

exported_class::exported_class()
    : m_name {"screen-capture"}
{
}

auto exported_class::name() const -> char const*
{
  return m_name.c_str();
}
