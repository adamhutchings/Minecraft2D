An open-source game *similar* to Minecraft, but in two dimensions.

Dependencies
------------
SFML 2.5.1 (`brew install sfml` or similar)

File path for SFML library is currently set to `/usr/local/Cellar/sfml/2.5.1`.
If different on your machine, change the `SFML_PATH` variable in `Makefile`.

GNU `make` version 3.81

Setup
-----
`sh scripts/setup.sh`

Compile
-------
`make`

Run
---
`./scripts/run.sh`

Controls
--------
d - right
a - left
space - jump
