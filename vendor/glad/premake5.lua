project "glad"
    kind "StaticLib"
    language "C"
    staticruntime "off"

    targetdir ("build/%{prj.name}")
    objdir ("build/%{prj.name}")

    files
    {
        "glad.h",
        "glad.c"
        "KHR/khrplatform.h",
    }

    includedirs
    {
        "."
    }

    filter "configurations:debug"
        defines { "DEBUG" }
        symbols "on"

    filter "configurations:release"
        optimize "on"