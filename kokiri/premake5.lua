project "kokiri"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"
    staticruntime "off"

	targetdir ("%{wks.location}/build/%{prj.name}")
	objdir ("%{wks.location}/build/%{prj.name}")

    pchheader "kkr.hpp"
    pchsource "src/kkr.cpp"

    files {
        "src/**.hpp",
        "src/**.cpp",

        "vendor/glm/glm/**.hpp",
        "vendor/glm/glm/**.inl"
    }

    includedirs {
        "src",

        "%{IncludeDir.box2d}",
        "%{IncludeDir.glm}",
        "%{IncludeDir.glad}",
    }

    links {
        "glad",
        "box2d",
        "sdl2"
    }

    -- build options

    filter "configurations:debug"
      defines { "DEBUG" }
      symbols "On"

   filter "configurations:release"
      optimize "On"