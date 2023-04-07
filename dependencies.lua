
-- Kokiri dependencies

IncludeDir = {}

IncludeDir["box2d"] = "%{wks.location}/kokiri/vendor/box2d/include"
IncludeDir["glad"] = "%{wks.location}/kokiri/vendor/glad/include"
IncludeDir["glm"] = "%{wks.location}/kokiri/vendor/glm"

LibraryDir = {}

LibraryDir["kokiri"] = "%{wks.location}/build/kokiri/"
LibraryDir["glad"] = "%{wks.location}/kokiri/vendor/glad/build/glad/"