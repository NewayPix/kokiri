project "kokiri-game"
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
        "%{IncludeDir.kokiri}/src",
        "%{IncludeDir.kokiri}/vendor",

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
        "SDL2",
        "SDL2_mixer",
        "SDL2_image",
        "ogg",
        "vorbis"
    }

    -- build options

    filter "configurations:debug"
        buildoptions { "-Wextra", "-Wall" }
        defines { "DEBUG" }
        symbols "On"

    filter "configurations:release"
        optimize "On"