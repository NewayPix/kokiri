project "kokiri-window"
    kind "WindowedApp"
    language "C++"
    cppdialect "C++17"
    staticruntime "off"

    targetdir ("build/%{prj.name}")
    objdir ("build/%{prj.name}")

    files {
        "**.cpp",
        "**.hpp",
    }

    includedirs {
        "%{wks.location}/kokiri/src",
        "%{wks.location}/kokiri/vendor",

        "%{IncludeDir.box2d}",
        "%{IncludeDir.glm}",
        "%{IncludeDir.glad}"
    }

    libdirs {
        "%{LibraryDir.kokiri}",
        "%{LibraryDir.glad}"
    }

    links {
        "kokiri:static",
        "glad:static",
        "SDL2"
    }

    -- build options

    filter "configurations:debug"
        buildoptions { "-Wextra", "-Wall" }
        defines { "DEBUG" }
        symbols "On"

    filter "configurations:release"
        optimize "On"