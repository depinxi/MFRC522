newoption {
	trigger = "device",
	description = "Target device type",
	value = "NAME",
	allowed = { 
		{ "arduino",  "Arduino" },
		{ "raspberrypi", "Raspberry PI" },
		{ "nanopi", "Nano Pi" }
	},
	default = "arduino"
}
	
workspace "MFRC522"
	configurations { "Release", "Debug" }
	location "../build"	
	include "MFRC522.lua"
		
	-- Tests
	local testPath = "../examples/" .. _OPTIONS["device"] 
	for _, file in ipairs (os.matchfiles (testPath .. "/*.cpp"))
	do
		local name = path.getbasename (file)
		project (name)
			kind "ConsoleApp"
			language "C++"
			files (file)
			includedirs { "../src" }
			links "MFRC522"
			MFRC522(_OPTIONS["device"])
			filter { "toolset:gcc or clang" }
				linkoptions { "-pthread" }
			filter { "toolset:not(gcc or clang)" }
				links { "pthread" }
			filter ()
	end
	
