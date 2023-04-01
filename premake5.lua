workspace "kokiri"
    configurations {"debug", "release"}

project "kokiri"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"
    staticruntime "off"

	targetdir ("build/%{prj.name}")
	objdir ("build/%{prj.name}")

    pchheader "kkr.hpp"
    pchsource "src/kkr.cpp"

    files {
        "src/**.hpp",
        "src/**.cpp",

        "vendor/glm/**.hpp",
        "vendor/glm/**.inl",

        "vendor/glad/**.h"
    }

    includedirs {
        "src",

        "%{IncludeDir.glad}",
        "%{IncludeDir.glm}"
    }

    links {
        "glad",
        "sdl2"
    }

    -- build options

    filter "configurations:debug"
      defines { "DEBUG" }
      symbols "On"

   filter "configurations:release"
      optimize "On"