
-- Kokiri dependencies

IncludeDir = {}

IncludeDir["box2d"] = "%{wks.location}/kokiri/vendor/box2d/include"
IncludeDir["glad"] = "%{wks.location}/kokiri/vendor/glad/include"
IncludeDir["fmt"] = "%{wks.location}/kokiri/vendor/fmt/include"
IncludeDir["glm"] = "%{wks.location}/kokiri/vendor/glm"

-- The kokiri include folder for the tests are not quite clear from their
-- perspective so I need to do the following.

IncludeDir["kokiri"] = "%{wks.location}/kokiri"

--

LibraryDir = {}

LibraryDir["kokiri"] = "%{wks.location}/build/kokiri/"
LibraryDir["glad"] = "%{wks.location}/kokiri/vendor/glad/build/glad/"
LibraryDir["box2d"] = "%{wks.location}/kokiri/vendor/box2d/build/"