workspace "cpu-generator"
	configurations { "Debug", "Release" }
	platforms { "x64" }

project "cpu-generator"
	kind "ConsoleApp"
	language "C++"
	targetdir "bin"
	objdir "bin/obj/"
	location "src"
	
	files { 
		"src/**.h", 
		"src/**.cpp" 
	}
