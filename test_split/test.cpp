#include "pch.h"
#include "split.hpp"

import Fibo.Split;

//TEST(TestCaseName, TestName) 
//{
	//auto vec = fibo::split("a b c ", [](auto sep) { return sep == ' '; });
	//EXPECT_EQ(1, 1);
	//EXPECT_TRUE(true);
//}

TEST(TestSplit, Split_error)
{
	try {
		std::vector<std::string> vec;
		hpx::string_util::split(vec,
			"-",
			[](auto sep) {return sep == '-'; },
			hpx::string_util::token_compress_mode::off);
		EXPECT_EQ(vec.size(), 2);
	}
	catch (...) {
		EXPECT_TRUE(false);
	}
}