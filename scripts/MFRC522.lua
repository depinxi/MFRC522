-- device specific rules

MFRC522 = {
	PATH = path.getabsolute (path.getdirectory(_SCRIPT) .. "/..")
}

MFRC522.devices = {
	arduino = {
		defines = { "MFRC522_DEVICE=1" },
		files = {
			MFRC522.PATH .. "/src//MFRC522Extended.cpp",
			MFRC522.PATH .. "/src//MFRC522Extended.h",
			MFRC522.PATH .. "/src//MFRC522Hack.cpp",
			MFRC522.PATH .. "/src//MFRC522Hack.h",
			MFRC522.PATH .. "/src//deprecated.h",
			MFRC522.PATH .. "/src//require_cpp11.h"
		},
		links = {}
	},
	raspberrypi = {
		defines = { "MFRC522_DEVICE=2" },
		links = { "bcm2835" }
	},
	nanopi = {
		defines = { "MFRC522_DEVICE=4" },
		links = { "wiringPi" }
	}

}

setmetatable (MFRC522,{
	__call = function (o, device, what)
		if type(what) ~= "string" then what = "use" end
		local keys = { "defines", "buildoptions", "links", "linkoptions" }
		if what == "all"
		then
			table.insert (keys, "files")
		end


		if type(o.devices[device]) == "table"
		then
			for _, key in ipairs (keys)
			do
				local value = o.devices[device][key]
				if (value ~= nil) and (type (_G[key]) == "function")
				then
					_G[key] (value)
				end 
			end
		end
	end
})

project "MFRC522"
	kind "StaticLib"
	language "C++"
	files {
		MFRC522.PATH .. "/src//MFRC522Base.h",
		MFRC522.PATH .. "/src//MFRC522.h",
		MFRC522.PATH .. "/src//MFRC522.cpp",
		MFRC522.PATH .. "/src//MFRC522Debug.cpp",
		MFRC522.PATH .. "/src//MFRC522Debug.h"	
	}

	filter { "toolset:gcc or clang" }
		linkoptions { "-pthread" }
	filter { "toolset:not(gcc or clang)" }
		links { "pthread" }
	filter {}

	MFRC522(_OPTIONS["device"], "all")
	
