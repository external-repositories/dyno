// Copyright Louis Dionne 2017
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef TE_EXPERIMENTAL_VTABLE_HPP
#define TE_EXPERIMENTAL_VTABLE_HPP

#include <te/concept.hpp>

#include <utility>


namespace te {
namespace experimental {

namespace detail {
  // TODO: Make sure we perfectly-forward rvalue reference args in vtable_impl::apply.

  template <typename ...Functions>
  struct vtable_base;

  template <typename GetConceptMap, typename ...Functions>
  struct vtable_impl;

  template <typename GetConceptMap>
  struct make_vtable_impl {
    template <typename ...Functions>
    using apply = vtable_impl<GetConceptMap, Functions...>;
  };

  template <typename Concept, typename GetConceptMap>
  constexpr te::unpack_vtable_layout<Concept, make_vtable_impl<GetConceptMap>::template apply>
    const derived_vtable{};
} // end namespace detail

template <typename Concept>
struct vtable {
  template <typename GetConceptMap>
  constexpr explicit vtable(GetConceptMap)
    : base_{&detail::derived_vtable<Concept, GetConceptMap>}
  { }

  template <typename Name>
  constexpr auto operator[](Name) const {
    return [base = this->base_](auto&& ...args) -> decltype(auto) {
      return base->apply(Name{}, std::forward<decltype(args)>(args)...);
    };
  }

private:
  using Base = te::unpack_vtable_layout<Concept, detail::vtable_base>;
  Base const* base_;
};

/*
What follows is a script to generate the specialization of `vtable_base`
and `vtable_impl`. Run the script as

  awk '/SCRIPTBEGIN/{flag=1;next}/SCRIPTEND/{flag=0}flag' ${thisfile} | erb

SCRIPTBEGIN
<% (0...10).each do |n| %>
template <
  <%= (0...n).map {|i| "typename Name#{i}, typename R#{i}, typename ...Args#{i}" }.join(",\n  ") %>
> struct vtable_base<
  <%= (0...n).map {|i| "std::pair<Name#{i}, R#{i} (*)(Args#{i}...)>" }.join(",\n  ") %>
> {
  <%= (0...n).map {|i| "virtual R#{i} apply(Name#{i}, Args#{i}...) const = 0;" }.join("\n  ") %>
};

template <typename GetConceptMap
  <%= (0...n).map {|i| ", typename Name#{i}, typename R#{i}, typename ...Args#{i}" }.join("\n  ") %>
>
struct vtable_impl<GetConceptMap
  <%= (0...n).map {|i| ", std::pair<Name#{i}, R#{i} (*)(Args#{i}...)>" }.join("\n  ") %>
> final : vtable_base<
  <%= (0...n).map {|i| "std::pair<Name#{i}, R#{i} (*)(Args#{i}...)>" }.join(",\n  ") %>
> {
  <%= (0...n).map {|i|
    "R#{i} apply(Name#{i} name, Args#{i} ...args) const override final" +
    "{ return GetConceptMap{}().erased(name)(args...); }"
  }.join("\n  ") %>
};
<% end %>
SCRIPTEND */

namespace detail {
  ////////////////////////////////////////////////////////////////////////////
  // BEGIN GENERATED CODE
  ////////////////////////////////////////////////////////////////////////////
  template <

  > struct vtable_base<

  > {

  };

  template <typename GetConceptMap

  >
  struct vtable_impl<GetConceptMap

  > final : vtable_base<

  > {

  };

  template <
    typename Name0, typename R0, typename ...Args0
  > struct vtable_base<
    std::pair<Name0, R0 (*)(Args0...)>
  > {
    virtual R0 apply(Name0, Args0...) const = 0;
  };

  template <typename GetConceptMap
    , typename Name0, typename R0, typename ...Args0
  >
  struct vtable_impl<GetConceptMap
    , std::pair<Name0, R0 (*)(Args0...)>
  > final : vtable_base<
    std::pair<Name0, R0 (*)(Args0...)>
  > {
    R0 apply(Name0 name, Args0 ...args) const override final{ return GetConceptMap{}().erased(name)(args...); }
  };

  template <
    typename Name0, typename R0, typename ...Args0,
    typename Name1, typename R1, typename ...Args1
  > struct vtable_base<
    std::pair<Name0, R0 (*)(Args0...)>,
    std::pair<Name1, R1 (*)(Args1...)>
  > {
    virtual R0 apply(Name0, Args0...) const = 0;
    virtual R1 apply(Name1, Args1...) const = 0;
  };

  template <typename GetConceptMap
    , typename Name0, typename R0, typename ...Args0
    , typename Name1, typename R1, typename ...Args1
  >
  struct vtable_impl<GetConceptMap
    , std::pair<Name0, R0 (*)(Args0...)>
    , std::pair<Name1, R1 (*)(Args1...)>
  > final : vtable_base<
    std::pair<Name0, R0 (*)(Args0...)>,
    std::pair<Name1, R1 (*)(Args1...)>
  > {
    R0 apply(Name0 name, Args0 ...args) const override final{ return GetConceptMap{}().erased(name)(args...); }
    R1 apply(Name1 name, Args1 ...args) const override final{ return GetConceptMap{}().erased(name)(args...); }
  };

  template <
    typename Name0, typename R0, typename ...Args0,
    typename Name1, typename R1, typename ...Args1,
    typename Name2, typename R2, typename ...Args2
  > struct vtable_base<
    std::pair<Name0, R0 (*)(Args0...)>,
    std::pair<Name1, R1 (*)(Args1...)>,
    std::pair<Name2, R2 (*)(Args2...)>
  > {
    virtual R0 apply(Name0, Args0...) const = 0;
    virtual R1 apply(Name1, Args1...) const = 0;
    virtual R2 apply(Name2, Args2...) const = 0;
  };

  template <typename GetConceptMap
    , typename Name0, typename R0, typename ...Args0
    , typename Name1, typename R1, typename ...Args1
    , typename Name2, typename R2, typename ...Args2
  >
  struct vtable_impl<GetConceptMap
    , std::pair<Name0, R0 (*)(Args0...)>
    , std::pair<Name1, R1 (*)(Args1...)>
    , std::pair<Name2, R2 (*)(Args2...)>
  > final : vtable_base<
    std::pair<Name0, R0 (*)(Args0...)>,
    std::pair<Name1, R1 (*)(Args1...)>,
    std::pair<Name2, R2 (*)(Args2...)>
  > {
    R0 apply(Name0 name, Args0 ...args) const override final{ return GetConceptMap{}().erased(name)(args...); }
    R1 apply(Name1 name, Args1 ...args) const override final{ return GetConceptMap{}().erased(name)(args...); }
    R2 apply(Name2 name, Args2 ...args) const override final{ return GetConceptMap{}().erased(name)(args...); }
  };

  template <
    typename Name0, typename R0, typename ...Args0,
    typename Name1, typename R1, typename ...Args1,
    typename Name2, typename R2, typename ...Args2,
    typename Name3, typename R3, typename ...Args3
  > struct vtable_base<
    std::pair<Name0, R0 (*)(Args0...)>,
    std::pair<Name1, R1 (*)(Args1...)>,
    std::pair<Name2, R2 (*)(Args2...)>,
    std::pair<Name3, R3 (*)(Args3...)>
  > {
    virtual R0 apply(Name0, Args0...) const = 0;
    virtual R1 apply(Name1, Args1...) const = 0;
    virtual R2 apply(Name2, Args2...) const = 0;
    virtual R3 apply(Name3, Args3...) const = 0;
  };

  template <typename GetConceptMap
    , typename Name0, typename R0, typename ...Args0
    , typename Name1, typename R1, typename ...Args1
    , typename Name2, typename R2, typename ...Args2
    , typename Name3, typename R3, typename ...Args3
  >
  struct vtable_impl<GetConceptMap
    , std::pair<Name0, R0 (*)(Args0...)>
    , std::pair<Name1, R1 (*)(Args1...)>
    , std::pair<Name2, R2 (*)(Args2...)>
    , std::pair<Name3, R3 (*)(Args3...)>
  > final : vtable_base<
    std::pair<Name0, R0 (*)(Args0...)>,
    std::pair<Name1, R1 (*)(Args1...)>,
    std::pair<Name2, R2 (*)(Args2...)>,
    std::pair<Name3, R3 (*)(Args3...)>
  > {
    R0 apply(Name0 name, Args0 ...args) const override final{ return GetConceptMap{}().erased(name)(args...); }
    R1 apply(Name1 name, Args1 ...args) const override final{ return GetConceptMap{}().erased(name)(args...); }
    R2 apply(Name2 name, Args2 ...args) const override final{ return GetConceptMap{}().erased(name)(args...); }
    R3 apply(Name3 name, Args3 ...args) const override final{ return GetConceptMap{}().erased(name)(args...); }
  };

  template <
    typename Name0, typename R0, typename ...Args0,
    typename Name1, typename R1, typename ...Args1,
    typename Name2, typename R2, typename ...Args2,
    typename Name3, typename R3, typename ...Args3,
    typename Name4, typename R4, typename ...Args4
  > struct vtable_base<
    std::pair<Name0, R0 (*)(Args0...)>,
    std::pair<Name1, R1 (*)(Args1...)>,
    std::pair<Name2, R2 (*)(Args2...)>,
    std::pair<Name3, R3 (*)(Args3...)>,
    std::pair<Name4, R4 (*)(Args4...)>
  > {
    virtual R0 apply(Name0, Args0...) const = 0;
    virtual R1 apply(Name1, Args1...) const = 0;
    virtual R2 apply(Name2, Args2...) const = 0;
    virtual R3 apply(Name3, Args3...) const = 0;
    virtual R4 apply(Name4, Args4...) const = 0;
  };

  template <typename GetConceptMap
    , typename Name0, typename R0, typename ...Args0
    , typename Name1, typename R1, typename ...Args1
    , typename Name2, typename R2, typename ...Args2
    , typename Name3, typename R3, typename ...Args3
    , typename Name4, typename R4, typename ...Args4
  >
  struct vtable_impl<GetConceptMap
    , std::pair<Name0, R0 (*)(Args0...)>
    , std::pair<Name1, R1 (*)(Args1...)>
    , std::pair<Name2, R2 (*)(Args2...)>
    , std::pair<Name3, R3 (*)(Args3...)>
    , std::pair<Name4, R4 (*)(Args4...)>
  > final : vtable_base<
    std::pair<Name0, R0 (*)(Args0...)>,
    std::pair<Name1, R1 (*)(Args1...)>,
    std::pair<Name2, R2 (*)(Args2...)>,
    std::pair<Name3, R3 (*)(Args3...)>,
    std::pair<Name4, R4 (*)(Args4...)>
  > {
    R0 apply(Name0 name, Args0 ...args) const override final{ return GetConceptMap{}().erased(name)(args...); }
    R1 apply(Name1 name, Args1 ...args) const override final{ return GetConceptMap{}().erased(name)(args...); }
    R2 apply(Name2 name, Args2 ...args) const override final{ return GetConceptMap{}().erased(name)(args...); }
    R3 apply(Name3 name, Args3 ...args) const override final{ return GetConceptMap{}().erased(name)(args...); }
    R4 apply(Name4 name, Args4 ...args) const override final{ return GetConceptMap{}().erased(name)(args...); }
  };

  template <
    typename Name0, typename R0, typename ...Args0,
    typename Name1, typename R1, typename ...Args1,
    typename Name2, typename R2, typename ...Args2,
    typename Name3, typename R3, typename ...Args3,
    typename Name4, typename R4, typename ...Args4,
    typename Name5, typename R5, typename ...Args5
  > struct vtable_base<
    std::pair<Name0, R0 (*)(Args0...)>,
    std::pair<Name1, R1 (*)(Args1...)>,
    std::pair<Name2, R2 (*)(Args2...)>,
    std::pair<Name3, R3 (*)(Args3...)>,
    std::pair<Name4, R4 (*)(Args4...)>,
    std::pair<Name5, R5 (*)(Args5...)>
  > {
    virtual R0 apply(Name0, Args0...) const = 0;
    virtual R1 apply(Name1, Args1...) const = 0;
    virtual R2 apply(Name2, Args2...) const = 0;
    virtual R3 apply(Name3, Args3...) const = 0;
    virtual R4 apply(Name4, Args4...) const = 0;
    virtual R5 apply(Name5, Args5...) const = 0;
  };

  template <typename GetConceptMap
    , typename Name0, typename R0, typename ...Args0
    , typename Name1, typename R1, typename ...Args1
    , typename Name2, typename R2, typename ...Args2
    , typename Name3, typename R3, typename ...Args3
    , typename Name4, typename R4, typename ...Args4
    , typename Name5, typename R5, typename ...Args5
  >
  struct vtable_impl<GetConceptMap
    , std::pair<Name0, R0 (*)(Args0...)>
    , std::pair<Name1, R1 (*)(Args1...)>
    , std::pair<Name2, R2 (*)(Args2...)>
    , std::pair<Name3, R3 (*)(Args3...)>
    , std::pair<Name4, R4 (*)(Args4...)>
    , std::pair<Name5, R5 (*)(Args5...)>
  > final : vtable_base<
    std::pair<Name0, R0 (*)(Args0...)>,
    std::pair<Name1, R1 (*)(Args1...)>,
    std::pair<Name2, R2 (*)(Args2...)>,
    std::pair<Name3, R3 (*)(Args3...)>,
    std::pair<Name4, R4 (*)(Args4...)>,
    std::pair<Name5, R5 (*)(Args5...)>
  > {
    R0 apply(Name0 name, Args0 ...args) const override final{ return GetConceptMap{}().erased(name)(args...); }
    R1 apply(Name1 name, Args1 ...args) const override final{ return GetConceptMap{}().erased(name)(args...); }
    R2 apply(Name2 name, Args2 ...args) const override final{ return GetConceptMap{}().erased(name)(args...); }
    R3 apply(Name3 name, Args3 ...args) const override final{ return GetConceptMap{}().erased(name)(args...); }
    R4 apply(Name4 name, Args4 ...args) const override final{ return GetConceptMap{}().erased(name)(args...); }
    R5 apply(Name5 name, Args5 ...args) const override final{ return GetConceptMap{}().erased(name)(args...); }
  };

  template <
    typename Name0, typename R0, typename ...Args0,
    typename Name1, typename R1, typename ...Args1,
    typename Name2, typename R2, typename ...Args2,
    typename Name3, typename R3, typename ...Args3,
    typename Name4, typename R4, typename ...Args4,
    typename Name5, typename R5, typename ...Args5,
    typename Name6, typename R6, typename ...Args6
  > struct vtable_base<
    std::pair<Name0, R0 (*)(Args0...)>,
    std::pair<Name1, R1 (*)(Args1...)>,
    std::pair<Name2, R2 (*)(Args2...)>,
    std::pair<Name3, R3 (*)(Args3...)>,
    std::pair<Name4, R4 (*)(Args4...)>,
    std::pair<Name5, R5 (*)(Args5...)>,
    std::pair<Name6, R6 (*)(Args6...)>
  > {
    virtual R0 apply(Name0, Args0...) const = 0;
    virtual R1 apply(Name1, Args1...) const = 0;
    virtual R2 apply(Name2, Args2...) const = 0;
    virtual R3 apply(Name3, Args3...) const = 0;
    virtual R4 apply(Name4, Args4...) const = 0;
    virtual R5 apply(Name5, Args5...) const = 0;
    virtual R6 apply(Name6, Args6...) const = 0;
  };

  template <typename GetConceptMap
    , typename Name0, typename R0, typename ...Args0
    , typename Name1, typename R1, typename ...Args1
    , typename Name2, typename R2, typename ...Args2
    , typename Name3, typename R3, typename ...Args3
    , typename Name4, typename R4, typename ...Args4
    , typename Name5, typename R5, typename ...Args5
    , typename Name6, typename R6, typename ...Args6
  >
  struct vtable_impl<GetConceptMap
    , std::pair<Name0, R0 (*)(Args0...)>
    , std::pair<Name1, R1 (*)(Args1...)>
    , std::pair<Name2, R2 (*)(Args2...)>
    , std::pair<Name3, R3 (*)(Args3...)>
    , std::pair<Name4, R4 (*)(Args4...)>
    , std::pair<Name5, R5 (*)(Args5...)>
    , std::pair<Name6, R6 (*)(Args6...)>
  > final : vtable_base<
    std::pair<Name0, R0 (*)(Args0...)>,
    std::pair<Name1, R1 (*)(Args1...)>,
    std::pair<Name2, R2 (*)(Args2...)>,
    std::pair<Name3, R3 (*)(Args3...)>,
    std::pair<Name4, R4 (*)(Args4...)>,
    std::pair<Name5, R5 (*)(Args5...)>,
    std::pair<Name6, R6 (*)(Args6...)>
  > {
    R0 apply(Name0 name, Args0 ...args) const override final{ return GetConceptMap{}().erased(name)(args...); }
    R1 apply(Name1 name, Args1 ...args) const override final{ return GetConceptMap{}().erased(name)(args...); }
    R2 apply(Name2 name, Args2 ...args) const override final{ return GetConceptMap{}().erased(name)(args...); }
    R3 apply(Name3 name, Args3 ...args) const override final{ return GetConceptMap{}().erased(name)(args...); }
    R4 apply(Name4 name, Args4 ...args) const override final{ return GetConceptMap{}().erased(name)(args...); }
    R5 apply(Name5 name, Args5 ...args) const override final{ return GetConceptMap{}().erased(name)(args...); }
    R6 apply(Name6 name, Args6 ...args) const override final{ return GetConceptMap{}().erased(name)(args...); }
  };

  template <
    typename Name0, typename R0, typename ...Args0,
    typename Name1, typename R1, typename ...Args1,
    typename Name2, typename R2, typename ...Args2,
    typename Name3, typename R3, typename ...Args3,
    typename Name4, typename R4, typename ...Args4,
    typename Name5, typename R5, typename ...Args5,
    typename Name6, typename R6, typename ...Args6,
    typename Name7, typename R7, typename ...Args7
  > struct vtable_base<
    std::pair<Name0, R0 (*)(Args0...)>,
    std::pair<Name1, R1 (*)(Args1...)>,
    std::pair<Name2, R2 (*)(Args2...)>,
    std::pair<Name3, R3 (*)(Args3...)>,
    std::pair<Name4, R4 (*)(Args4...)>,
    std::pair<Name5, R5 (*)(Args5...)>,
    std::pair<Name6, R6 (*)(Args6...)>,
    std::pair<Name7, R7 (*)(Args7...)>
  > {
    virtual R0 apply(Name0, Args0...) const = 0;
    virtual R1 apply(Name1, Args1...) const = 0;
    virtual R2 apply(Name2, Args2...) const = 0;
    virtual R3 apply(Name3, Args3...) const = 0;
    virtual R4 apply(Name4, Args4...) const = 0;
    virtual R5 apply(Name5, Args5...) const = 0;
    virtual R6 apply(Name6, Args6...) const = 0;
    virtual R7 apply(Name7, Args7...) const = 0;
  };

  template <typename GetConceptMap
    , typename Name0, typename R0, typename ...Args0
    , typename Name1, typename R1, typename ...Args1
    , typename Name2, typename R2, typename ...Args2
    , typename Name3, typename R3, typename ...Args3
    , typename Name4, typename R4, typename ...Args4
    , typename Name5, typename R5, typename ...Args5
    , typename Name6, typename R6, typename ...Args6
    , typename Name7, typename R7, typename ...Args7
  >
  struct vtable_impl<GetConceptMap
    , std::pair<Name0, R0 (*)(Args0...)>
    , std::pair<Name1, R1 (*)(Args1...)>
    , std::pair<Name2, R2 (*)(Args2...)>
    , std::pair<Name3, R3 (*)(Args3...)>
    , std::pair<Name4, R4 (*)(Args4...)>
    , std::pair<Name5, R5 (*)(Args5...)>
    , std::pair<Name6, R6 (*)(Args6...)>
    , std::pair<Name7, R7 (*)(Args7...)>
  > final : vtable_base<
    std::pair<Name0, R0 (*)(Args0...)>,
    std::pair<Name1, R1 (*)(Args1...)>,
    std::pair<Name2, R2 (*)(Args2...)>,
    std::pair<Name3, R3 (*)(Args3...)>,
    std::pair<Name4, R4 (*)(Args4...)>,
    std::pair<Name5, R5 (*)(Args5...)>,
    std::pair<Name6, R6 (*)(Args6...)>,
    std::pair<Name7, R7 (*)(Args7...)>
  > {
    R0 apply(Name0 name, Args0 ...args) const override final{ return GetConceptMap{}().erased(name)(args...); }
    R1 apply(Name1 name, Args1 ...args) const override final{ return GetConceptMap{}().erased(name)(args...); }
    R2 apply(Name2 name, Args2 ...args) const override final{ return GetConceptMap{}().erased(name)(args...); }
    R3 apply(Name3 name, Args3 ...args) const override final{ return GetConceptMap{}().erased(name)(args...); }
    R4 apply(Name4 name, Args4 ...args) const override final{ return GetConceptMap{}().erased(name)(args...); }
    R5 apply(Name5 name, Args5 ...args) const override final{ return GetConceptMap{}().erased(name)(args...); }
    R6 apply(Name6 name, Args6 ...args) const override final{ return GetConceptMap{}().erased(name)(args...); }
    R7 apply(Name7 name, Args7 ...args) const override final{ return GetConceptMap{}().erased(name)(args...); }
  };

  template <
    typename Name0, typename R0, typename ...Args0,
    typename Name1, typename R1, typename ...Args1,
    typename Name2, typename R2, typename ...Args2,
    typename Name3, typename R3, typename ...Args3,
    typename Name4, typename R4, typename ...Args4,
    typename Name5, typename R5, typename ...Args5,
    typename Name6, typename R6, typename ...Args6,
    typename Name7, typename R7, typename ...Args7,
    typename Name8, typename R8, typename ...Args8
  > struct vtable_base<
    std::pair<Name0, R0 (*)(Args0...)>,
    std::pair<Name1, R1 (*)(Args1...)>,
    std::pair<Name2, R2 (*)(Args2...)>,
    std::pair<Name3, R3 (*)(Args3...)>,
    std::pair<Name4, R4 (*)(Args4...)>,
    std::pair<Name5, R5 (*)(Args5...)>,
    std::pair<Name6, R6 (*)(Args6...)>,
    std::pair<Name7, R7 (*)(Args7...)>,
    std::pair<Name8, R8 (*)(Args8...)>
  > {
    virtual R0 apply(Name0, Args0...) const = 0;
    virtual R1 apply(Name1, Args1...) const = 0;
    virtual R2 apply(Name2, Args2...) const = 0;
    virtual R3 apply(Name3, Args3...) const = 0;
    virtual R4 apply(Name4, Args4...) const = 0;
    virtual R5 apply(Name5, Args5...) const = 0;
    virtual R6 apply(Name6, Args6...) const = 0;
    virtual R7 apply(Name7, Args7...) const = 0;
    virtual R8 apply(Name8, Args8...) const = 0;
  };

  template <typename GetConceptMap
    , typename Name0, typename R0, typename ...Args0
    , typename Name1, typename R1, typename ...Args1
    , typename Name2, typename R2, typename ...Args2
    , typename Name3, typename R3, typename ...Args3
    , typename Name4, typename R4, typename ...Args4
    , typename Name5, typename R5, typename ...Args5
    , typename Name6, typename R6, typename ...Args6
    , typename Name7, typename R7, typename ...Args7
    , typename Name8, typename R8, typename ...Args8
  >
  struct vtable_impl<GetConceptMap
    , std::pair<Name0, R0 (*)(Args0...)>
    , std::pair<Name1, R1 (*)(Args1...)>
    , std::pair<Name2, R2 (*)(Args2...)>
    , std::pair<Name3, R3 (*)(Args3...)>
    , std::pair<Name4, R4 (*)(Args4...)>
    , std::pair<Name5, R5 (*)(Args5...)>
    , std::pair<Name6, R6 (*)(Args6...)>
    , std::pair<Name7, R7 (*)(Args7...)>
    , std::pair<Name8, R8 (*)(Args8...)>
  > final : vtable_base<
    std::pair<Name0, R0 (*)(Args0...)>,
    std::pair<Name1, R1 (*)(Args1...)>,
    std::pair<Name2, R2 (*)(Args2...)>,
    std::pair<Name3, R3 (*)(Args3...)>,
    std::pair<Name4, R4 (*)(Args4...)>,
    std::pair<Name5, R5 (*)(Args5...)>,
    std::pair<Name6, R6 (*)(Args6...)>,
    std::pair<Name7, R7 (*)(Args7...)>,
    std::pair<Name8, R8 (*)(Args8...)>
  > {
    R0 apply(Name0 name, Args0 ...args) const override final{ return GetConceptMap{}().erased(name)(args...); }
    R1 apply(Name1 name, Args1 ...args) const override final{ return GetConceptMap{}().erased(name)(args...); }
    R2 apply(Name2 name, Args2 ...args) const override final{ return GetConceptMap{}().erased(name)(args...); }
    R3 apply(Name3 name, Args3 ...args) const override final{ return GetConceptMap{}().erased(name)(args...); }
    R4 apply(Name4 name, Args4 ...args) const override final{ return GetConceptMap{}().erased(name)(args...); }
    R5 apply(Name5 name, Args5 ...args) const override final{ return GetConceptMap{}().erased(name)(args...); }
    R6 apply(Name6 name, Args6 ...args) const override final{ return GetConceptMap{}().erased(name)(args...); }
    R7 apply(Name7 name, Args7 ...args) const override final{ return GetConceptMap{}().erased(name)(args...); }
    R8 apply(Name8 name, Args8 ...args) const override final{ return GetConceptMap{}().erased(name)(args...); }
  };
  ////////////////////////////////////////////////////////////////////////////
  // END GENERATED CODE
  ////////////////////////////////////////////////////////////////////////////
} // end namespace detail

} // end namespace experimental
} // end namespace te

#endif // TE_EXPERIMENTAL_VTABLE_HPP
