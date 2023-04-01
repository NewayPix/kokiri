project "kokiri-test"
    kind "WindowedApp"
    language "C++"
    cppdialect "C++17"
    staticruntime "off"

    targetdir ("build/%{prj.name}")
    objdir ("build/%{prj.name}")

    files {
        "**.cpp",
        "**.hpp"
    }

    includedirs {
        "%{wks.location}/kokiri/src",
        "%{wks.location}/kokiri/vendor",

        "%{IncludeDir.box2d}",
        "%{IncludeDir.glm}",
        "%{IncludeDir.glad}"
    }

    links {
        "kokiri",
        "glad",
        "SDL2"
    }