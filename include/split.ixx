module;

#include <vector>
#include <string>
#include <stdexcept>

export module Fibo.Split;

import Fibo.Concept;

namespace fibo
{
	export template<class S, class F> requires(fibo::Stringable<S>&& std::predicate<F, typename fibo::tstring_t<S>::value_type>)
		[[nodiscard]] auto split(const S& str, F&& pre, size_t maxElement = 0)
	{
		// Valid nullptr for s1 and s2
		if constexpr (std::is_pointer_v<S>) {
			if (nullptr == str) {
				throw std::invalid_argument("Invalid parameters");
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
}