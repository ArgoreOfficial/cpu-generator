workspace "cpu-generator"
	configurations { "Debug", "Release" }
	platforms { "x64" }
	

project "cpu-generator"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++20"
	targetdir "bin"
	objdir "bin/obj/"
	location "src"

	debugdir "./"

	files { 
		"src/**.h", 
		"src/**.cpp" 
	}
