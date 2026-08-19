#include "conan-library-a/sum.hpp"

#include <stdexcept>

namespace conan_library_a {

nlohmann::json sum(const nlohmann::json& a, const nlohmann::json& b) {
    if (a.is_number_integer() && b.is_number_integer()) {
        return a.get<std::int64_t>() + b.get<std::int64_t>();
    }
    if ((a.is_number_float() || a.is_number_integer()) &&
        (b.is_number_float() || b.is_number_integer())) {
        return a.get<double>() + b.get<double>();
    }
    throw std::invalid_argument("sum requires numeric JSON values");
}

} // namespace conan_library_a
