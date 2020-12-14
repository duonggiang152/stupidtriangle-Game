#pragma once

#ifdef HZ_PLATFORM_WINDOWS
#ifdef HZ_DYNAMIC_LINK
	#ifdef HZ_BUILT_DLL
		#define HAZEL_API __declspec(dllexport)
	#else	
		#define HAZEL_API __declspec(dllimport)
	#endif
#else 
	#define HAZEL_API
#endif
#else
	#error Hazel only support Window!
#endif
#ifdef HZ_ENABLE_ASSERTS
	#define HZ_ASSERT(x, ...) {if(!(x))} { HZ_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak();}
	#define HZ_CORE_ASSERT(x, ...) {if(!(x))} { HZ_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak();}
#else 
#define HZ_ASSERT(x, ...);
#define HZ_CORE_ASSERT(x, ...);
#endif

#define BIT(x) (0 << x)

#define HZ_BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)
#include <memory>
namespace Hazel {
	template<typename T>
	using Scope = std::unique_ptr<T>;

	template<typename T>
	using Ref = std::shared_ptr<T>;
}

