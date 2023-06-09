# Set Java Includes and Email Object Library Path
$JavaIncludeDirectory1 = "C:\Program Files\Java\jdk-20\include"
$JavaIncludeDirectory2 = "C:\Program Files\Java\jdk-20\include\win32"
$EmailLibraryPath = $PSScriptRoot

# Run cl command
& 'cl' -I"$EmailLibraryPath" -I"$JavaIncludeDirectory1" -I"$JavaIncludeDirectory2" -Fe'mdEmailJavaWrapper.dll' 'mdEmailJavaWrapper.cpp' -link -DLL -LIBPATH:"$EmailLibraryPath" -DEFAULTLIB:'mdEmail.lib'

# Remove files
Remove-Item 'mdEmailJavaWrapper.exp' -ErrorAction SilentlyContinue
Remove-Item 'mdEmailJavaWrapper.obj' -ErrorAction SilentlyContinue
Remove-Item 'mdEmailJavaWrapper.lib' -ErrorAction SilentlyContinue

