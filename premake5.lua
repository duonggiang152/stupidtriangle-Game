workspace "Hazel"
	architecture "x64"
	startproject "Sandbox"
	configurations
	{
		"Debug",
		"Release",
	}
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
-- include directories relative to root folder (solution directory)
IncludeDir = {};
IncludeDir["GLFW"]        = "Hazel/vendor/GLFW/include";
IncludeDir["Glad"]        = "Hazel/vendor/Glad/include";
IncludeDir["imgui"]       = "Hazel/vendor/imgui";
IncludeDir["glm"]         = "Hazel/vendor/glm";
IncludeDir["stb_image"]   = "Hazel/vendor/stb_image";
IncludeDir["Hazel"]   = "Hazel";
include "Hazel/vendor/GLFW"
include "Hazel/vendor/Glad"
include "Hazel/vendor/imgui"
include "Hazel/vendor/glm"
project "Hazel"
	location "Hazel"
	kind "staticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "On"
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "hzpch.h"
	pchsource "Hazel/src/hzpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/stb_image/**.h",
		"%{prj.name}/vendor/stb_image/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl"
		
	}
	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.imgui}",
		"%{IncludeDir.glm}",
		"%{IncludeDir.stb_image}",
	}

	links
	{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib",
		
	}
	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		
		defines
		{
			"HZ_PLATFORM_WINDOWS",
			"HZ_BUILT_DLL",
			"GLFW_INCLUDE_NONE",

		}
		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/SandBox")
		}
		filter "configurations:Debug"
			defines "HZ_DEBUG"
			buildoptions "/MTd"
			symbols "On"
		filter "configurations:Release"
			defines "HZ_RELESE"
			buildoptions "/MD"
			optimize "On"
project "Sandbox"
	location "SandBox"
	kind "ConsoleApp"
	language "C++"
	staticruntime "On"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		
	}
	includedirs
	{
		"Hazel/vendor/spdlog/include",
		"%{IncludeDir.Hazel}/src",
		"%{IncludeDir.Hazel}/src/Hazel.h",
		"%{IncludeDir.glm}",
		"%{IncludeDir.imgui}",
	}
	links
	{
		"Hazel"
	}
	filter "system:windows"
		cppdialect "C++14"
		staticruntime "On"
		cppdialect "C++17"
		systemversion "latest"
		
		defines
		{
			"HZ_PLATFORM_WINDOWS"
		}
		filter "configurations:Debug"
			defines "HZ_DEBUG"
			buildoptions "/MTd"
			symbols "On"
		filter "configurations:Release"
			defines "HZ_RELESE"
			buildoptions "/MD"
			optimize "On"
