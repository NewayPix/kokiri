workspace "kokiri"
    configurations {"debug", "release"}

    group "core"
        include "kokiri"

    group "dependencies"
        include "kokiri/vendor/glad"

    group "tests"
        include "kokiri-test/"