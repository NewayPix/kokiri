workspace "kokiri"
    configurations {"debug", "release"}

    group "core"
        include "kokiri"
    group ""

    group "dependencies"
        include "kokiri/vendor/glad"
    group ""

    group "tests"
        include "kokiri-test/"
    group ""