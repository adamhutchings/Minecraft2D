# Make the bin folder if needed
mkdir -p bin

# SFML path
sfml_path=/usr/local/Cellar/sfml/2.5.1

# Compile
g++ -g $(find src -type f -iregex ".*\.cpp") -std=c++11 \
-I$sfml_path/include -L$sfml_path/lib -lsfml-graphics -lsfml-window -lsfml-system -o bin/mc2d
