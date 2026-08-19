#pragma once

#include <nlohmann/json.hpp>

namespace conan_library_a {

nlohmann::json sum(const nlohmann::json& a, const nlohmann::json& b);

} // namespace conan_library_a
