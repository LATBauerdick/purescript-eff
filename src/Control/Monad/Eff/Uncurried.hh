///////////////////////////////////////////////////////////////////////////////
//
// Module      :  Uncurried.hh
// Copyright   :  (c) Andy Arvanitis 2015, 2017
// License     :  MIT
//
// Maintainer  :  Andy Arvanitis <andy.arvanitis@gmail.com>
// Stability   :  experimental
// Portability :
//
// Function FFI functions
//
///////////////////////////////////////////////////////////////////////////////
//
#ifndef Control_Monad_Eff_Uncurried_FFI_HH
#define Control_Monad_Eff_Uncurried_FFI_HH

#include "PureScript/PureScript.hh"

namespace Control_Monad_Eff_Uncurried {
  using namespace PureScript;

  //---------------------------------------------------------------------------

  inline auto mkEffFn1(const any& fn) -> any {
    return fn;
  }

  inline auto mkEffFn2(const any& fn) -> any {
    return fn;
  }

  inline auto mkEffFn3(const any& fn) -> any {
    return fn;
  }

  inline auto mkEffFn4(const any& fn) -> any {
    return fn;
  }

  inline auto mkEffFn5(const any& fn) -> any {
    return fn;
  }

  inline auto mkEffFn6(const any& fn) -> any {
    return fn;
  }

  inline auto mkEffFn7(const any& fn) -> any {
    return fn;
  }

  inline auto mkEffFn8(const any& fn) -> any {
    return fn;
  }

  inline auto mkEffFn9(const any& fn) -> any {
    return fn;
  }

  inline auto mkEffFn10(const any& fn) -> any {
    return fn;
  }

  //---------------------------------------------------------------------------

  inline auto runEffFn1(const any& fn, const any& a) -> any {
    return fn(a);
  }

  template <typename F, typename ... Args>
  inline auto runEffFn2(F&& fn, Args&&...args) ->
      typename std::enable_if<!std::is_convertible<F,any>::value,
                              typename std::result_of<F(Args...)>::type>::type {
    return fn(std::forward<Args>(args)...);
  }

  template <typename F>
  inline auto runEffFn2(const F& fn, const any& a, const any& b) ->
      typename std::enable_if<std::is_convertible<F,any>::value, any>::type {
    return fn(a)(b);
  }

  template <typename F, typename ... Args>
  inline auto runEffFn3(F&& fn, Args&&...args) ->
      typename std::enable_if<!std::is_convertible<F,any>::value,
                              typename std::result_of<F(Args...)>::type>::type {
    return fn(std::forward<Args>(args)...);
  }

  template <typename F>
  inline auto runEffFn3(const F& fn, const any& a, const any& b, const any& c) ->
      typename std::enable_if<std::is_convertible<F,any>::value, any>::type {
    return fn(a)(b)(c);
  }

  template <typename F, typename ... Args>
  inline auto runEffFn4(F&& fn, Args&&...args) ->
      typename std::enable_if<!std::is_convertible<F,any>::value,
                              typename std::result_of<F(Args...)>::type>::type {
    return fn(std::forward<Args>(args)...);
  }

  template <typename F>
  inline auto runEffFn4(const F& fn, const any& a, const any& b, const any& c, const any& d) ->
      typename std::enable_if<std::is_convertible<F,any>::value, any>::type {
    return fn(a)(b)(c)(d);
  }

  template <typename F, typename ... Args>
  inline auto runEffFn5(F&& fn, Args&&...args) ->
      typename std::enable_if<!std::is_convertible<F,any>::value,
                              typename std::result_of<F(Args...)>::type>::type {
    return fn(std::forward<Args>(args)...);
  }

  template <typename F>
  inline auto runEffFn5(const F& fn, const any& a, const any& b, const any& c, const any& d, const any& e) ->
      typename std::enable_if<std::is_convertible<F,any>::value, any>::type {
    return fn(a)(b)(c)(d)(e);
  }

  template <typename F, typename ... Args>
  inline auto runEffFn6(F&& fn, Args&&...args) ->
      typename std::enable_if<!std::is_convertible<F,any>::value,
                              typename std::result_of<F(Args...)>::type>::type {
    return fn(std::forward<Args>(args)...);
  }

  template <typename F>
  inline auto runEffFn6(const F& fn, const any& a, const any& b, const any& c, const any& d, const any& e, const any& f) ->
      typename std::enable_if<std::is_convertible<F,any>::value, any>::type {
    return fn(a)(b)(c)(d)(e)(f);
  }

  template <typename F, typename ... Args>
  inline auto runEffFn7(F&& fn, Args&&...args) ->
      typename std::enable_if<!std::is_convertible<F,any>::value,
                              typename std::result_of<F(Args...)>::type>::type {
    return fn(std::forward<Args>(args)...);
  }

  template <typename F>
  inline auto runEffFn7(const F& fn, const any& a, const any& b, const any& c, const any& d, const any& e,
                                     const any& f, const any& g) ->
      typename std::enable_if<std::is_convertible<F,any>::value, any>::type {
    return fn(a)(b)(c)(d)(e)(f)(g);
  }

  template <typename F, typename ... Args>
  inline auto runEffFn8(F&& fn, Args&&...args) ->
      typename std::enable_if<!std::is_convertible<F,any>::value,
                              typename std::result_of<F(Args...)>::type>::type {
    return fn(std::forward<Args>(args)...);
  }

  template <typename F>
  inline auto runEffFn8(const F& fn, const any& a, const any& b, const any& c, const any& d, const any& e,
                                  const any& f, const any& g, const any& h) ->
      typename std::enable_if<std::is_convertible<F,any>::value, any>::type {
    return fn(a)(b)(c)(d)(e)(f)(g)(h);
  }

  template <typename F, typename ... Args>
  inline auto runEffFn9(F&& fn, Args&&...args) ->
      typename std::enable_if<!std::is_convertible<F,any>::value,
                              typename std::result_of<F(Args...)>::type>::type {
    return fn(std::forward<Args>(args)...);
  }

  template <typename F>
  inline auto runEffFn9(const F& fn, const any& a, const any& b, const any& c, const any& d, const any& e,
                                  const any& f, const any& g, const any& h, const any& i) ->
      typename std::enable_if<std::is_convertible<F,any>::value, any>::type {
    return fn(a)(b)(c)(d)(e)(f)(g)(h)(i);
  }

  template <typename F, typename ... Args>
  inline auto runEffFn10(F&& fn, Args&&...args) ->
      typename std::enable_if<!std::is_convertible<F,any>::value,
                              typename std::result_of<F(Args...)>::type>::type {
    return fn(std::forward<Args>(args)...);
  }

  template <typename F>
  inline auto runEffFn10(const F& fn, const any& a, const any& b, const any& c, const any& d, const any& e,
                                   const any& f, const any& g, const any& h, const any& i, const any& j) ->
      typename std::enable_if<std::is_convertible<F,any>::value, any>::type {
    return fn(a)(b)(c)(d)(e)(f)(g)(h)(i)(j);
  }

} // namespace Control_Monad_Eff_Uncurried

#endif // Control_Monad_Eff_Uncurried_FFI_HH
