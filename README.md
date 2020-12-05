# split-string
### Using C++20 features:
* [concept](https://en.cppreference.com/w/cpp/header/concepts)
### [source](/include/split.ixx)
Work well with data type:  
* char*, wchar_t*, char8_t*, char16_t*, char32_t*  
* std::string, std::wstring, std::u8string, std::u16string, std::u32string  
* std::string_view, std::wstring_view, std::u8string_view, std::u16string_view, std::u32string_view  
  
### Example  
```
#include <cassert>
#include <vector>
import Fibo.Split;
int main() {
  auto vec1 = fibo::split("aaa-bb-c", [](auto ch) { return ch == '-'; });
  assert(vec1.size() == 3);
  
  auto vec2 = fibo::split_regex("aaa-bb+c", "\\-|\\+");
  assert(vec2.size() == 3);
}
```
