project "glad"
    kind "StaticLib"
    language "C"
    staticruntime "off"

    targetdir ("build/%{prj.name}")
    objdir ("build/%{prj.name}")

    files
    {
        "include/glad/glad.h",
        "include/KHR/khrplatform.h",

        "src/glad.c"
    }

    includedirs
    {
        "include"
    }

    filter "configurations:debug"
        defines { "DEBUG" }
        symbols "on"

    filter "configurations:release"
        optimize "on"