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

		auto substr = [](auto const& s, auto const& first, auto const& last) {
			auto const pos = std::distance(std::cbegin(s), first);
			auto const count = std::distance(first, last);
			return s.substr(pos, count);
		};

		auto itBeg = std::cbegin(sv);
		auto itEnd = std::cend(sv);

		auto itNex = itBeg;
		do {
			auto found = std::find_if(itNex, itEnd, pre);
			auto const pos = std::distance(itBeg, itNex);
			auto const count = std::distance(itNex, found);

			if (count > 1) {
				result.emplace_back(sv.substr(pos, count));
			}
			if (found != itEnd) {
				itNex = found + 1;
			}

		} while (itEnd != std::cend(sv));

		return result;
	}
}