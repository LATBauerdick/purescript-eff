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

  // foreign import pureE :: forall e a. a -> Eff e a
  //
  inline auto pureE(const any& a) -> any {
    return [=]() -> any {
      return a;
    };
  }

  // foreign import bindE :: forall e a b. Eff e a -> (a -> Eff e b) -> Eff e b
  //
  inline auto bindE(const any& a, const any& f) -> any {
    return [=]() -> any {
      return f(a())();
    };
  }

  // foreign import runPure :: forall a. Pure a -> a
  //
  inline auto runPure(const any& f) -> any {
    return f();
  }

  // foreign import untilE :: forall e. Eff e Boolean -> Eff e Unit
  //
  inline auto untilE(const any& f) -> any {
    return [=]() -> any {
      while (not cast<bool>(f()));
      return Data_Unit::unit;
    };
  }

  // foreign import whileE :: forall e a. Eff e Boolean -> Eff e a -> Eff e Unit
  //
  inline auto whileE(const any& f, const any& a) -> any {
    return [=]() -> any {
      while (cast<bool>(f())) {
        a();
      }
      return Data_Unit::unit;
    };
  }

  // foreign import forE :: forall e. Int -> Int -> (Int -> Eff e Unit) -> Eff e Unit
  //
  inline auto forE(const any& lo, const any& hi, const any& f) -> any {
    return [=]() -> any {
      for (double d = lo; d < hi; d++) {
        f(d)();
      }
      return Data_Unit::unit;
    };
  }

  // foreign import foreachE :: forall e a. Array a -> (a -> Eff e Unit) -> Eff e Unit
  //
  inline auto foreachE(const any::array& as, const any& f) -> any {
    return [=]() -> any {
      for (auto it = as.cbegin(), end = as.cend(); it != end; ++it) {
        f(*it)();
      }
      return Data_Unit::unit;
    };
  };
}


#endif // EffFFI_HH
