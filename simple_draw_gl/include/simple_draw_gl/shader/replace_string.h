#pragma once
#include <string>
#include <vector>

namespace simple_draw_gl {
namespace shader {

// https://stackoverflow.com/a/2548212
std::string& replace_string_inplace(std::string& str, const std::string& remove, const std::string& insert);
std::string& replace_strings_inplace(std::string& str, const std::vector<std::string>& remove, const std::vector<std::string>& insert);

} // namespace shader
} // namespace simple_draw_gl
