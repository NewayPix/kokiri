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
        "%{wks.location}/src",
        "%{wks.location}/vendor"
    }

    links {
        "kokiri"
    }