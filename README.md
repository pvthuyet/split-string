# split-string
### Using C++20 features:
* [concept](https://en.cppreference.com/w/cpp/header/concepts)
### [source](include/split.xx)
Work well with data type:  
* char*, wchar_t*, char8_t*, char16_t*, char32_t*  
* std::string, std::wstring, std::u8string, std::u16string, std::u32string  
* std::string_view, std::wstring_view, std::u8string_view, std::u16string_view, std::u32string_view  
```
import Fibo.Split;
int main() {
  auto vec = fibo::split("aaa-bb-c", [](auto ch) { return ch == '-'; });
}
```
