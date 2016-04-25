///////////////////////////////////////////////////////////////////////////////
//
// Module      :  Eff.hh
// Copyright   :  (c) Andy Arvanitis 2015
// License     :  MIT
//
// Maintainer  :  Andy Arvanitis <andy.arvanitis@gmail.com>
// Stability   :  experimental
// Portability :
//
// Eff FFI functions
//
///////////////////////////////////////////////////////////////////////////////
//
#ifndef EffFFI_HH
#define EffFFI_HH

#include "PureScript/PureScript.hh"

namespace Control_Monad_Eff {
  using namespace PureScript;

  inline auto returnE(const any& a) -> any {
    return [=]() -> any {
      return a;
    };
  }

  inline auto bindE(const any& a, const any& f) -> any {
    return [=]() -> any {
      return f(a())();
    };
  }

  inline auto runPure(const any& f) -> any {
    return f();
  }

  inline auto untilE(const any& f) -> any {
    return [=]() -> any {
      while (not cast<bool>(f()));
      return Prelude::unit;
    };
  }

  inline auto whileE(const any& f, const any& a) -> any {
    return [=]() -> any {
      while (cast<bool>(f())) {
        a();
      }
      return Prelude::unit;
    };
  }

  inline auto forE(const any& lo, const any& hi, const any& f) -> any {
    return [=]() -> any {
      for (double d = lo; d < hi; d++) {
        f(d)();
      }
      return Prelude::unit;
    };
  }

  inline auto foreachE(const any::array& as, const any& f) -> any {
    return [=]() -> any {
      for (auto it = as.cbegin(), end = as.cend(); it != end; ++it) {
        f(*it)();
      }
      return Prelude::unit;
    };
  };
}


#endif // EffFFI_HH
