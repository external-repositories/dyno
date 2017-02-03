// Copyright Louis Dionne 2017
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

#include <te/concept.hpp>
#include <te/concept_map.hpp>
using namespace te::literals;


struct Fooable : decltype(te::requires(
  "foo"_s = te::function<void (te::T&)>
)) { };

int main() {
  // No concept map was defined for `int`, and no default concept map is provided.
  auto const& map = te::concept_map<Fooable, int>;
}
