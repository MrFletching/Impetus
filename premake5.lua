workspace "Impetus"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Impetus"
	location "Impetus"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"IMPETUS_PLATFORM_WINDOWS",
			"IMPETUS_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "IMPETUS_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "IMPETUS_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "IMPETUS_DIST"
		optimize "On"


project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Impetus/vendor/spdlog/include",
		"Impetus/src"
	}

	links
	{
		"Impetus"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"IMPETUS_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "IMPETUS_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "IMPETUS_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "IMPETUS_DIST"
		optimize "On"