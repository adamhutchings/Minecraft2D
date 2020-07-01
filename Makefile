OBJECTS = ./bin/objects/entity/player.o ./bin/objects/entity/entity.o ./bin/objects/entity/item.o \
./bin/objects/render/m_window.o ./bin/objects/render/renderable.o ./bin/objects/world/block.o \
./bin/objects/world/world.o ./bin/objects/item/item_stack.o ./bin/objects/item/inventory.o \
./bin/objects/gui/m_button.o ./bin/objects/main.o

SFML_PATH = /usr/local/Cellar/sfml/2.5.1

SFML_ARGS = -I$(SFML_PATH)/include -L$(SFML_PATH)/lib -lsfml-system -lsfml-graphics -lsfml-window

GCC = g++ -std=c++17

./bin/mc2d : $(OBJECTS)
	$(GCC) $(OBJECTS) $(SFML_ARGS) -o ./bin/mc2d

./bin/objects/entity/player.o : ./src/entity/player.cpp ./src/entity/player.h ./src/world/world.h \
./src/entity/entity.h ./src/render/m_window.h ./src/main.h ./src/item/inventory.h
	$(GCC) -c ./src/entity/player.cpp -o ./bin/objects/entity/player.o

./bin/objects/entity/entity.o : ./src/entity/entity.cpp ./src/entity/entity.h \
./src/render/renderable.h ./src/world/world.h ./src/main.h ./src/render/m_window.h
	$(GCC) -c ./src/entity/entity.cpp -o ./bin/objects/entity/entity.o

./bin/objects/entity/item.o : ./src/entity/item.cpp ./src/entity/item.h ./src/entity/entity.h ./src/item/item_stack.h
	$(GCC) -c ./src/entity/item.cpp -o ./bin/objects/entity/item.o

./bin/objects/render/m_window.o : ./src/render/m_window.cpp ./src/render/m_window.h ./src/world/block.h \
./src/render/renderable.h ./src/entity/entity.h ./src/main.h ./src/entity/player.h
	$(GCC) -c ./src/render/m_window.cpp -o ./bin/objects/render/m_window.o

./bin/objects/render/renderable.o : ./src/render/renderable.cpp ./src/render/renderable.h ./src/render/m_window.h
	$(GCC) -c ./src/render/renderable.cpp -o ./bin/objects/render/renderable.o

./bin/objects/world/block.o : ./src/world/block.cpp ./src/world/block.h ./src/render/m_window.h ./src/render/renderable.h \
./src/item/item_stack.h
	$(GCC) -c ./src/world/block.cpp -o ./bin/objects/world/block.o

./bin/objects/world/world.o : ./src/world/world.cpp ./src/render/m_window.h ./src/world/block.h ./src/render/renderable.h
	$(GCC) -c ./src/world/world.cpp -o ./bin/objects/world/world.o

./bin/objects/item/item_stack.o : ./src/item/item_stack.cpp ./src/item/item_stack.h \
./src/render/renderable.h ./src/render/m_window.h ./src/world/block.h
	$(GCC) -c ./src/item/item_stack.cpp -o ./bin/objects/item/item_stack.o

./bin/objects/item/inventory.o : ./src/item/inventory.cpp ./src/item/inventory.h ./src/item/item_stack.h \
./src/render/renderable.h ./src/entity/player.h
	$(GCC) -c ./src/item/inventory.cpp -o ./bin/objects/item/inventory.o

./bin/objects/gui/m_button.o : ./src/gui/m_button.cpp ./src/gui/m_button.h ./src/render/renderable.h ./src/render/m_window.h
	$(GCC) -c ./src/gui/m_button.cpp -o ./bin/objects/gui/m_button.o

./bin/objects/main.o : ./src/main.cpp ./src/main.h ./src/world/block.h ./src/render/m_window.h ./src/world/world.h \
./src/entity/player.h ./src/gui/m_button.h
	$(GCC) -c ./src/main.cpp -o ./bin/objects/main.o
