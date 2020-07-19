# XmlConfigReader
Consists of xml handling
Will be added as part of bigger projects
Based on libxml2, used for reading and wirting into xml

Build instrutions:
- Create directory bin in the source folder
- cd bin
- cmake ..
- make
- If any error messages occur check path of include_directories and link_directories, works only on linux

Imporvements:
- statically link libxml2, as of now causing issues
- library build target,working but is commented out
- xpath support and traversal recipies, in near future during integration with other projects
