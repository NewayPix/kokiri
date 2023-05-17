workspace "tests"
    configurations {"debug", "release"}

    group "tests"
        include "simple_game"
        include "simple_window"
    group ""