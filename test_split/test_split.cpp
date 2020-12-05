#include "pch.h"

import Saigon.Split;

TEST(split, a_char_array_normal) 
{
	auto vec = saigon::split("aaa-bb-c", [](auto ch) { return ch == '-'; });
	EXPECT_EQ(vec.size(), 3);
}

TEST(split, a_char_array_end)
{
	auto vec = saigon::split("aaa-bb-c-", [](auto ch) { return ch == '-'; });
	EXPECT_EQ(vec.size(), 3);
}

TEST(split, a_char_array_begin)
{
	auto vec = saigon::split("-aaa-bb-c", [](auto ch) { return ch == '-'; });
	EXPECT_EQ(vec.size(), 3);
}

TEST(split, a_char_array_begin_end)
{
	auto vec = saigon::split("-aaa-bb-c-", [](auto ch) { return ch == '-'; });
	EXPECT_EQ(vec.size(), 3);
}

TEST(split, a_char_array_multi)
{
	auto vec = saigon::split("a--b-c", [](auto ch) { return ch == '-'; });
	EXPECT_EQ(vec.size(), 3);
}

TEST(split, a_char_array_without_sep)
{
	auto vec = saigon::split("a", [](auto ch) { return ch == '-'; });
	EXPECT_EQ(vec.size(), 1);
}

TEST(split, a_char_array_empty)
{
	auto vec = saigon::split("", [](auto ch) { return ch == '-'; });
	EXPECT_EQ(vec.size(), 0);
}

TEST(split, a_char_array_sep_only)
{
	auto vec = saigon::split("-", [](auto ch) { return ch == '-'; });
	EXPECT_EQ(vec.size(), 0);
}

TEST(split, a_wide_char_array_normal)
{
	auto vec = saigon::split(L"aaa-bb-c", [](auto ch) { return ch == L'-'; });
	EXPECT_EQ(vec.size(), 3);
}

TEST(split, a_string_normal)
{
	std::string s{ "aaa-bb-c" };
	auto vec = saigon::split(s, [](auto ch) { return ch == '-'; });
	EXPECT_EQ(vec.size(), 3);
}

TEST(split, a_wstring_normal)
{
	std::wstring s{ L"aaa-bb-c" };
	auto vec = saigon::split(s, [](auto ch) { return ch == L'-'; });
	EXPECT_EQ(vec.size(), 3);
}

TEST(split, a_const_char_pointer_normal)
{
	char const* s = "aaa-bb-c";
	auto vec = saigon::split(s, [](auto ch) { return ch == '-'; });
	EXPECT_EQ(vec.size(), 3);
}

TEST(split, a_const_wchar_pointer_normal)
{
	wchar_t const* s = L"aaa-bb-c";
	auto vec = saigon::split(s, [](auto ch) { return ch == L'-'; });
	EXPECT_EQ(vec.size(), 3);
}

TEST(split, a_char_is_null_pointer)
{
	try {
		wchar_t const* s = nullptr;
		auto vec = saigon::split(s, [](auto ch) { return ch == L'-'; });
		EXPECT_FALSE(true);
	}
	catch (std::exception const&) {
		//std::cout << e.what();
		EXPECT_FALSE(false);
	}
}

TEST(split, a_char8_t_normal)
{
	char8_t const* s = u8"aaa-bb-c";
	auto vec = saigon::split(s, [](auto ch) { return ch == u8'-'; });
	EXPECT_EQ(vec.size(), 3);
}

TEST(split, a_char16_t_normal)
{
	char16_t const* s = u"aaa-bb-c";
	auto vec = saigon::split(s, [](auto ch) { return ch == u'-'; });
	EXPECT_EQ(vec.size(), 3);
}


TEST(split, a_char32_t_normal)
{
	char32_t const* s = U"aaa-bb-c";
	auto vec = saigon::split(s, [](auto ch) { return ch == U'-'; });
	EXPECT_EQ(vec.size(), 3);
}

TEST(split, a_u8string_normal)
{
	std::u8string s{ u8"aaa-bb-c" };
	auto vec = saigon::split(s, [](auto ch) { return ch == u8'-'; });
	EXPECT_EQ(vec.size(), 3);
}

TEST(split, a_u16string_normal)
{
	std::u16string s{ u"aaa-bb-c" };
	auto vec = saigon::split(s, [](auto ch) { return ch == u'-'; });
	EXPECT_EQ(vec.size(), 3);
}

TEST(split, a_u32string_normal)
{
	std::u32string s{ U"aaa-bb-c" };
	auto vec = saigon::split(s, [](auto ch) { return ch == U'-'; });
	EXPECT_EQ(vec.size(), 3);
}

TEST(split, a_string_view_normal)
{
	std::string_view s{ "aaa-bb-c" };
	auto vec = saigon::split(s, [](auto ch) { return ch == '-'; });
	EXPECT_EQ(vec.size(), 3);
}

TEST(split, a_wstring_view_normal)
{
	std::wstring_view s{ L"aaa-bb-c" };
	auto vec = saigon::split(s, [](auto ch) { return ch == L'-'; });
	EXPECT_EQ(vec.size(), 3);
}

TEST(split, a_u8string_view_normal)
{
	std::u8string_view s{ u8"aaa-bb-c" };
	auto vec = saigon::split(s, [](auto ch) { return ch == u8'-'; });
	EXPECT_EQ(vec.size(), 3);
}

TEST(split, a_u16string_view_normal)
{
	std::u16string_view s{ u"aaa-bb-c" };
	auto vec = saigon::split(s, [](auto ch) { return ch == u'-'; });
	EXPECT_EQ(vec.size(), 3);
}

TEST(split, a_u32string_view_normal)
{
	std::u32string_view s{ U"aaa-bb-c" };
	auto vec = saigon::split(s, [](auto ch) { return ch == U'-'; });
	EXPECT_EQ(vec.size(), 3);
}