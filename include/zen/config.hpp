#ifndef ZEN_CONFIG_HPP
#define ZEN_CONFIG_HPP

#include <stdio.h>
#include <cstdlib>

#define ZEN_CAT(arg) #arg
#define ZEN_CAT2(arg) ZEN_CAT(arg)

#define ZEN_ASSERT(test)                                                                      \
  if (!(test)) {                                                                                \
    ZEN_PANIC("The invariant " #test " failed to hold. See the stack trace for more details."); \
  }

#define ZEN_PANIC(message, ...)                                            \
  fprintf(stderr, __FILE__ ":" ZEN_CAT2(__LINE__) ": " message "\n" __VA_OPT__(,) __VA_ARGS__); \
  std::abort();

#define ZEN_UNREACHABLE \
  ZEN_PANIC("Code that should have been unreachable was executed. This is a bug.");

#define ZEN_AUTO_SIZE (-1)

#if __cplusplus >= 201703L
#define ZEN_NODISCARD [[nodiscard]]
#else
#define ZEN_NODISCARD
#endif

#define ZEN_NOEXCEPT noexcept

#endif // of #ifndef ZEN_CONFIG_HPP

