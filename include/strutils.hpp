
#include <iterator>
#include <regex>

namespace strutil {

template <typename E, typename TR = std::char_traits<E>,
          typename AL = std::allocator<E>,
          typename _str_type = std::basic_string<E, TR, AL>>
std::vector<_str_type> split(const std::basic_string<E, TR, AL>& in,
                             const std::basic_string<E, TR, AL>& delim) {
  std::basic_regex<E> re{delim};
  return std::vector<_str_type>{
      std::regex_token_iterator<typename _str_type::const_iterator>(
          in.begin(), in.end(), re, -1),
      std::regex_token_iterator<typename _str_type::const_iterator>()};
}

std::vector<std::string> split(const std::string& in,
                               const std::string& delim = "\\s+") {
  std::regex re{delim};
  return std::vector<std::string>{
      std::sregex_token_iterator(in.begin(), in.end(), re, -1),
      std::sregex_token_iterator()};
}

// std::wstring版本
std::vector<std::wstring> split(const std::wstring& in,
                                const std::wstring& delim = L"\\s+") {
  std::wregex re{delim};
  return std::vector<std::wstring>{
      std::wsregex_token_iterator(in.begin(), in.end(), re, -1),
      std::wsregex_token_iterator()};
}
// c string版本
std::vector<std::string> split(const char* in, const char* delim = "\\s+") {
  std::regex re{delim};
  return std::vector<std::string>{
      std::cregex_token_iterator(in, in + strlen(in), re, -1),
      std::cregex_token_iterator()};
}
// 支持wchar_t宽字符集的版本
std::vector<std::wstring> split(const wchar_t* in,
                                const wchar_t* delim = L"\\s+") {
  std::wregex re{delim};
  return std::vector<std::wstring>{
      std::wcregex_token_iterator(in, in + wcslen(in), re, -1),
      std::wcregex_token_iterator()};
}

/**
 * @brief join a string vector with specified connect string
 * @param vec: vector of string to be joined
 * @param w: connect string
 *
 */
inline std::wstring join(std::vector<std::wstring> vec, std::wstring w) {
  std::wstring str{};
  if (vec.size() >= 1) str += vec[0];
  for (auto i = 1; i < vec.size(); i++) {
    str += w + vec[i];
  }
  return str;
}

inline std::wstring join(std::vector<std::wstring>::iterator _start,
                         std::vector<std::wstring>::iterator _end,
                         std::wstring w) {
  std::wstring str{};
  str += *_start;
  _start++;
  while (_start != _end) {
    str += w + *_start;
    _start++;
  }
  return str;
}

inline std::string join(std::vector<std::string>::iterator _start,
                        std::vector<std::string>::iterator _end,
                        std::string w) {
  std::string str{};
  str += *_start;
  _start++;
  while (_start != _end) {
    str += w + *_start;
    _start++;
  }
  return str;
}

/**
 * @brief trim the space of a string
 * @param text : string to be trimed
 *
 */
inline std::wstring& trim(std::wstring& text) {
  if (!text.empty()) {
    text.erase(0, text.find_first_not_of(L" \t\n\r\v\f"));
    text.erase(text.find_last_not_of(L" \t\n\r\v\f") + 1);
  }
  return text;
}
inline std::string& trim(std::string& text) {
  if (!text.empty()) {
    text.erase(0, text.find_first_not_of(" \t\n\r\v\f"));
    text.erase(text.find_last_not_of(" \t\n\r\v\f") + 1);
  }
  return text;
}

}  // namespace strutil