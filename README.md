An open-source game *similar* to Minecraft, but in two dimensions.

Dependencies
------------
SFML 2.5.1 (`brew install sfml` or similar)

File path for SFML library is currently set to `/usr/local/Cellar/sfml/2.5.1`.
If different on your machine, change the `SFML_PATH` variable in `Makefile`.

GNU `make` version 3.81
`g++` supporting C++17

Setup
-----
`./scripts/setup.sh`

Compile
-------
`make`

Run
---
`./scripts/run.sh`

Controls
--------
d - right <br/>
a - left <br/>
w - direction player faces <br/>
s - direction behind player <br/>
space - jump <br/>
left click - break block <br/>
escape - go to escape menu

Notes
-----
There are several known bugs, like that block breaking sometimes doesn't work
or that occasionally on startup nothing appears when you make a new world. This
isn't nearly perfect yet. Please report bugs using an issue. Thanks!

Also, please excuse extra `#include`s in implementation files. Stuff fails
to compile when I omit them, for some reason.
