include "dependencies.lua"

workspace "kokiri"
    configurations {"debug", "release"}

    group "core"
        include "kokiri"
    group ""

    group "dependencies"
        include "kokiri/vendor/glad"
        include "kokiri/vendor/box2d"
    group ""

    group "tests"
        include "kokiri-test/"
    group ""