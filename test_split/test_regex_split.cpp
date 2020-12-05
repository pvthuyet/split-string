#include "pch.h"

import Fibo.Split;

TEST(split_regex, a_char_array_normal)
{
	auto vec = fibo::split_regex("aaa-bb+c", "\\-|\\+");
	EXPECT_EQ(vec.size(), 3);
}

TEST(split_regex, a_const_char_pointer_normal)
{
	char const* s = "aaa-bb+c";
	char const* tk = "\\-|\\+";
	auto vec = fibo::split_regex(s, tk);
	EXPECT_EQ(vec.size(), 3);
}

TEST(split_regex, a_wchar_array_normal)
{
	auto vec = fibo::split_regex(L"aaa-bb+c", L"\\-|\\+");
	EXPECT_EQ(vec.size(), 3);
}

TEST(split_regex, a_const_wchar_pointer_normal)
{
	wchar_t const* s = L"aaa-bb+c";
	wchar_t const* tk = L"\\-|\\+";
	auto vec = fibo::split_regex(s, tk);
	EXPECT_EQ(vec.size(), 3);
}

TEST(split_regex, a_string_normal)
{
	std::string s = "aaa-bb+c";
	std::string tk = "\\-|\\+";
	auto vec = fibo::split_regex(s, tk);
	EXPECT_EQ(vec.size(), 3);
}

TEST(split_regex, a_empty_string)
{
	auto vec = fibo::split_regex("", "\\-|\\+");
	EXPECT_EQ(vec.size(), 0);
}

TEST(split_regex, a_separtor_only)
{
	auto vec = fibo::split_regex("-+-+++--", "\\-|\\+");
	EXPECT_EQ(vec.size(), 0);
}