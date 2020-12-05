module;

#include <vector>
#include <string>
#include <stdexcept>
#include <iterator>
#include <algorithm>

export module Saigon.Split;

import Saigon.Concepts;

namespace saigon
{
	export template<class S, class F> requires(saigon::Stringable<S>&& std::predicate<F, typename saigon::tstring_t<S>::value_type>)
		[[nodiscard]] auto split(const S& str, F&& pre, size_t maxElement = 0)
	{
		// Valid nullptr for s1 and s2
		if constexpr (std::is_pointer_v<S>) {
			if (nullptr == str) {
				throw std::invalid_argument("The input string is nullptr.");
			}
		}

		using TString = tstring_t<S>;
		using TStringView = tstring_view_t<S>;
		TStringView sv{ str };

		std::vector<TString> result;
		if (maxElement > 0) {
			result.reserve(maxElement);
		}

		auto substr = [&result](auto const& s, auto const& first, auto const& last) {
			auto const pos = std::distance(std::cbegin(s), first);
			auto const count = std::distance(first, last);
			if (count > 0) {
				result.emplace_back(s.substr(pos, count));
			}
		};

		auto itNex = std::cbegin(sv);
		for(;;) {
			auto found = std::find_if(itNex, std::cend(sv), pre);
			if (found == std::cend(sv)) {
				break;
			}
			substr(sv, itNex, found);
			itNex = found + 1;
		}
		substr(sv, itNex, std::cend(sv));

		return result;
	}

	export template<typename S1, typename S2> requires saigon::StringablePair<S1, S2>
		[[nodiscard]] auto split_regex(const S1& str, const S2& token, size_t maxElement = 0)
	{
		// Valid nullptr for s1 and s2
		if constexpr (std::is_pointer_v<S1>) {
			if (nullptr == str) {
				throw std::invalid_argument("The input string is nullptr.");
			}
		}

		if constexpr (std::is_pointer_v<S2>) {
			if (nullptr == token) {
				throw std::invalid_argument("The input token is nullptr.");
			}
		}

		using TString = tstring_t<S1>;
		using TStringView = tstring_view_t<S1>;
		TStringView sv{ str };
		TStringView tokv{ token };

		std::vector<TString> result;
		if (maxElement > 0) {
			result.reserve(maxElement);
		}

		using TRegex = tregex_t<S1>;
		using TRegexTokenIt = saigon::tregex_token_iterator_t<TStringView>;

		TRegex rex(tokv.data());
		std::copy_if(TRegexTokenIt(std::cbegin(sv), std::cend(sv), rex, -1),
			TRegexTokenIt(),
			std::back_inserter(result),
			[](auto const& it) {
				return std::distance(it.first, it.second) > 0;
			}
		);

		return result;
	}
}